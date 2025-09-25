# IEnumStream::Clone

## Description

The
**Clone** method creates another enumerator that contains the same enumeration state as the current one.

## Parameters

### `ppEnum` [out]

Pointer to new
[IEnumStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumstream) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnum* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | Failed for unknown reasons. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[IEnumStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumstream) interface returned by **IEnumStream::Clone**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**IEnumStream** interface to free resources associated with it.

## See also

[IEnumStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumstream)

[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)