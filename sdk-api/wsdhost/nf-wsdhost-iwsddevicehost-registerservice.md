# IWSDDeviceHost::RegisterService

## Description

Registers a service object for incoming requests and adds the service to the device host metadata.

## Parameters

### `pszServiceId` [in]

 The ID of the service to be registered. This ID must appear in the device's service host metadata.

### `pService` [in]

The service object that will handle requests addressed to the specified service.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pszServiceId* is **NULL**, the length in characters of *pszServiceId* exceeds WSD_MAX_TEXT_LENGTH (8192), or a service matching *pszServiceId* has already been registered. |

## See also

[IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost)