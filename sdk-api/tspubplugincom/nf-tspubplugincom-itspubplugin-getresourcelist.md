# ItsPubPlugin::GetResourceList

## Description

Retrieves a list of resources assigned to the specified user. The RemoteApp and Desktop Connection Management service calls this method in the following situations:

* When the user has no cache in Remote Desktop Web Access (RD Web Access).
* When the user has a cache, but it has expired.
* When a call to [GetCacheLastUpdateTime](https://learn.microsoft.com/windows/desktop/api/tspubplugincom/nf-tspubplugincom-itspubplugin-getcachelastupdatetime) returns a time that is later than the time stored in the user's cache.

## Parameters

### `userID` [in]

The user security identifier (SID).

### `pceAppListSize` [out]

A pointer to a **LONG** variable to receive the number of elements in the *resourceList*.

### `resourceList` [out]

The address of a pointer to an array of [pluginResource](https://learn.microsoft.com/windows/win32/api/tspubplugincom/ns-tspubplugincom-pluginresource) structures that receive the resources assigned to the specified user. You must use the [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) function to allocate this memory. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ItsPubPlugin](https://learn.microsoft.com/windows/desktop/api/tspubplugincom/nn-tspubplugincom-itspubplugin)