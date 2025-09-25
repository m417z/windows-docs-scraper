## Description

Gets an [AccountsSettingsPane](https://learn.microsoft.com/uwp/api/windows.ui.applicationsettings.accountssettingspane) object for the window of the active application.

## Parameters

### `appWindow`

Handle to the window of the active application.

### `riid`

The GUID for the resource interface.

The REFIID, or GUID, of the interface to the resource can be obtained by using the __uuidof() macro. For example:

`__uuidof(AccountSettingsPanel)`

### `accountsSettingsPane`

Address of a pointer to a [AccountSettingsPane](https://learn.microsoft.com/uwp/api/Windows.UI.ApplicationSettings.AccountsSettingsPane) object.

## Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also