# IWSDDeviceHost::Start

## Description

Starts the device host and publishes the device host using a WS-Discovery Hello message. If a notification sink is passed to this method, then the notification sink is also registered. After **Start** has been called successfully, the device host will automatically respond to Probe and Resolve messages.

## Parameters

### `ullInstanceId` [in]

The instance identifier. If no identifier is provided, the current instance value + 1 is used as the default.

**Note** For compatibility with the WS-Discovery specification, this value must be less than or equal to UINT_MAX (4294967295).

### `pScopeList` [in]

Scope of the device host. If **NULL**, no scopes are associated with the host.

### `pNotificationSink` [in, optional]

Reference to an [IWSDDeviceHostNotify](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehostnotify) object that specifies the notification sink.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **S_FALSE** | The device host has already been started. |
| **E_FAIL** | The method failed. It may have failed because the host has not been initialized. Call [Init](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-init) to initialize a device host. |
| **E_ABORT** | There is no metadata associated with the host. |

## See also

[IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost)