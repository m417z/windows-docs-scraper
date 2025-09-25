# IUpdateServiceManager::SetOption

## Description

Set options for the object that specifies the service ID. The **SetOption** method is also used to determine whether a warning is displayed when you change the registration of Automatic Updates.

## Parameters

### `optionName` [in]

Set this parameter to AllowedServiceID to specify the form of the service ID that is provided to the object.

Set to AllowWarningUI to display a warning when changing the Automatic Updates registration.

### `optionValue` [in]

If the *optionName* parameter is set to AllowServiceID, the *optionValue* parameter is set to the service ID that is provided as a **VT_BSTR** value.

If *optionName* is set to AllowWarningUI, *optionValue* is a **VT_BOOL** value that specifies whether to display a warning when changing the registration of Automatic Updates.

Set the optionValue parameter to VARIANT_TRUE to display the warning UI. Set it to VARIANT_FALSE to suppress the warning UI.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows

error code.

| Return code | Description |
| --- | --- |
| **WU_E_INVALID_OPERATION** | The computer is not allowed to access the update site. |
| **E_INVALIDARG** | An argument of the method is invalid. |

## See also

[IUpdateServiceManager](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservicemanager)