# ISettingsEngine::UnloadStore

## Description

 Unloads the schema store hive and frees resources. If there are currently unreleased SMI objects when calling this method, it fails and returns an error value **E_ACCESSDENIED**. You must release all SMI objects before calling **UnloadStore**.

## Parameters

### `Reserved` [in]

Reserved.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. If there are currently unreleased SMI objects when calling **UnloadStore**, **UnloadStore** will fail and return **E_ACCESSDENIED**. Before calling **UnloadStore**, release all SMI objects. If the store was not already loaded, it may return **E_INVALIDARG**.

## See also

[ISettingsEngine](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine)