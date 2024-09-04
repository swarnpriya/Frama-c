# Function contract:
- The goal of a function contract is to state the properties of the input that are expected by the function, and in exchange the properties that will be assured for the output. 
- The expectation of the function is called the $\textbf{precondition}$.
- The properties of the output are called the $\textbf{postcondition}$.
- These properties are expressed with ACSL.
  - Logic constructs and connectors are used to write the specifications.
  - Built-in predicates to express properties that are useful about C programs (for example a valid pointer can be written using ```\valid(p)```)

## Specification language:
- ```@```: All contracts are started with this symbol to indicate Frama-C that what follows it are annotations and not a comment block that it should simply ignore.
- ```==>```: Implication (A ==> B)
- ```<=>```: Equivalence (A <=> B)
### Postcondition:
- The postcondition of a function is introduced with the clause ```ensures```. 
