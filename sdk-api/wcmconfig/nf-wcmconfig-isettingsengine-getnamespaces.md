# ISettingsEngine::GetNamespaces

## Description

Returns an enumerator to the installed namespaces.

## Parameters

### `Flags` [in]

A [WcmNamespaceEnumerationFlags](https://learn.microsoft.com/windows/win32/api/wcmconfig/ne-wcmconfig-wcmnamespaceenumerationflags) value that specifies the context to include in the collection of namespaces.

### `Reserved` [in]

Reserved. Must be **NULL**.

### `Namespaces` [out]

An [IItemEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-iitemenumerator) interface pointer whose methods can be used to access members of the collection.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It returns **WCM_E_USERNOTFOUND** if the store is not loaded.

## See also

[ISettingsEngine](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine)