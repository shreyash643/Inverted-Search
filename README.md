# Inverted-Search

---

## 📌 Overview

This project implements an **Inverted Index** using **Hashing** in C to enable fast and efficient searching across multiple text files.

The system reads input files, extracts words, and organizes them in a hash table.
Each word stores:

*  List of files in which it appears
*  Number of occurrences in each file

---

## ⚙️ Tech Stack

* C Programming
* Hashing Technique
* Multi-level Linked Lists
* File Handling
* Dynamic Memory Allocation
* Command Line Arguments

---

## 🚀 Features

*  Create database from multiple files
*  Display inverted index
*  Update database with new files
*  Search words efficiently
*  Save database to file

---

## 🧠 Learning Outcomes

* Efficient data organization using hashing
* Implementation of multi-level linked lists
* Real-time data updates without rebuilding structure
* Handling large text data efficiently

---

## 📂 Project Structure

```
Inverted-Search/
│
├── main.c
├── functions.c
├── head.h
├── README.md
└── sample_files/
```

---

## ▶️ How to Run

```bash
gcc main.c functions.c -o inverted
./inverted file1.txt file2.txt
```

---

## ⚠️ Notes

* Only `.txt` files are supported
* Files should not be empty
* Duplicate files are ignored

---

## ⭐ If you like this project

Give it a ⭐ on GitHub!
