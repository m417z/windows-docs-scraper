# ITLegacyCallMediaControl::MonitorMedia

## Description

The
**MonitorMedia** method sets monitoring for a given media type on the current call. This method enables and disables the detection of media types (modes) on the specified call. When a media type is detected, a message is sent to the application. For more information, see
[lineMonitorMedia](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemonitormedia).

## Parameters

### `lMediaType` [in]

Indicator of
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *lMediaType* parameter is not valid. |
| **E_FAIL** | The associated call object is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITLegacyAddressMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacyaddressmediacontrol)

[ITLegacyCallMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol)