# ISettingsEngine::UnregisterNamespace

## Description

Unregisters an existing namespace. This method is deprecated.

## Parameters

### `SettingsID` [in]

An [ISettingsIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsidentity) interface value that identifies the namespace to be unregistered.

### `RemoveSettings` [in]

When **true**, specifies that settings must be removed.

## Return value

This method returns an HRESULT value. **S_OK** indicates success.

## See also

[ISettingsEngine](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine)