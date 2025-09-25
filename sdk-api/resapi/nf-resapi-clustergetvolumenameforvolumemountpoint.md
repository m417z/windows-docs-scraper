# ClusterGetVolumeNameForVolumeMountPoint function

## Description

[**ClusterGetVolumeNameForVolumeMountPoint** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [GetVolumeNameForVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumenameforvolumemountpointw).]

Retrieves a cluster volume **GUID** path for the volume that is associated with the
specified cluster shared volume (CSV) mount point (drive letter, volume **GUID** path, or
mounted folder).

## Parameters

### `lpszVolumeMountPoint` [in]

A pointer to a string that contains the path of a mounted folder (for example, "Y:\MountX\") or a drive
letter (for example, "X:\\"). The string must end with a trailing backslash (\\).

### `lpszVolumeName` [out]

A pointer to a string that receives the volume **GUID** path. This path is of the form
"\\?\Volume{*GUID*}\" where *GUID* is a
**GUID** that identifies the volume. If there is more than one volume
**GUID** path for the volume, only the first one in the mount manager's cache is
returned. The string returned is in the format required for
[IVssBackupComponents::AddToSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addtosnapshotset)
and
[IVssBackupComponents::IsVolumeSupported](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-isvolumesupported).

### `cchBufferLength` [in]

The length of the output buffer, in **WCHARs**. A reasonable size for the buffer
to accommodate the largest possible volume **GUID** path is 51 characters.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the input CSV is not locally mounted
the call will fail with an **ERROR_CSV_VOLUME_NOT_LOCAL** (5951) error.

## Remarks

The following examples may help. In these examples "Filename.Ext" does exist but
"File\that\does\not\exist" and "Directory\that\does\not\exist\" do not.

* Input: "C:\ClusterStorage\Volume31\"

  Output: "\\?\Volume{deadbeef-895e-4a1d-9d64-9b82fa068d76}\"
* Input: "C:\ClusterStorage\Volume31\"

  Output: Function fails and sets a last error of **ERROR_CSV_VOLUME_NOT_LOCAL**
  (5951).

  **Note** The CSV volume specified for input is not locally mounted for direct I/O.
* Input: "\\?\C:\ClusterStorage\Volume31\Filename.Ext"

  Output: Function fails and sets a last error of **ERROR_INVALID_PARAMETER** (87).
* Input: "C:\ClusterStorage\Volume31\File\that\does\not\exist"

  Output: Function fails and sets a last error of **ERROR_INVALID_NAME** (123).
* Input: "C:\ClusterStorage\Volume31\Directory\that\does\not\exist\"

  Output: Function fails and sets a last error of **ERROR_INVALID_NAME** (123).
* Input: "\\?\Volume{deadbeef-895e-4a1d-9d64-9b82fa068d76}\"

  Output: "\\?\Volume{deadbeef-895e-4a1d-9d64-9b82fa068d76}\"
* Input: "\\?\Volume{de8b99bb-895e-4a1d-9d64-9b82fa068d76}\ClusterStorage\Volume31\"

  Output: "\\?\Volume{deadbeef-895e-4a1d-9d64-9b82fa068d76}\"

  **Note** The volume in the output is a CSV and is different from the system volume that
  was part of the input.
* Input:
  "\\?\GLOBALROOT\Device\Harddisk0\Partition1\ClusterStorage\Volume31\"

  Output: "\\?\Volume{deadbeef-895e-4a1d-9d64-9b82fa068d76}\"
* Input:
  "\\?\GLOBALROOT\Device\HarddiskVolume1\ClusterStorage\Volume31\"

  Output: "\\?\Volume{deadbeef-895e-4a1d-9d64-9b82fa068d76}\"

**Windows Server 2008 R2:** The initial release of ResApi.h containing the
**ClusterGetVolumeNameForVolumeMountPoint**
function used **TCHAR**-based data types instead of
**WCHAR**-based data types. The UNICODE preprocessor define must be set before ResApi.h
is included.

```cpp
#define UNICODE 1
#include <ResApi.h>
```

The
**ClusterGetVolumeNameForVolumeMountPoint**
function must be called from a node of the cluster.

## See also

[Backing Up and Restoring the Failover Cluster Configuration Using VSS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backing-up-and-restoring-the-failover-cluster-configuration-using-vss)

[Backup and Restore Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backup-and-restore-functions)

[GetVolumeNameForVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumenameforvolumemountpointw)

[IVssBackupComponents::AddToSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addtosnapshotset)

[IVssBackupComponents::IsVolumeSupported](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-isvolumesupported)