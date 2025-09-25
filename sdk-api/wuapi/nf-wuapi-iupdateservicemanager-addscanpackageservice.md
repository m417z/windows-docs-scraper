# IUpdateServiceManager::AddScanPackageService

## Description

Registers a scan package as a service with Windows Update Agent (WUA) and then returns an [IUpdateService](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservice) interface.

## Parameters

### `serviceName` [in]

A descriptive name for the scan package service.

### `scanFileLocation` [in]

The path of the Microsoft signed scan file that has to be registered as a service.

### `flags` [in]

Determines how to remove the service registration of the scan package.

For possible values, see [UpdateServiceOption](https://learn.microsoft.com/windows/desktop/api/wuapi/ne-wuapi-updateserviceoption).

### `ppService` [out]

A pointer to an [IUpdateService](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservice) interface that contains service registration information.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code. This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A parameter value is invalid. |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |
| **WU_E_INVALID_OPERATION** | The computer could not access the update site. |

## Remarks

You can use the ID of the service in searches by passing the ID as the [ServiceID](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-get_serviceid) property of the [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface.

To free resources, remove the service after it is no longer needed. Use the [RemoveService](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-removeservice) method to remove the service.

Do not call the [RegisterServiceWithAU](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-registerservicewithau) method for the service that the **AddScanPackageService** method registers.

The service that is returned by **AddScanPackageService** is in the collection of services that the [Services](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-get_services) property of the IUpdateServiceManager interface returns. This service has the special [IsScanPackageService](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservice-get_isscanpackageservice) property.

An error is returned by [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) if the Authorization Cab is not signed.

This method returns **WU_E_INVALID_OPERATION** if the object that implements the interface has been locked down.

## See also

[IUpdateServiceManager](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservicemanager)