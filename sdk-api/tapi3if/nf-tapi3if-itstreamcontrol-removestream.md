# ITStreamControl::RemoveStream

## Description

The
**RemoveStream** method removes a media stream.

## Parameters

### `pStream` [in]

Pointer to
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *pStream* parameter is not valid. |
| **TAPI_E_NOTSUPPORTED** | This operation is not supported. |

## Remarks

Some MSPs may not support the advanced concept of creating and removing streams, and simply return TAPI_E_NOTSUPPORTED.

Stream creation or removal may involve interaction with a remote endpoint, resulting in a CMC_REMOTE_REQUEST rather than the CMC_LOCAL_REQUEST messages that are received when a stream is stopped or started.

## See also

[ITStreamControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstreamcontrol)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)