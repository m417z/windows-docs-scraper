# IWSDDeviceHost::Stop

## Description

Sends a WS-Discovery [Bye](https://learn.microsoft.com/windows/desktop/WsdApi/bye-message) message and stops the host. After a host has been successfully stopped, it must be terminated with [IWSDDeviceHost::Terminate](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-terminate) before being released.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **S_FALSE** | The host has already stopped. |
| **E_FAIL** | The host is not initialized or the host is not started. |

## Remarks

When a device host is stopped using this method, all services remain attached but no inbound messages are processed or otherwise handled.

Calling **Stop** is not necessary if the host has not been started.

## See also

[IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost)