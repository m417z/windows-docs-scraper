## Description

The **GetRequestCount** method gets the number of requests in the request list.

## Parameters

### `puCount` [out]

Pointer to a variable that receives the number of requests.

## Return value

The method returns one of the following values. For more information about COM error codes, see [COM Error Codes](https://learn.microsoft.com/windows/win32/com/com-error-codes).

| Value | Description |
|---|---|
| **S_OK** | The operation was successfully carried out. |
| **E_HANDLE** | The interface handle was invalid. |
| **None of the above** | The **HRESULT** contains an error code corresponding to the last error. |

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[Bidirectional Communication Schema](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema)

[IBidiRequestContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidirequestcontainer)