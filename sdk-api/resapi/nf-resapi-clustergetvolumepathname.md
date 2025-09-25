# ClusterGetVolumePathName function

## Description

[**ClusterGetVolumePathName** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [GetVolumePathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumepathnamew).]

Retrieves the volume mount point on the cluster where the specified path is mounted.

## Parameters

### `lpszFileName` [in]

A pointer to the input path string. Both absolute and relative file and directory names, for example
"..", are acceptable in this path.

If you specify a relative directory or file name without a volume qualifier,
**ClusterGetVolumePathName** returns the drive letter of the
current volume.

If this parameter is an empty string, "", the function fails but the last error is set to
**ERROR_SUCCESS**.

### `lpszVolumePathName` [out]

A pointer to a string that receives the volume mount point for the input path.

### `cchBufferLength` [in]

The length of the output buffer, in **WCHARs**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The following examples may help. In these examples "Filename.Ext" does exist but
"Path\that\does\not\exist" does not.

* Input: "C:\ClusterStorage\Volume31\Filename.Ext"

  Output: "C:\ClusterStorage\Volume31\"
* Input: "\\?\C:\ClusterStorage\Volume31\Filename.Ext"

  Output: "\\?\C:\ClusterStorage\Volume31\"
* Input: "C:\ClusterStorage\Volume31\Path\that\does\not\exist"

  Output: "C:\ClusterStorage\Volume31\"
* Input:
  "\\?\Volume{deadbeef-895e-4a1d-9d64-9b82fa068d76}\ClusterStorage\Volume31\Filename.Ext"

  Output: "\\?\Volume{deadbeef-895e-4a1d-9d64-9b82fa068d76}\ClusterStorage\Volume31\"
* Input:
  "\\?\GLOBALROOT\Device\Harddisk0\Partition1\ClusterStorage\Volume31\Filename.Ext"

  Output: "\\?\GLOBALROOT\Device\Harddisk0\Partition1\ClusterStorage\Volume31\"
* Input:
  "\\?\GLOBALROOT\Device\HarddiskVolume1\ClusterStorage\Volume31\Filename.Ext"

  Output: "\\?\GLOBALROOT\Device\HarddiskVolume1\ClusterStorage\Volume31\"

**Windows Server 2008 R2:** The initial release of ResApi.h containing the
**ClusterGetVolumePathName** function used
**TCHAR**-based data types instead of **WCHAR**-based
data types. The UNICODE preprocessor define must be set before ResApi.h is included.

```cpp
#define UNICODE 1
#include <ResApi.h>
```

The
**ClusterGetVolumePathName**
function must be called from a node of the cluster.

## See also

[Backing Up and Restoring the Failover Cluster Configuration Using VSS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backing-up-and-restoring-the-failover-cluster-configuration-using-vss)

[Backup and Restore Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backup-and-restore-functions)