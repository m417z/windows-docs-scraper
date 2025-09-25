# IOfflineFilesEvents3::PrefetchFileEnd

## Description

Reports that a file prefetch operation has ended.

## Parameters

### `pszPath` [in]

The UNC path of the file.

### `hrResult` [in]

Receives the result of the operation. Contains **S_OK** if the operation completed successfully or an error value otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesEvents3](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents3)