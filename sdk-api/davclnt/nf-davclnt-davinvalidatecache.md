# DavInvalidateCache function

## Description

Invalidates the contents of the local cache for a remote file on a WebDAV server.

## Parameters

### `URLName` [in]

A pointer to a Unicode string that contains the name of a remote file on a WebDAV server. This name can be an HTTP path name (URL) or a UNC path name.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **DavInvalidateCache** function marks the contents of the locally cached file (for the specified URL) for deletion. If this function succeeds, the local file cache is no longer valid. This function fails if there are any handles opened against the file either by the same process or by a different process on the local computer.

If the item that is named in the *URLName* parameter is not present in the cache, **DavInvalidateCache** returns ERROR_SUCCESS without invalidating the cache.