# ITSubStreamControl::EnumerateSubStreams

## Description

The
**EnumerateSubStreams** method enumerates currently available media substreams. Provided for C and C++ applications. Automation client applications such as Visual Basic must use the
[get_SubStreams](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstreamcontrol-get_substreams) method.

## Parameters

### `ppEnumSubStream` [out]

Pointer to
[IEnumSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumsubstream) enumeration of substreams.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppEnumSubStream* parameter is not a valid pointer. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[IEnumSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumsubstream) interface returned by **ITSubStreamControl::EnumerateSubStreams**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**IEnumSubStream** interface to free resources associated with it.

## See also

[ITSubStreamControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstreamcontrol)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)