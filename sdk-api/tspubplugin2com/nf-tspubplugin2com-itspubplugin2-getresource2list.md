# ItsPubPlugin2::GetResource2List

## Description

Retrieves a list of resources assigned to the specified user. The RemoteApp and Desktop Connection Management service calls this method in the following situations:

* When the user has no cache in Remote Desktop Web Access (RD Web Access).
* When the user has a cache, but it has expired.
* When a call to [GetCacheLastUpdateTime](https://learn.microsoft.com/windows/desktop/api/tspubplugincom/nf-tspubplugincom-itspubplugin-getcachelastupdatetime) returns a time that is later than the time stored in the user's cache.

## Parameters

### `userID` [in]

A null-terminated string that contains the security identifier (SID) of the user. If this parameter is **NULL**, this method should return the resources for all users.

### `pceAppListSize` [out]

The address of a **LONG** variable that receives the number of elements in the *resourceList* array.

### `resourceList` [out]

The address of an array of [pluginResource2](https://learn.microsoft.com/windows/win32/api/tspubplugin2com/ns-tspubplugin2com-pluginresource2) structures that contains the resources for the specified user. You must use the [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) function to allocate this memory. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ItsPubPlugin2](https://learn.microsoft.com/windows/desktop/api/tspubplugin2com/nn-tspubplugin2com-itspubplugin2)