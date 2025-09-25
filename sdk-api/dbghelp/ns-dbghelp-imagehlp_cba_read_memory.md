# IMAGEHLP_CBA_READ_MEMORY structure

## Description

Contains information about a memory read operation.

## Members

### `addr`

The address to be read.

### `buf`

A pointer to a buffer that receives the memory read.

### `bytes`

The number of bytes to read.

### `bytesread`

A pointer to a variable that receives the number of bytes read.

## See also

[SymRegisterCallbackProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psymbol_registered_callback)