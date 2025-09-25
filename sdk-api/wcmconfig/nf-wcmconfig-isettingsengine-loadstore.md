# ISettingsEngine::LoadStore

## Description

 Initializes and loads the schema store hive.

## Parameters

### `Flags` [in]

Flags must have a value 0 or have the value **LINK_STORE_TO_ENGINE_INSTANCE**. In a normal operation, loading the store is a persistent operation which affects the overall state of the system. The store is not cleaned up after the process exits. The developer must call [UnloadStore](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsengine-unloadstore) to avoid a leak in the hive. A leak in the hive can cause future issues when accessing the same image.

## Return value

This method returns an HRESULT value. **S_OK** indicates success.

## Remarks

**Note** If the flag **LINK_STORE_TO_ENGINE_INSTANCE** is passed as an input parameter, the loaded store is considered attached to the current engine and will be unloaded when the [ISettingsEngine](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine) object on which this method was called is finalized. The **ISettingsEngine** object can be finalized either by releasing all pointers to it, or by terminating the process. Developers can call [UnloadStore](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsengine-unloadstore) to force the store to be unloaded early, but it is not necessary when this flag is used.

**Note** When using a target; that is, if you are not loading the store from the default file to the default location in the registry, you must call [UnloadStore](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsengine-unloadstore) to verify that you do not lock the file.

## See also

[ISettingsEngine](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine)