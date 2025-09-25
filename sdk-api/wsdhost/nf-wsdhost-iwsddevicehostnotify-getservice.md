# IWSDDeviceHostNotify::GetService

## Description

Retrieves a service object that is not currently registered.

## Parameters

### `pszServiceId` [in]

The ID of the service to be produced.

### `ppService` [out]

 A reference to an [IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy) object for the specified service.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |

## See also

[IWSDDeviceHostNotify](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehostnotify)