# BeepBeep: Morse Code Converter

**BeepBeep** is a simple, console-based Morse Code Converter that allows users to encode and decode messages using the Morse code system. It provides an interactive, menu-driven interface where users can choose between encoding a message to Morse code or decoding a Morse code message back to text.

In this project, the **Morse code tree** is used to efficiently encode and decode messages. Each character (A-Z, 0-9) is represented by a unique path in the binary tree, where each node has two children corresponding to the **dot (.)** and **dash (-)** symbols.

---

## Features

- **Encode Message**: Converts input text into its equivalent Morse code using a **binary tree** for efficient traversal.
- **Decode Message**: Converts Morse code (separated by spaces) back to readable text by traversing the tree based on the dot and dash signals.
- **Menu-Driven Interface**: Provides a continuous loop for the user to interact with the program until they choose to exit.
- **Error Handling**: Handles invalid characters by outputting a placeholder (`??`) during encoding and decoding.
  
---

## Technologies

- **C Programming Language**: Used to implement the core functionality.
- **Binary Tree Data Structure**: Used to efficiently encode and decode Morse code.
- **Algorithms**: Implemented Morse code encoding and decoding logic using a tree traversal approach.
- **Basic User Interface**: Simple text-based menu for user interaction.

---

## How It Works: Using Trees for Encoding and Decoding

The **Morse Code Tree** is a binary tree where:
- Each **leaf node** represents a letter or number in Morse code.
- Each **internal node** represents a choice between a **dot (.)** or a **dash (-)**.

For **encoding**, the program starts at the root of the tree and traverses down the tree following the path of dots and dashes corresponding to the characters in the message.

For **decoding**, the program starts at the root and follows the dots and dashes from the input Morse code, traversing the tree until it reaches the corresponding letter or number at each leaf node.

This tree-based structure makes the encoding and decoding process efficient and easy to implement.

---

## How to Run

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/BeepBeep.git
   cd BeepBeep
