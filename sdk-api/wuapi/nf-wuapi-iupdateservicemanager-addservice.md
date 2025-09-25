# IUpdateServiceManager::AddService

## Description

Registers a service with Windows Update Agent (WUA).

## Parameters

### `serviceID` [in]

An identifier for a service to be registered.

### `authorizationCabPath` [in]

The path of the Microsoft signed local cabinet file that has the information that is required for a service registration.

### `retval` [out]

An [IUpdateService](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservice) interface that represents an added service.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A parameter value is invalid. |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |
| **WU_E_DS_SERVICEEXPIRED** | The Authorization Cab has expired. |
| **WU_E_DS_INVALIDOPERATION** | The state of Automatic Updates could not be changed. |

## Remarks

This method returns **WU_E_DS_INVALIDOPERATION** if the requested change in the state of Automatic Updates is contrary to the specifications in the Authorization Cab. An error is returned by [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) if the Authorization Cab has not been signed.

## See also

[IUpdateServiceManager](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservicemanager)