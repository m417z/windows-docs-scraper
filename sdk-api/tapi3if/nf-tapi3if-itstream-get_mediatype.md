# ITStream::get_MediaType

## Description

The
**get_MediaType** method gets the stream's
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants).

## Parameters

### `plMediaType` [out]

Pointer to media type descriptor.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plMediaType* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)