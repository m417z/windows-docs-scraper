# RtlUnicodeToMultiByteSize function

## Description

Determines how many bytes are needed to represent a Unicode string as an ANSI string.

## Parameters

### `BytesInMultiByteString` [out]

Returns the number of bytes for the ANSI equivalent of the Unicode string pointed to by *UnicodeString*. This number does not include the terminating **NULL** character.

### `UnicodeString` [in]

The Unicode source string for which the ANSI length is calculated.

### `BytesInUnicodeString` [in]

The number of bytes in the string pointed to by
*UnicodeString*.

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The count was successful. The various NTSTATUS values are defined in NTSTATUS.H, which is distributed with the Windows DDK. |

## Remarks

It is recommended that you use [WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte) instead of **RtlUnicodeToMultiByteSize**. When its *cbMultiByte* parameter is set to zero, the **WideCharToMultiByte** function returns the number of bytes required for the buffer.