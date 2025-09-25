# IPortableDeviceService::Open

## Description

The **Open** method opens a connection to the service.

## Parameters

### `pszPnPServiceID` [in]

The Plug and Play (PnP) identifier for the service, which is the same identifier that is retrieved by the [GetPnPServiceId](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservice-getpnpserviceid) method.

### `pClientInfo` [in]

The [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface specifying the client information.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The PnP identifier specified by the *pszPnPServiceID* parameter is invalid. |
| **E_POINTER** | A **NULL** parameter was specified. |
| **E_WPD_SERVICE_ALREADY_OPENED** | This method has already been called for the service. |

## See also

[IPortableDeviceService Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice)

[Opening a Service](https://learn.microsoft.com/windows/desktop/wpd_sdk/opening-a-service)