# ITSubStreamControl::get_SubStreams

## Description

The
**get_SubStreams** method creates a collection of substreams currently available. Provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateSubStreams](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstreamcontrol-enumeratesubstreams) method.

## Parameters

### `pVariant` [out]

Pointer to **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream) interface pointers.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |
| **E_UNEXPECTED** | The call appears to have been shut down. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream) interface returned by **ITSubStreamControl::get_SubStreams**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**ITSubStream** interface to free resources associated with it.

## See also

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)

[ITSubStreamControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstreamcontrol)

[ITSubstream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)