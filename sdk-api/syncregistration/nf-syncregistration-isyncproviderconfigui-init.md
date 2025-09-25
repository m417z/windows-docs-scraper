# ISyncProviderConfigUI::Init

## Description

Initializes the configuration UI for a synchronization provider.

## Parameters

### `pguidInstanceId` [in]

The instance ID of the configuration UI.

### `pguidContentType` [in]

A GUID that represents the content type that is associated with the synchronization provider that this configuration UI will create.

### `pConfigurationProperties` [in]

The properties that should be specified when the configuration UI is registering the synchronization provider. These properties are also used to properly initialize
the configuration UI object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method will be called by the registration code before the object is returned whenever an instance of the configuration UI is requested from one of the registration interfaces.

## See also

[ISyncProviderConfigUI Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfigui)