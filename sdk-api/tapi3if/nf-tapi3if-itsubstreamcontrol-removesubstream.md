# ITSubStreamControl::RemoveSubStream

## Description

The
**RemoveSubStream** method removes a substream.

## Parameters

### `pSubStream` [in]

Pointer to
[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream) to be removed.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *pSubStream* parameter does not point to a valid interface. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_INVALIDSTREAM** | The *pSubStream* parameter does not point to a valid substream. |

## Remarks

Some MSPs may not support the advanced concept of creating and removing substreams, and simply return TAPI_E_NOTSUPPORTED.

## See also

[ITSubStreamControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstreamcontrol)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)