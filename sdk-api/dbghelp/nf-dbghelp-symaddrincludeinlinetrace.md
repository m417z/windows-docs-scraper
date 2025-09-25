# SymAddrIncludeInlineTrace function

## Description

Indicates whether the specified address is within an inline frame.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Address` [in]

The address.

## Return value

Returns zero if the address is not within an inline frame.