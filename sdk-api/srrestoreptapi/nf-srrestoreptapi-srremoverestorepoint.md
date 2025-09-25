# SRRemoveRestorePoint function

## Description

Deletes the specified restore point.

## Parameters

### `dwRPNum` [in]

The sequence number of the restore point.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the specified restore point does not exist or cannot be removed, the return value is ERROR_INVALID_DATA. All other error codes indicate an internal error.

## Remarks

Applications should not call System Restore functions using load-time dynamic linking. Instead, use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function to load SrClient.dll and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to call the function.

## See also

[SRSetRestorePoint](https://learn.microsoft.com/windows/desktop/api/srrestoreptapi/nf-srrestoreptapi-srsetrestorepointa)