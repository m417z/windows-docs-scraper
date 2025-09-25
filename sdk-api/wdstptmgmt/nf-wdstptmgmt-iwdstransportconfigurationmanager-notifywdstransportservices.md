# IWdsTransportConfigurationManager::NotifyWdsTransportServices

## Description

Sends a notification to WDS transport services. The notification value is translated to the appropriate WDS transport service controls, and then these controls are sent to the appropriate services.

## Parameters

### `ServiceNotification` [in]

A value of the [WDSTRANSPORT_SERVICE_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/wdstptmgmt/ne-wdstptmgmt-wdstransport_service_notification) enumeration that specifies the type of service notification to be sent.

## Return value

Standard HRESULT error values are used: S_OK for success; others for failure.

## See also

[IWdsTransportConfigurationManager](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportconfigurationmanager)

[WDSTRANSPORT_SERVICE_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/wdstptmgmt/ne-wdstptmgmt-wdstransport_service_notification)