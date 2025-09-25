# ServerSelection enumeration

## Description

Defines the update services that Windows Update can operate against.

## Constants

### `ssDefault`

Used only by [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher). Indicates that the search call should search the default server.

The default server used by the Windows Update Agent (WUA) is the same as **ssMangagedServer** if the computer is set up to have a managed server. If the computer is not been set up to have a managed server, WUA uses the first update service for which the [IsRegisteredWithAU](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservice-get_isregisteredwithau) property of [IUpdateService](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservice) is VARIANT_TRUE and the [IsManaged](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservice-get_ismanaged) property of **IUpdateService** is VARIANT_FALSE

### `ssManagedServer`

Indicates the managed server, in an environment that uses Windows Server Update Services or a similar corporate update server to manage the computer.

### `ssWindowsUpdate`

Indicates the Windows Update service.

### `ssOthers`

Indicates some update service other than those listed previously. If the **ServerSelection** property of a Windows Update Agent API object is set to **ssOthers**, then the **ServiceID** property of the object contains the ID of the service.