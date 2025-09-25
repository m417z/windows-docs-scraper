# IUpdateServiceManager::RegisterServiceWithAU

## Description

Registers a service with Automatic Updates.

## Parameters

### `serviceID` [in]

An identifier for the service to be registered.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A parameter value is invalid. |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |
| **WU_E_DS_UNKNOWNSERVICE** | An attempt to register an unknown service. |
| **WU_E_DS_NEEDWINDOWSSERVICE** | The Windows Update service could not be removed. |
| **WU_E_INVALID_OPERATION** | The computer could not access the update site, or the state of Automatic Updates could not be changed. |

## Remarks

This method returns **WU_E_DS_UNKNOWNSERVICE** if the service to be registered is unknown to Automatic Updates.

This method returns **WU_E_INVALID_OPERATION** if the method is called with an invalid service ID. This method also returns **WU_E_INVALID_OPERATION** if the service ID is valid but the service can't register with Automatic Updates. That is, the requested change in the state of Automatic Updates is contrary to the specifications in the authorization cabinet file (for example, [CanRegisterWithAU](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservice-get_canregisterwithau) property is set to **FALSE**). An error is returned by [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) function if the authorization cabinet file has not been signed.

This method returns **WU_E_DS_NEEDWINDOWSSERVICE** if you try to remove the Windows Update service.

## See also

[IUpdateServiceManager](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservicemanager)