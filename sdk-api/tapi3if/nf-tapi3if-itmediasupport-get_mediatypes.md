# ITMediaSupport::get_MediaTypes

## Description

The
**get_MediaTypes** method gets the
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) or types supported on the current address.

## Parameters

### `plMediaTypes` [out]

Pointer to bitmask of ORed of
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plMediaTypes* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITMediaSupport](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itmediasupport)