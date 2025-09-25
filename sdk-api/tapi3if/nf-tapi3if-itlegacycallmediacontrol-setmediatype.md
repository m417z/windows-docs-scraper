# ITLegacyCallMediaControl::SetMediaType

## Description

The
**SetMediaType** method sets the media type(s) for the current call in its
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure. For more information, see
[lineSetMediaMode](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediamode).

## Parameters

### `lMediaType` [in]

Indicator of
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_FAIL** | The associated call object is not valid. |
| **E_INVALIDARG** | The *lMediaType* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITLegacyAddressMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacyaddressmediacontrol)

[ITLegacyCallMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol)