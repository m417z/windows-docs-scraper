# FPO_DATA structure

## Description

Represents the stack frame layout for a function on an x86 computer when frame pointer omission (FPO) optimization is used. The structure is used to locate the base of the call frame.

## Members

### `ulOffStart`

The offset of the first byte of the function code.

### `cbProcSize`

The number of bytes in the function.

### `cdwLocals`

The number of local variables.

### `cdwParams`

The size of the parameters, in **DWORD**s.

### `cbProlog`

The number of bytes in the function prolog code.

### `cbRegs`

The number of registers saved.

### `fHasSEH`

A variable that indicates whether the function uses structured exception handling.

### `fUseBP`

A variable that indicates whether the EBP register has been allocated.

### `reserved`

Reserved for future use.

### `cbFrame`

A variable that indicates the frame type.

| Type | Meaning |
| --- | --- |
| **FRAME_FPO**<br><br>0 | FPO frame |
| **FRAME_NONFPO**<br><br>3 | Non-FPO frame |
| **FRAME_TRAP**<br><br>1 | Trap frame |
| **FRAME_TSS**<br><br>2 | TSS frame |

## See also

[FunctionTableAccessProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-pfunction_table_access_routine)

[STACKFRAME64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-stackframe)

[SymFunctionTableAccess64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfunctiontableaccess)