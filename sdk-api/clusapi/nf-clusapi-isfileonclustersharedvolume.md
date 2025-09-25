# IsFileOnClusterSharedVolume function

## Description

Specifies whether the file is on the cluster shared volume.

## Parameters

### `lpszPathName` [in]

A Unicode string that specifies the path of the cluster shared volume. The string ends with a terminating null character.

### `pbFileIsOnSharedVolume` [out]

**True** if the file is on the cluster shared volume; otherwise **false.**

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails,
it returns one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[Failover Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)