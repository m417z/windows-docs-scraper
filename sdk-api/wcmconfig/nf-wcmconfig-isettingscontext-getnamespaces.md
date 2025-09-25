# ISettingsContext::GetNamespaces

## Description

Gets the namespaces that exist in the context.

## Parameters

### `ppNamespaceIds` [out]

An [IItemEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-iitemenumerator) interface pointer that represents the collection of namespaces.

## Return value

This method returns an HRESULT value. **S_OK** indicates success.

## Remarks

**Note** This method may return **E_OUTOFMEMORY** if there are insufficient resources in the system to allocate a new enumerator.

## See also

[ISettingsContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingscontext)