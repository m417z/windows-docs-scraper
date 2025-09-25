# ISettingsNamespace::Save

## Description

Updates the settings namespace to persistent and visible.

## Parameters

### `PushSettings` [in]

 Not used. A flag that controls whether to transfer settings to the registry or to an initialization file.

### `Result` [out]

 A pointer to an [ISettingsResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsresult) object that contains any error that may have occurred while saving the namespace.

## Return value

This method returns an HRESULT value. **S_OK** indicates success.

## See also

[ISettingsNamespace](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsnamespace)