# ITSubStreamControl::CreateSubStream

## Description

The
**CreateSubStream** method creates a substream.

## Parameters

### `ppSubStream` [out]

Pointer to
[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream) interface created.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppSubStream* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_MAXSTREAMS** | Substream cannot be created because the maximum number of streams has already been reached. |

## Remarks

Many MSPs do not support dynamic creation of substreams, and simply return TAPI_E_MAXSTREAMS in their implementation of this method.

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream) interface returned by **ITSubStreamControl::CreateSubStream**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**ITSubStream** interface to free resources associated with it.

## See also

[ITSubStreamControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstreamcontrol)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)