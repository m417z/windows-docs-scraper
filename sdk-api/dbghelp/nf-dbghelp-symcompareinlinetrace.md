# SymCompareInlineTrace function

## Description

Compares two inline traces.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Address1` [in]

The first address to be compared.

### `InlineContext1` [in]

The inline context for the first trace to be compared.

### `RetAddress1` [in]

The return address of the first trace to be compared.

### `Address2` [in]

The second address to be compared.

### `RetAddress2` [in]

The return address of the second trace to be compared.

## Return value

Indicates the result of the comparison.

| Return code/value | Description |
| --- | --- |
| **SYM_INLINE_COMP_ERROR**<br><br>0 | An error occurred. |
| **SYM_INLINE_COMP_IDENTICAL**<br><br>1 | The inline contexts are identical. |
| **SYM_INLINE_COMP_STEPIN**<br><br>2 | The inline trace is a step-in of an inline function. |
| **SYM_INLINE_COMP_STEPOUT**<br><br>3 | The inline trace is a step-out of an inline function. |
| **SYM_INLINE_COMP_STEPOVER**<br><br>4 | The inline trace is a step-over of an inline function. |
| **SYM_INLINE_COMP_DIFFERENT**<br><br>5 | The inline contexts are different. |