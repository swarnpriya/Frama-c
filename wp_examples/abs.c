/*@ 
    ensures \result >= 0;
    ensures (\old(val) >= 0 ==> \result == \old(val)) &&
            (\old(val) < 0 ==> \result == -\old(val));
*/

int abs(int val) {
    if (val < 0)
        /* assert -2147483647 <= val; */ 
        return -val; 
    return val;
}

/* 
[kernel] Parsing wp_examples/abs.c (with preprocessing)
[wp] Warning: Missing RTE guards
[wp] 2 goals scheduled
[wp] Proved goals:    4 / 4
  Terminating:     1
  Unreachable:     1
  Qed:             2
[wp:pedantic-assigns] wp_examples/abs.c:7: Warning: 
  No 'assigns' specification for function 'abs'.
  Callers assumptions might be imprecise.
[report] Computing properties status...

--------------------------------------------------------------------------------
--- Properties of Function 'abs'
--------------------------------------------------------------------------------

[  Valid  ] Post-condition (file wp_examples/abs.c, line 2)
            by Wp.typed.
[  Valid  ] Post-condition (file wp_examples/abs.c, line 3)
            by Wp.typed.
[  Valid  ] Exit-condition (generated)
            by Unreachable Annotations.
[  Valid  ] Termination-condition (generated)
            by Trivial Termination.
[  Valid  ] Default behavior
            by Frama-C kernel.

--------------------------------------------------------------------------------
--- Status Report Summary
--------------------------------------------------------------------------------
     5 Completely validated
     5 Total
--------------------------------------------------------------------------------
*/