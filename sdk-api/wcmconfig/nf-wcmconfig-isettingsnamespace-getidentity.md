# ISettingsNamespace::GetIdentity

## Description

Gets the identity of the namespace.

## Parameters

### `SettingsID` [out]

A pointer to an [ISettingsIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsidentity) object that represents the namespace identity.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It may return **E_OUTOFMEMORY** if there are insufficient resources to return information to the user.

## See also

[ISettingsNamespace](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsnamespace)