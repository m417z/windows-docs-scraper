# LookupByteSetString function

The **LookupByteSetString** function returns the string corresponding to the specified value of a labeled set.

## Parameters

*lpSet*

Pointer to a labeled set, from which you can extract the value's label.

*Value*

Value of a labeled set.

## Return value

If the function is successful, the return value is a string corresponding to the value provided.

If the function is unsuccessful, the return value is **NULL**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Parser.lib |
| DLL<br> | Nmapi.dll |

