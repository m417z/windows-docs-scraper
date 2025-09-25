# IVssBackupComponentsEx4::GetRootAndLogicalPrefixPaths

## Description

Normalizes a local volume path or UNC share path so that it can be passed to the [IVssBackupComponents::AddToSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addtosnapshotset) method.

## Parameters

### `pwszFilePath` [in]

The path to be normalized.

### `ppwszRootPath` [out]

Receives the root path that should be passed to the [IVssBackupComponents::AddToSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addtosnapshotset) method.

### `ppwszLogicalPrefix` [out]

If *pwszFilePath* is a local path, this parameter receives the volume GUID name. If it's a UNC path, this parameter receives a fully evaluated share path.

### `bNormalizeFQDNforRootPath` [in, optional]

If *pwszFilePath* is a UNC share path, the server name portion can be

* A host name
* A fully qualified domain name
* An IP address

This parameter specifies whether host name format or fully qualified domain name format should be used in the server name portion of the normalized root path that is returned in the *ppwszRootPath* parameter.

If this parameter is **FALSE**, simple host name format will be used.

The default value for this parameter is **FALSE**.

If this parameter is **TRUE**, fully qualified domain name will be used.

In a deployment where a host name could exist in multiple domain suffixes, this parameter should be **TRUE**.

## Return value

The following are the valid return codes for this method.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully returned the path information. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## Remarks

This method normalizes a local volume path or UNC share path and separates it into a root path and a logical prefix path. The root path can then be passed to the [IVssBackupComponents::AddToSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addtosnapshotset) method.

If *pwszFilePath* is a local volume path, the root path will be similar to a volume mount point. In this case, the root and the logical prefix paths map to the results of [GetVolumePathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumepathnamew) and [GetVolumeNameForVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumenameforvolumemountpointw), respectively.

If *pwszFilePath* is a UNC share path, the root and logical prefix paths map to the root path of the file share and the fully evaluated physical share path (which will take into account DFS and cluster deployment), respectively.

If you call this method more than once for the same shadow copy set creation operation, you must set the *bNormalizeFQDNforRootPath* to the same value for every call. Fully qualified domain name format and host name format cannot be mixed in the same shadow copy set.

## See also

[IVssBackupComponents::AddToSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addtosnapshotset)

[IVssBackupComponentsEx4](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponentsex4)