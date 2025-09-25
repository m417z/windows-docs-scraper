# ISettingsIdentity::GetAttribute

## Description

Gets an identity attribute for a namespace identity.

## Parameters

### `Reserved` [in]

Reserved. Must be **NULL**.

### `Name` [in]

The name of the attribute.

### `Value` [out]

The value of the attribute.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. If the attribute specified by Name is not recognized, this function returns **WCM_E_ATTRIBUTENOTFOUND**.

## See also

[ISettingsIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsidentity)