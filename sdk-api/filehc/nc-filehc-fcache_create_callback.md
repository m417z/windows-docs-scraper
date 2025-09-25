# FCACHE_CREATE_CALLBACK callback function

## Description

A callback function that is used to create items in the cache. It is called by the [CacheCreateFile](https://learn.microsoft.com/windows/desktop/api/filehc/nf-filehc-cachecreatefile) function.

## Parameters

### `lpstrName` [in]

The name of the file.

### `lpvData` [in]

User-provided data to [CacheCreateFile](https://learn.microsoft.com/windows/desktop/api/filehc/nf-filehc-cachecreatefile).

### `cbFileSize` [out]

The size of the file.

### `cbFileSizeHigh` [out]

The location to return the high **DWORD** of the file size.

## Return value

Returns a handle to the file created in the cache.

## See also

[CacheCreateFile](https://learn.microsoft.com/windows/desktop/api/filehc/nf-filehc-cachecreatefile)