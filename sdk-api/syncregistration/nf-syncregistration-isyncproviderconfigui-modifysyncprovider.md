# ISyncProviderConfigUI::ModifySyncProvider

## Description

Updates the [ISyncProviderInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderinfo) of the synchronization provider that is configured by this **ISyncProviderConfigUI**.

## Parameters

### `hwndParent` [in]

HWND serving as the parent for the configuration UI that needs to be presented before the synchronization provider can be created.
The HWND should be **NULL** only if the **dwCapabilities** member of the [SyncProviderConfigUIConfiguration](https://learn.microsoft.com/windows/win32/api/syncregistration/ns-syncregistration-syncproviderconfiguiconfiguration) structure is set to not support a UI.

### `pUnkContext` [in]

Pointer to an interface containing additional information needed to generate the synchronization provider. The pointer will be **NULL** if no additional information is needed.

### `pProviderInfo` [in]

An [ISyncProviderInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderinfo) that provides information about the synchronization provider that is being modified.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## See also

[ISyncProviderConfigUI Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderconfigui)