# BERGetInteger function

The **BERGetInteger** function decodes a BER-encoded integer.

## Parameters

*pCurrentPointer*

Pointer to the integer that is decoded.

*ppValuePointer*

Pointer to the pointer to returned value.

*pHeaderLength*

Pointer to the returned header length.

*pDataLength*

Pointer to the data length.

*ppNext*

Pointer to the pointer to the next BER entry.

## Return value

If the function is successful (that is, if a valid BER encoded integer is found and converted), the return value is **TRUE**.

If function is unsuccessful, the return value is **FALSE**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Parser.lib |
| DLL<br> | Nmapi.dll |

