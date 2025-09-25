# ReleaseNameCache function

## Description

Releases a name cache.

## Parameters

### `pNameCache`

A pointer to a [NAME_CACHE_CONTEXT](https://learn.microsoft.com/windows/desktop/api/filehc/ns-filehc-name_cache_context) structure.

## Return value

Returns the resulting decremented reference count.

## Remarks

The caller must guarantee the thread safety of this call.

## See also

[NAME_CACHE_CONTEXT](https://learn.microsoft.com/windows/desktop/api/filehc/ns-filehc-name_cache_context)