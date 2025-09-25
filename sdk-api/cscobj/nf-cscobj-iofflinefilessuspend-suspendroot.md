# IOfflineFilesSuspend::SuspendRoot

## Description

Suspend or release a share root or directory tree. A suspended item is always in the offline state and is excluded from automatic synchronization by Offline Files.

## Parameters

### `bSuspend` [in]

Specify **TRUE** to suspend, or **FALSE** to release.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

When a share root or directory tree is suspended, all directories and files contained in the share or directory or in any subfolders are suspended as well. This means that both directories and files may be suspended. Note that a directory can be suspended directly (if it is the root of the share or directory tree) or indirectly (if it is one of the items contained in the share or directory tree).

## See also

[IOfflineFilesSuspend](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessuspend)