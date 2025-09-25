# ISettingsEngine::CreateSettingsIdentity

## Description

Creates an empty settings identity.

## Parameters

### `SettingsID` [out]

A value that returns a pointer to an empty [ISettingsIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine) object.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It may return **E_OUTOFMEMORY** if there are insufficient resources to allocate the [ISettingsIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine) object.

## See also

[ISettingsEngine](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine)