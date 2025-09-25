# ISettingsEngine::RegisterNamespace

## Description

Registers a namespace from a stream. The stream passed as a parameter to this method must be the XML for the configuration section of a manifest. This method is deprecated.

## Parameters

### `SettingsID` [in]

An [ISettingsIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsidentity) value that identifies the namespace to be registered.

### `Stream` [in]

The stream that specifies the configuration.

### `PushSettings` [in]

When this flag is set to **TRUE**, settings are pushed to the registry or to the initialization files. If the flag is not set, only the store for settings is changed.

### `Results` [out]

Results is a variant of type **VT_VARIANT** or **VT_ARRAY**, each of which points to an [ISettingsResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsresult) object which describes an error or warning uncovered during manifest compilation.

## Return value

This method returns an HRESULT value. **S_OK** indicates success.

## See also

[ISettingsEngine](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine)