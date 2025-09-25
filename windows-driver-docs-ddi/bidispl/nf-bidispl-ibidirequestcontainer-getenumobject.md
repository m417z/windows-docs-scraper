## Description

The **GetEnumObject** method enumerates the bidi requests in a list.

## Parameters

### `ppenum` [out]

Pointer to the variable that receives a pointer to the [IEnumUnknown](https://learn.microsoft.com/windows/win32/api/objidl/nn-objidl-ienumunknown) interface that enumerates the bidi requests in the container.

## Return value

The method returns one of the following values. For more information about COM error codes, see [COM Error Codes](https://learn.microsoft.com/windows/win32/com/com-error-codes).

| Value | Description |
|---|---|
| **S_OK** | The operation was successfully carried out. |
| **E_HANDLE** | The interface handle was invalid. |
| **None of the above** | The **HRESULT** contains an error code corresponding to the last error. |

## Remarks

An application can call [IEnumUnknown::Next](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-ienumunknown-next) to retrieve one or more [IBidiRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidirequest) interfaces.

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[Bidirectional Communication Schema](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema)

[IBidiRequestContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidirequestcontainer)

[IEnumUnknown](https://learn.microsoft.com/windows/win32/api/objidl/nn-objidl-ienumunknown)