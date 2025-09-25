# ClusterPrepareSharedVolumeForBackup function

## Description

[**ClusterPrepareSharedVolumeForBackup** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

A call to this function is not required. The function does not do anything other than retrieve the volume path and the volume name.

**Windows Server 2008 R2:** Prepares a cluster shared volume (CSV) for backup. This will mount the CSV locally, pin it to this cluster node,
disable direct I/O, and set the volume state to "Backup in Progress".

## Parameters

### `lpszFileName` [in]

Path to a directory or file on a cluster shared volume.

### `lpszVolumePathName` [out]

Address of buffer that will receive the CSV reparse point.

### `lpcchVolumePathName` [in, out]

Address of a **DWORD** that on input contains the size of the buffer (in
**WCHAR** characters) pointed to by the *lpszVolumePathName*
parameter and on output contains the size of the string written to that buffer. If size on input is not large
enough then the function will fail and return **ERROR_MORE_DATA** and set the
**DWORD** to the required size.

### `lpszVolumeName` [out]

Address of buffer that will receive the volume GUID path for the CSV.

### `lpcchVolumeName` [in, out]

Address of a **DWORD** that on input contains the size of the buffer (in
**WCHAR** characters) pointed to by the *lpszVolumeName*
parameter and on output contains the size of the string written to that buffer. If size on input is not large
enough then the function will fail and return **ERROR_MORE_DATA** and set the
**DWORD** to the required size.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The
**ClusterPrepareSharedVolumeForBackup**
function must be called from a node of the cluster.

## See also

[Backing Up and Restoring the Failover Cluster Configuration Using VSS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backing-up-and-restoring-the-failover-cluster-configuration-using-vss)

[Backup and Restore Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backup-and-restore-functions)