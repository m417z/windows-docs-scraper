## Description

The **GetResult** method tells whether the bidi request was successful.

## Parameters

### `phr` [out]

Pointer to a variable that specifies the status of the bidi request.

## Return value

The method returns one of the following values. For more information about COM error codes, see [COM Error Codes](https://learn.microsoft.com/windows/win32/com/com-error-codes).

| Value | Description |
|---|---|
| **S_OK** | The operation was successfully carried out. |
| **E_HANDLE** | The interface handle was invalid. |
| **E_POINTER** | At least one of the pointer variable parameters did not reference a valid memory location. |
| **None of the above** | The **HRESULT** contains an error code corresponding to the last error. |

The return value indicates whether the method was successful. It does not indicate what happened to the bidi request.

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[Bidirectional Communication Schema](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema)

[IBidiRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidirequest)