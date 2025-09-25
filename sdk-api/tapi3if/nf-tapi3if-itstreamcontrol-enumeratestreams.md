# ITStreamControl::EnumerateStreams

## Description

The **EnumerateStreams** method enumerates currently available media streams. Provided for C and C++ applications. Automation client applications such as Visual Basic must use the
[get_Streams](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstreamcontrol-get_streams) method.

## Parameters

### `ppEnumStream` [out]

Pointer to pointer for
[IEnumStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumstream) enumerator.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppEnumStream* parameter is not a valid pointer. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[IEnumStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumstream) interface returned by **ITStreamControl::EnumerateStreams**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**IEnumStream** interface to free resources associated with it.

## See also

[ITStreamControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstreamcontrol)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)