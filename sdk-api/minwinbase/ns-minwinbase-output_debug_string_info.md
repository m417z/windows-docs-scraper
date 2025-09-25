# OUTPUT_DEBUG_STRING_INFO structure

## Description

Contains the address, format, and length, in bytes, of a debugging string.

## Members

### `lpDebugStringData`

The debugging string in the calling process's address space. The debugger can use the
[ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory) function to retrieve the value of the string.

### `fUnicode`

The format of the debugging string. If this member is zero, the debugging string is ANSI; if it is nonzero, the string is Unicode.

### `nDebugStringLength`

The lower 16 bits of the length of the string in bytes. As nDebugStringLength is of type WORD, this does not always contain the full length of the string in bytes.

For example, if the original output string is longer than 65536 bytes, this field will contain a value that is less than the actual string length in bytes.

## See also

[DEBUG_EVENT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-debug_event)

[ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory)