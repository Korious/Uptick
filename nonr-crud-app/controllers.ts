import { Request, Response } from 'express';
import User from '../models/user.model';

export const getUsers = async (req: Request, res: Response): Promise<void> => {
    try {
        const users = await User.find();
        res.status(200).json(users);
    } catch (error) {
        res.status(500).send(error.message);
    }
};

export const createUser = async (req: Request, res: Response): Promise<void> => {
    try {
        const { name, email, age } = req.body;
        const newUser = new User({ name, email, age });
        await newUser.save();
        res.status(201).json(newUser);
    } catch (error) {
        res.status(500).send(error.message);
    }
};

// Implement other CRUD operations similarly

