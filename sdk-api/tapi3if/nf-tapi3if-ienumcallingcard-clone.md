# IEnumCallingCard::Clone

## Description

The
**Clone** method creates another enumerator that contains the same enumeration state as the current one. This method is hidden from Visual Basic and scripting languages.

## Parameters

### `ppEnum` [out]

Pointer to new
[IEnumCallingCard](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcallingcard) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnum* parameter not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | Failed for unknown reasons. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[IEnumCallingCard](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcallingcard) interface returned by **IEnumCallingCard::Clone**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**IEnumCallingCard** interface to free resources associated with it.

## See also

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)