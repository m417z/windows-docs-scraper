# ISyncProviderConfigUI::GetRegisteredProperties

## Description

Obtains configuration UI properties for reading and writing.

## Parameters

### `ppConfigUIProperties` [out]

Returns the **IPropertyStore** object that contains the configuration UI properties for reading and writing. Both the [ISyncProviderInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderinfo) and [ISyncProviderConfigUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfiguiinfo) interfaces inherit from **IPropertyStore**.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[ISyncProviderConfigUI Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfigui)