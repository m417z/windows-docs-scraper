# LoadStringAddr function

The **LoadStringAddr** function transforms a string (such as "157.54.32.45") and creates a **DWORD** address.

## Parameters

*pAddress*

Pointer to a **DWORD**.

*str*

Pointer to a character string with x.x.x.x representation of an IP address (for example,127.0.0.1).

## Return value

If the function is successful (the address name was found); the return value is **TRUE**.

If the function is unsuccessful, the return value is **FALSE**.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

