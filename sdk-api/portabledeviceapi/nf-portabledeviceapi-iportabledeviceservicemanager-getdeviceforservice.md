# IPortableDeviceServiceManager::GetDeviceForService

## Description

The **GetDeviceForService** method retrieves the device associated with the specified service.

## Parameters

### `pszPnPServiceID` [in]

The Plug and Play (PnP) identifier of the service.

### `ppszPnPDeviceID` [out]

The retrieved PnP identifier of the device associated with the service.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | An invalid pointer was supplied. |

## Remarks

Neither the *pszPnPServiceID* parameter nor the *pszPnPDeviceID* parameter can be **NULL**.

An application can retrieve a PnP service identifier by calling the **GetDeviceServices** method.

## See also

[IPortableDeviceServiceManager Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicemanager)