# ISettingsNamespace::Settings

## Description

Retrieves an enumerator for the top-level settings for the namespace.

## Parameters

### `Settings` [out]

A pointer to an [IItemEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-iitemenumerator) object that provides methods to access all the settings for this namespace.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It may return **E_OUTOFMEMORY** if there are insufficient resources to return information to the user.

## See also

[ISettingsNamespace](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsnamespace)