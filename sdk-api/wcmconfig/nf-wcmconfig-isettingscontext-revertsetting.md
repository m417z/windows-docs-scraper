# ISettingsContext::RevertSetting

## Description

Reverts a setting in the namespace.

## Parameters

### `pIdentity` [in]

The fully-specified identity for the namespace that holds the setting to be reverted.

### `pwzSetting` [in]

A path to a setting within the namespace that has been overridden in this context.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It returns **WCM_E_NAMESPACENOTFOUND** if *pIdentity* specifies a namespace that is not currently in the context. It returns **WCM_E_STATENODENOTFOUND** if *pwzSetting* is not changed in the context.

## See also

[ISettingsContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingscontext)