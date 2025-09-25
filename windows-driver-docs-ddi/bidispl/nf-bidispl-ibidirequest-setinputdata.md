## Description

The **SetInputData** method sets the data to send to the printer.

## Parameters

### `dwType` [in]

The type of data to be sent. This parameter can be one of the following values.

| Value | Description |
|---|---|
| **BIDI_NULL** | No data. |
| **BIDI_INT** | Integer data. |
| **BIDI_FLOAT** | Floating-point number. |
| **BIDI_BOOL** | **TRUE** or **FALSE** |
| **BIDI_STRING** | Unicode character string. |
| **BIDI_TEXT** | Non-localizable Unicode string. |
| **BIDI_ENUM** | Enumeration data in the form of a Unicode string. |
| **BIDI_BLOB** | Binary data. |

### `pData` [in]

A pointer to the byte array that contains the data. For example, if *dwType* is BIDI_BOOL, *pData* points to a buffer that contains a Boolean value and if *dwType* is BIDI_BLOB, *pData* points to a buffer that contains the binary data.

### `uSize` [in]

Size, in bytes, of the byte array specified by *pData*.

## Return value

The method returns one of the following values. For more information about COM error codes, see [COM Error Codes](https://learn.microsoft.com/windows/win32/com/com-error-codes).

| Value | Description |
|---|---|
| **S_OK** | The operation was successfully carried out. |
| **E_HANDLE** | The interface handle was invalid. |
| **E_INVALIDARG** | The type of the data was not consistent with its size. |
| **E_OUTOFMEMORY** | Memory allocation failed. |
| **None of the above** | The **HRESULT** contains an error code corresponding to the last error. |

## Remarks

If an application calls **SetInputData** more than once, only the value of the last call will be set.

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[Bidirectional Communication Schema](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema)

[IBidiRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidirequest)