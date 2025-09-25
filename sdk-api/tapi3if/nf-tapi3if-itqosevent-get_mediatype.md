# ITQOSEvent::get_MediaType

## Description

The
**get_MediaType** method gets the
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) indicator.

## Parameters

### `plMediaType` [out]

Indicates the media type for the call on which the QOS event occurred.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plMediaType* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITQOSEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itqosevent)

[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants)