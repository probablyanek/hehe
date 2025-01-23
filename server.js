const express = require('express');
const fs = require('fs').promises;
const path = require('path');
const app = express();
const port = 8081;

app.use(express.static(__dirname));

// New endpoint to get clipboard files
app.get('/get-clipboard-files', async (req, res) => {
    try {
        const dirPath = path.join(__dirname, 'clipboard');
        const files = (await fs.readdir(dirPath)).sort();
        
        const fileContents = await Promise.all(files.map(async (fileName) => {
            const filePath = path.join(dirPath, fileName);
            const stats = await fs.stat(filePath);
            
            if (stats.isFile()) {
                const content = await fs.readFile(filePath, 'utf8');
                return { name: fileName, content };
            }
            return null;
        }));

        // Filter out nulls (directories) and return only files
        res.json(fileContents.filter(file => file !== null));
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
});

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html'));
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
    console.log(`Put files in the 'clipboard' directory to be copied`);
});