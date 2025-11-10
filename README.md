# Personal-Expense-Tracker-v1.0
The Personal Expense Tracker v1.0 is a console-based financial tracking tool developed using the C programming language.


---

## Overview
The **Personal Expense Tracker v1.0** is a console-based financial management program developed in **C**, designed to automate expense recording, computation, and analysis.  

It was created as a **self-directed project** inspired by  
- `102903/CO100F – Introduction to C Programming, RSET`  
- `102908/MA100B – Calculus and Linear Algebra, RSET`

This project demonstrates structured programming principles such as **functions, recursion, arrays, strings, and structures**, while incorporating **storage classes** and modular logic.

---

## Features
1. Add new expenses with date, category, and amount  
2. Display all expenses in a formatted table  
3. Calculate total and average spending  
4. Sort expenses by amount (ascending)  
5. Search expenses by category name  
6. Recursive menu for smooth user interaction  
7. Demonstrates `static`, `extern`, and `register` storage classes  

---

## Tech Stack
| Component | Description |
|------------|-------------|
| **Language** | C |
| **Compiler** | GCC (ANSI C) |
| **Environment** | Programiz / OnlineGDB / Local GCC |
| **Header Files Used** | `<stdio.h>`, `<string.h>`, `<math.h>` |
| **Core Concepts** | Functions, Arrays, Structures, Recursion, Storage Classes |

---

## System Architecture

```text
 ┌──────────────────────────────────────────────┐
 │            Personal Expense Tracker          │
 ├──────────────────────────────────────────────┤
 │              MENU (Recursive)                │
 │   ├── Add Expense                            │
 │   ├── Display All                            │
 │   ├── Total Spending                         │
 │   ├── Average Spending                       │
 │   ├── Sort by Amount                         │
 │   ├── Search by Category                     │
 │   └── Exit                                   │
 └──────────────────────────────────────────────┘
