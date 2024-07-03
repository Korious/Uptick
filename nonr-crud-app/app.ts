import express, { Application } from 'express';
import bodyParser from 'body-parser';
import { getUsers, createUser } from './controllers/user.controller';
import db from './db';

const app: Application = express();
const PORT = process.env.PORT || 3000;

app.use(bodyParser.json());

// Routes
app.get('/users', getUsers);
app.post('/users', createUser);

// Start server
app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});
