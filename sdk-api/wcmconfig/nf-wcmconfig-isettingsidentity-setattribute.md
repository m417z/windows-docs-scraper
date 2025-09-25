# ISettingsIdentity::SetAttribute

## Description

Sets an identity attribute for a namespace identity.

## Parameters

### `Reserved` [in]

Reserved. Must be **NULL**.

### `Name` [in]

The name of the attribute.

### `Value` [in]

The value of the attribute.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It returns **WCM_E_ATTRIBUTENOTALLOWED** if the attribute specified by Name is not recognized.

## See also

[ISettingsIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsidentity)