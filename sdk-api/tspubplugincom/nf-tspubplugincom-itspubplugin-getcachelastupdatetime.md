# ItsPubPlugin::GetCacheLastUpdateTime

## Description

Returns the time that the cache was last updated. The RemoteApp and Desktop Connection Management service calls this method to determine whether the data in the Remote Desktop Web Access (RD Web Access) cache should be refreshed.

## Parameters

### `lastUpdateTime` [out]

A pointer to an **unsigned long long** variable that receives the time that the cache was last updated.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The RemoteApp and Desktop Connection Management service calls this method to get the last time that the cache was refreshed. If your plug-in does not implement caching, return the current system time. This tells the service that it must call [GetResourceList](https://learn.microsoft.com/windows/desktop/api/tspubplugincom/nf-tspubplugincom-itspubplugin-getresourcelist) to get the current list of resources. We recommend implementing the plug-in with caching because caching reduces the number of calls the service must make to **GetResourceList**.

## See also

[ItsPubPlugin](https://learn.microsoft.com/windows/desktop/api/tspubplugincom/nn-tspubplugincom-itspubplugin)