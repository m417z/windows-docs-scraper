# LookupWordSetString function

The **LookupWordSetString** function returns the string corresponding to the requested value from a labeled set.

## Parameters

*lpSet*

Labeled set from which you extract the value's label.

*Value*

Value of a labeled set.

## Return value

If the function is successful, the return value is a string that corresponds to the requested value.

If the function is unsuccessful, the specified value is not in the set, the return value is **NULL**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Parser.lib |
| DLL<br> | Nmapi.dll |

