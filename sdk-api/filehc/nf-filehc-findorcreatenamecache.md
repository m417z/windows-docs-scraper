# FindOrCreateNameCache function

## Description

Finds or creates a name cache.

## Parameters

### `lpstrName` [in]

The name of the name cache to be created. This parameter is case sensitive and must not be set to **NULL**.

### `pfnKeyCompare` [in]

A pointer to a function that is provided by a client to compare keys. This parameter cannot be **NULL**.

### `pfnKeyHash` [in]

A pointer to a function that is provided by clients to compute a hash value on keys.

**Note** The cache provides a hash function only if the user does not. However, the internally provided hash function is best only for items that appear to be regular strings.

### `pfnKeyDestroy` [in]

A pointer to the [CACHE_DESTROY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/filehc/nc-filehc-cache_destroy_callback) function. This parameter can be **NULL**.

### `pfnDataDestroy` [in]

A pointer to the [CACHE_DESTROY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/filehc/nc-filehc-cache_destroy_callback) function. This parameter can be **NULL**.

## Return value

Returns a [NAME_CACHE_CONTEXT](https://learn.microsoft.com/windows/desktop/api/filehc/ns-filehc-name_cache_context) structure that represents the name cache.

## Remarks

Name caches are reference counted. If this function is called twice with the same name, a reference is added to an existing name cache.

The [NAME_CACHE_CONTEXT](https://learn.microsoft.com/windows/desktop/api/filehc/ns-filehc-name_cache_context) structure does not contain any fields that are useful to a client, but it must be passed back into all of the name cache functions.

## See also

[CACHE_DESTROY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/filehc/nc-filehc-cache_destroy_callback)

[NAME_CACHE_CONTEXT](https://learn.microsoft.com/windows/desktop/api/filehc/ns-filehc-name_cache_context)