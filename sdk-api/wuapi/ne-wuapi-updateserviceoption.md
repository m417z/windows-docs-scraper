# UpdateServiceOption enumeration

## Description

Defines the options that affect how the service registration for a scan package service is removed.

## Constants

### `usoNonVolatileService:0x1`

Indicates that you must call the [IUpdateServiceManager::RemoveService](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-removeservice) method to remove the service registration.

Failure to call the [RemoveService](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-removeservice) method before releasing the [IUpdateService](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservice) interface causes a resource leak.

## Remarks

If you do not specify **usoNonVolatileService**, the service registration is automatically removed when you release the [IUpdateService](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservice) interface.

The **UpdateServiceOption** enumeration may require that you update Windows Update Agent (WUA). For more information, see [Updating Windows Update Agent](https://learn.microsoft.com/windows/desktop/Wua_Sdk/updating-the-windows-update-agent).

## See also

[IUpdateServiceManager::AddScanPackageService](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-addscanpackageservice)