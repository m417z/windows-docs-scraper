# IWSDDeviceHost::RemoveDynamicService

## Description

Unregisters a service object that was registered using [AddDynamicService](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-adddynamicservice). An unregistered service object does not receive incoming requests.

## Parameters

### `pszServiceId` [in]

The ID for the dynamic service to be removed.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pszServiceId* is **NULL**, the length in characters of *pszServiceId* exceeds WSD_MAX_TEXT_LENGTH (8192), or *pszServiceId* was not found in the list of dynamic services. |
| **E_FAIL** | The method failed. It may have failed because the host has not been initialized. Call [Init](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-init) to initialize a device host. |

## Remarks

The device host releases its reference to the service object after the service is unregistered. The service object will not receive callbacks after **RemoveDynamicService** has completed.

## See also

[IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost)