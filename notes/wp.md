# Introduction
- In static analysis, we do not execute the program to check if the specification is satisfied; instead we reason about the mathematical model (more or less abstract) representing the state of the program.
- Every type of instruction, of control structure, is associated to a precise semantics, a model of its behavior in a pure logic, mathematical, world. 
- The logic used in Frama-C (WP plugin) is a variant of Hoare logic. 

## Hoare Triple:
- ```{P} C {Q}```
  P and Q are preciates, logic formulas that express properties about the memory at particular program points. C is the list of instructions that defines the program, and if C terminates, the Q is verified for the new state of the execution. P is a sufficient precondition to ensure that C will bring us to the postcondition Q. 

## Weakest precondition calculus:
- Hoare triple (as stated above) reason about programs in a style called ```forward reasoning```. We calculate from the precondition and from one or multiple instructions, the strongest postcondition we can reach. 
- ```Backward reasoning```: From the wanted postcondition and the instructions we are reasoning about, we find the weakest precondition that ensures this behavior.
- Supports various tools:
    - SMT solvers: Z3, Alt-Ergo, CVC4, etc.
    - Why3
    - Coq: The properties we want to prove can be too complex to be solved automatically by SMT solvers, typically when they requires careful inductive reasoning with precise choices at each step. In this situation, WP allows us to generate verification conditions translated in Coq language, and to write the proof ourselves. 