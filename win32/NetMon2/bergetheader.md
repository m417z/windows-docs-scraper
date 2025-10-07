# BERGetHeader function

The **BERGetHeader** function decodes a choice header.

## Parameters

*pCurrentPointer*

Pointer to the choice header.

*pTag*

Pointer to the returned tag.

*pHeaderLength*

Pointer to the returned header length.

*pDataLength*

Pointer to the returned data length.

*ppNext*

Pointer to the header contents.

## Return value

If the function is successful (that is, a valid BER choice header is found) the return value is **TRUE**.

If the function is unsuccessful, the return value is **FALSE**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Parser.lib |
| DLL<br> | Nmapi.dll |

