## Description

The **GetEnumCount** method gets the number of output results from the bidi request.

## Parameters

### `pdwTotal` [out]

A pointer to a variable that receives the number of output results.

## Return value

The method returns one of the following values. For more information about COM error codes, see [COM Error Codes](https://learn.microsoft.com/windows/win32/com/com-error-codes).

| Value | Description |
|---|---|
| **S_OK** | The method was successful. |
| **E_HANDLE** | The interface handle was invalid. |
| **E_POINTER** | The *pdwTotal* parameter did not point to a valid memory location. |
| **None of the above** | The **HRESULT** contains an error code corresponding to the last error. |

## Remarks

A single bidi request can have multiple results. After calling **GetEnumCount**, the application can call [GetOutputData](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nf-bidispl-ibidirequest-getoutputdata) to select a particular result.

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[Bidirectional Communication Schema](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema)

[GetOutputData](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nf-bidispl-ibidirequest-getoutputdata)

[IBidiRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidirequest)