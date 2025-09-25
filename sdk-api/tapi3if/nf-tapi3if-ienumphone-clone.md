# IEnumPhone::Clone

## Description

The
**Clone** method creates another enumerator that contains the same enumeration state as the current one. This method is hidden from Visual Basic and scripting languages.

## Parameters

### `ppEnum` [out]

Pointer to new
[IEnumPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumphone) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnum* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | The method failed for unknown reasons. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[IEnumPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumphone) interface returned by **IEnumPhone::Clone**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**IEnumPhone** interface to free resources associated with it.

## See also

[IEnumPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumphone)