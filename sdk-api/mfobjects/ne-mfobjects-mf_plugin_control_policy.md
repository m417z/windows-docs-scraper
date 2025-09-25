# MF_PLUGIN_CONTROL_POLICY enumeration

## Description

Defines policy settings for the [IMFPluginControl2::SetPolicy](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfplugincontrol2-setpolicy) method.

## Constants

### `MF_PLUGIN_CONTROL_POLICY_USE_ALL_PLUGINS:0`

Enumerate all registered sources and transforms.

### `MF_PLUGIN_CONTROL_POLICY_USE_APPROVED_PLUGINS:1`

Enumerate only approved sources and transforms. Third-party components are excluded unless the component is registered with a valid merit value, or the component was registered locally by the application.

### `MF_PLUGIN_CONTROL_POLICY_USE_WEB_PLUGINS:2`

Restrict enumeration to components intended for use in a web browser.

### `MF_PLUGIN_CONTROL_POLICY_USE_WEB_PLUGINS_EDGEMODE:3`

## See also

[IMFPluginControl2](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfplugincontrol2)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)