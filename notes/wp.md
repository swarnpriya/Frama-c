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

  ### Commands:
  - ```frama-c -wp "filename.c"``` : -wp resembles to use weaker precondition logic to ensure that a code respects a specification. It does not directly check the absence of runtime errors if we don't ask it. 
  - ```frama-c -wp-rte "filename.c"```: -rte resembles checking the runtime errors like integer overflow, invalid pointer derefencing, division by 0, etc. 

  ### Workflow of WP plugin:
  - When WP transmits a verification condition to an automatic prover, it basically transmits two kinds of properties: $G$, the goal, the property that we want to prove, and $A_1,..., A_n$, the different assumptions we can have about the state of the memory at the program point where we want to verify $G$.
  - WP plugin transforms the specifications into a logic formula and then asks to different provers if it is possible to satisfy this formula (to find for each variable, a value that can make the formula true), and it determines if the property can be proved.
  - Before sending the properties to a prover, WP uses a module called "Qed", which is able to perform different simplifications about it. 

  ### Reason for the prover to get stuck:
  - The prover did not have the information needed to terminate the proof.
  - The prover did not have enough time to compute the proof and met a timeout.  


