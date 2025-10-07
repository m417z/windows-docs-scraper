# VarLenSmallIntToDword function

The **VarLenSmallIntToDword** function converts a variable-length, small integer to a **DWORD**.

## Parameters

*pValue*

Pointer to the variable-length, small integer.

*ValueLen*

Length (in bytes) of the variable-length, small integer .

*fIsByteswapped*

Flag that indicates whether the variable length small integer is byte-swapped.

*lpDword*

The **DWORD** that the integer is converted to.

## Return value

The return value is a pointer to the **DWORD**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Parser.lib |
| DLL<br> | Nmapi.dll |

