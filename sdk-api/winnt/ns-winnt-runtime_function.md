# RUNTIME_FUNCTION structure

## Description

Represents an entry in the function table on 64-bit Windows.

## Members

### `BeginAddress`

The address of the start of the function.

### `EndAddress`

The address of the end of the function.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.UnwindInfoAddress`

The address of the unwind information for the function.

### `DUMMYUNIONNAME.UnwindData`

## See also

[SymFunctionTableAccess64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfunctiontableaccess)