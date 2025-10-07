# \_chkstk Routine

Called by the compiler when you have more than one page of local variables in your function.

## Remarks

\_chkstk Routine is a helper routine for the C compiler. For x86 compilers, \_chkstk Routine is called when the local variables exceed 4K bytes; for x64 compilers it is 8K.

