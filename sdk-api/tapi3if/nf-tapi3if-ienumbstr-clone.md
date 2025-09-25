# IEnumBstr::Clone

## Description

The
**Clone** method creates another enumerator that contains the same enumeration state as the current one. This method is hidden from Visual Basic and scripting languages.

## Parameters

### `ppEnum` [out]

Pointer to new
[IEnumBstr](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumbstr) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnum* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | Failed for unknown reasons. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[IEnumBstr](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumbstr) interface returned by this method. The application must call the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the
**IEnumBstr** interface to free resources associated with it.

## See also

[IEnumAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagentsession)