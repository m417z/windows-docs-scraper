# IUpdateServiceManager::UnregisterServiceWithAU

## Description

Unregisters a service with Automatic Updates.

## Parameters

### `serviceID`

An identifier for the service to be unregistered.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A parameter value is invalid. |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |
| **WU_E_DS_NEEDWINDOWSSERVICE** | The Windows Update service could not be removed. |
| **WU_E_DS_INVALIDOPERATION** | The state of Automatic Updates could not be changed. |
| **WU_E_DS_UNKNOWNSERVICE** | Attempt to register an unknown service. |
| **WU_E_INVALID_OPERATION** | The computer could not access the update site. |
| **WU_E_CALL_CANCELLED** | The user canceled the change. |

## Remarks

This method returns **WU_E_DS_INVALIDOPERATION** if the requested change in the state of Automatic Updates is contrary to the specifications in the Authorization Cab. An error is returned by [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) function if the Authorization Cab has not been signed.

This method returns **WU_E_DS_UNKNOWNSERVICE** if the service to be removed does not exist.

This method returns **WU_E_DS_NEEDWINDOWSSERVICE** if you attempt to remove the Windows Update service and if it is the only service that is registered with Automatic Updates.

## See also

[IUpdateServiceManager](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservicemanager)