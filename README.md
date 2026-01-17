# Design and Evaluation of a Modular Scientific Calculator in C




---

## What This Project Is

I built a scientific calculator from scratch in C that can handle different types of math problems. Instead of just being a basic four-function calculator, it has separate modes for arithmetic, matrices, solving equations, and trigonometry. 

The main challenge wasn't just getting the math right - it was designing the program so that each feature is cleanly separated, handles bad input gracefully, and actually works the way you'd expect a calculator to work.

---
**Language:** C  
**Project Focus:** Modular Programming & Numerical Computing

## Why I Made This

At first year, a calculator seems pretty simple, but once you start implementing one in C, you realize there are a lot of hidden challenges:

- How do you handle division by zero without crashing?
- What happens when someone enters letters instead of numbers?
- How do you make matrix operations work for different sized matrices?
- How do you organize the code so adding new features doesn't break everything?

I wanted to tackle these problems and see if I could build something that's both functional and well-structured. Also, working in C meant dealing with memory management and numerical precision issues directly, which was a good learning experience.

---

## What It Can Do

The calculator has four main modes, each handling a different type of calculation:

### 1. Basic Arithmetic
This is your standard calculator stuff - addition, subtraction, multiplication, and division. It works with both whole numbers and decimals (integers and floating-point numbers in C terms).

The tricky part here was making sure edge cases work correctly, like dividing by zero or handling really large numbers.

### 2. Matrix Operations
You can create matrices, do basic matrix math, and solve simple matrix equations. The program checks that your matrices are compatible before trying to multiply them (you can't multiply a 2x3 matrix by a 2x3 matrix, for example).

Matrix operations were probably the most challenging part because you have to manage 2D arrays in C, validate dimensions, and make sure the math is correct.

### 3. Equation Solver
This mode solves linear and quadratic equations. For quadratic equations, it uses the quadratic formula to find the roots (including handling cases with no real solutions).

I went with analytical methods rather than numerical approximation because for these types of equations, you can get exact answers.

### 4. Trigonometry Functions
Sin, cos, tan, and their inverse functions. The program uses C's math library for these calculations, which means I had to be careful about angle units and handling inputs that might cause errors (like tan(90°)).

---

## How It's Built

### Overall Structure

The program is organized into separate modules - basically, each computation mode has its own set of functions. This modular approach means:

- Each feature is independent and easier to test
- If I want to add a new mode, I don't have to mess with existing code
- Bugs in one section don't cascade into others

### The Interface

It's a command-line menu system. When you run the program, you see a menu of modes, pick one, and then follow the prompts to enter your numbers. Pretty straightforward, but I spent time making sure the prompts are clear and the error messages are actually helpful.

### Input Validation

This was more work than I expected. The program has to handle:

- Non-numeric input (what if someone types "five" instead of "5"?)
- Out-of-range values (angles outside valid ranges, negative numbers for square roots)
- Incompatible operations (like trying to multiply matrices with mismatched dimensions)

I centralized a lot of the validation logic so I'm not duplicating checks all over the place.

### Libraries Used

I'm using the standard C math library (`math.h`) for trig functions and other advanced operations. Everything else is implemented from scratch using basic C features.

---

## Design Decisions and Trade-offs

While building this, I had to make some choices about what to prioritize:

**Clarity over Performance**  
I went for readable, straightforward code rather than highly optimized algorithms. For a calculator handling normal-sized problems, the performance difference is negligible, but the code is much easier to understand and maintain.

**Modularity over Compactness**  
I could have written more compact code by combining functions, but separating everything into modules makes the whole system more extensible. If I want to add statistical functions or calculus operations later, I can just add a new module.

**Fixed Precision**  
C's standard floating-point types have precision limits. For really big numbers or calculations requiring extreme accuracy, this calculator won't cut it. But for typical use cases, the precision is fine.

---

## Challenges I Ran Into

**Memory Management**  
Working with dynamically sized matrices in C means dealing with pointers and manual memory allocation. I had to be really careful to avoid memory leaks and segmentation faults.

**Floating-Point Precision**  
Floating-point arithmetic in C can be... weird sometimes. Two numbers that should be equal might differ by a tiny amount due to rounding errors. I had to account for this in equality checks and validation.

**Input Handling**  
Getting robust input handling in C is harder than in higher-level languages. I used `scanf` carefully and added extra validation to prevent crashes from unexpected input.

**Edge Cases**  
There are so many edge cases in math operations - division by zero, square roots of negatives, undefined trig values, singular matrices. Each one needed explicit handling.

---

## Limitations

Being honest about what this calculator can't do:

- No symbolic math (it can't solve x² + 5x + 6 symbolically, only numerically)
- Fixed precision (limited by C's double type)
- Command-line only (no graphical interface)
- Matrix operations get slow with really large matrices
- No arbitrary-precision arithmetic for extreme values
- Can't handle complex numbers (well, not yet at least)

These limitations are mostly due to scope decisions - this is a learning project.

---

## What I Learned

Building this calculator taught me a lot about:

**Software Design:** How to structure a program so it's maintainable and extensible. Modular design really does make a difference when you want to add features or fix bugs.

**Numerical Computing:** The difference between theoretical math and implementing math on a computer. Floating-point arithmetic has quirks you don't think about until you're debugging weird rounding errors.

**Error Handling:** How important it is to think about what can go wrong and handle it gracefully. A program that crashes on bad input isn't very useful.

**C Programming:** Working at a lower level than languages like Python really forces you to think about memory, types, and how the computer actually represents numbers.

---

## How to Use It

### Compiling

```bash
gcc calculator.c -o calculator -lm
```

(The `-lm` flag links the math library)

### Running

```bash
./calculator
```

Then just follow the menu prompts. Select a mode, enter your numbers when asked, and the program will show you the result.

### Example Session

```
=== Scientific Calculator ===
1. Arithmetic
2. Matrix Operations
3. Equation Solver
4. Trigonometry
Select mode: 1

Enter first number: 15
Enter operation (+, -, *, /): *
Enter second number: 7
Result: 105.00
```

---

## Technical Notes

The code is written in standard C (C99) and should compile on any system with a C compiler. I tried to keep dependencies minimal - just the standard library and math library.

The modular structure means each computation mode has:
- Its own header file with function prototypes
- Implementation file with the actual logic
- Input validation specific to that mode
- Error handling for edge cases

This separation made testing much easier since I could test each module independently.

---

## Final Thoughts

This project was more challenging than I expected, but in a good way. Calculators seem simple from the outside, but implementing one correctly requires thinking about numerical precision, user input, error handling, and software architecture.

The modular design approach worked really well - it made the code easier to write, test, and extend. And working in C, while more difficult than using a high-level language, gave me much better understanding of how numerical computation actually works at a lower level.
