# IWSDDeviceHost::Terminate

## Description

Terminates the host and releases any attached services. If a notification sink was passed to the [Start](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-start) method, then the notification sink is released.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_FAIL** | The host is uninitialized or the host has already been terminated. |

## Remarks

Services and notification sinks will not receive messages after the **Terminate** method has completed.

If this device host was started by calling [IWSDDeviceHost::Start](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-start), it must first be stopped by calling [IWSDDeviceHost::Stop](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-stop) before **Terminate** can be called.

**Terminate** must be called before releasing the [IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost).

## See also

[IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost)