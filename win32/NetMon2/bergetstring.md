# BERGetString function

The **BERGetString** function decodes a BER-encoded string.

## Parameters

*pCurrentPointer*

Pointer to the string that is decoded.

*ppValuePointer*

Pointer to the pointer of the decoded string.

*pHeaderLength*

Pointer to the returned header length.

*pDataLength*

Pointer to the string length.

*ppNext*

Pointer to the pointer of the next BER entry.

## Return value

If the function is successful (that is, if a valid BER-encoded string is decoded), the return value is **TRUE**.

If function is unsuccessful, the return value is **FALSE**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Parser.lib |
| DLL<br> | Nmapi.dll |

