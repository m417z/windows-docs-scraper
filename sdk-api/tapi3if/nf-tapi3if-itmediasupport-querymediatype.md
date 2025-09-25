# ITMediaSupport::QueryMediaType

## Description

The
**QueryMediaType** method indicates whether the service provider associated with the current address supports the
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) or types indicated by *lMediaType*.

## Parameters

### `lMediaType` [in]

[Media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) or types being queried.

### `pfSupport` [out]

Pointer to a VARIANT_BOOL indicating whether the media type is supported. If the returned value is VARIANT_TRUE, the media is supported; if it is VARIANT_FALSE, the media is not supported.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pfSupport* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITMediaSupport](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itmediasupport)