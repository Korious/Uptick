import { Schema, model, Document } from 'mongoose';

export interface User extends Document {
    name: string;
    email: string;
    age?: number;
}

const userSchema = new Schema<User>({
    name: { type: String, required: true },
    email: { type: String, required: true, unique: true },
    age: { type: Number }
});

export default model<User>('User', userSchema);
