# \_allmul Routine

Multiplies two **LONGLONG** or **ULONGLONG** integers.
For example, to multiply two int64 values the compiler might generate a call to the **\_allmul** routine.

## Remarks

The **\_allmul** routine is a helper routine for the C compiler.
Whether the compiler uses **\_allmul** is completely dependent on the optimization set.

This routine is used only on x86 platforms.