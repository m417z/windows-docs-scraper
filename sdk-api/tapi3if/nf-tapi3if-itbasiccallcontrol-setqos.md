# ITBasicCallControl::SetQOS

## Description

The
**SetQOS** method sets the quality of service level for the call.

## Parameters

### `lMediaType` [in]

[Media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) of call.

### `ServiceLevel` [in]

[QOS_SERVICE_LEVEL](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-qos_service_level) indicator of desired QOS level for call.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *lMediaType* parameter is not a valid media type. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[QOS_SERVICE_LEVEL](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-qos_service_level)