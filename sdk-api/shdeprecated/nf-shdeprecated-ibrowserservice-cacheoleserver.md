# IBrowserService::CacheOLEServer

## Description

Deprecated. Caches a reference to an external object to avoid reloading the server on reuse.

## Parameters

### `pole` [in]

Type: **[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)***

A pointer to an [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) interface that represents the external object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.