# IUpdateServiceManager::RemoveService

## Description

Removes a service registration from Windows Update Agent (WUA).

## Parameters

### `serviceID` [in]

An identifier for the service to be unregistered.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code. This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A parameter value was invalid. |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |
| **WU_E_DS_NEEDWINDOWSSERVICE** | The Windows Update service could not be removed. |
| **WU_E_DS_INVALIDOPERATION** | The state of Automatic Updates could not be changed. This error is returned if you try to delete the service. |
| **WU_E_DS_UNKNOWNSERVICE** | Attempt to register or remove an unknown service. |

## See also

[IUpdateServiceManager](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservicemanager)