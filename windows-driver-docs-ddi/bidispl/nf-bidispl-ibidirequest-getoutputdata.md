## Description

The **GetOutputData** method gets the specified output data coming back from the printer.

## Parameters

### `dwIndex` [in]

A zero-based index of the output data that is requested. For more information, see Remarks.

### `ppszSchema` [out]

A pointer to a NULL-terminated string that receives the schema string. The caller must call the [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free this pointer.

### `pdwType` [out]

A pointer to a variable that receives the type of the output data. This parameter can be one of the following values.

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

### `ppData` [out]

A pointer to the variable that receives a pointer to the byte array containing the output data. The buffer is allocated by the COM interface to store the output data. The caller is responsible for calling [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree) to free the buffer.

### `uSize` [out]

A pointer to a variable that receives the size of the byte array specified by **ppData.

## Return value

The method returns one of the following values. For more information about COM error codes, see [COM Error Codes](https://learn.microsoft.com/windows/win32/com/com-error-codes).

| Return code | Description |
|---|---|
| **S_OK** | The operation was successfully carried out. |
| **E_HANDLE** | The interface handle was invalid. |
| **E_POINTER** | At least one of the pointer variable parameters did not reference a valid memory location. |
| **None of the above** | The **HRESULT** contains an error code corresponding to the last error. |

## Remarks

A single bidi request can have multiple results. The application calls [GetEnumCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nf-bidispl-ibidirequest-getenumcount) to get the number of results from the bidi request.

If an application calls **GetOutputData** with the same index twice, the interface allocates two different buffers and thus the application must free both buffers.

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[Bidirectional Communication Schema](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema)

[GetEnumCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nf-bidispl-ibidirequest-getenumcount)

[IBidiRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidirequest)