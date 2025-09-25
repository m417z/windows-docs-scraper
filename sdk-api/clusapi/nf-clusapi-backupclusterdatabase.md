# BackupClusterDatabase function

## Description

[This function is available for use in the operating systems specified in the Requirements
section. Support for this function was removed in Windows Server 2008 and this function does nothing and returns
**ERROR_CALL_NOT_IMPLEMENTED**.]

Creates a backup of the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) and
all registry [checkpoints](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/checkpointing).

## Parameters

### `hCluster` [in]

Handle to the cluster to be backed up.

### `lpszPathName` [in]

Null-terminated Unicode string specifying the path to where the backup should be created. Cluster
configuration information will be saved to this location; this is sensitive data that should be protected. For
example, this data can be protected by using an access control list to restrict access to the location where the
data is stored.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Ideally, the specified path should be a path visible to all cluster
[nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes), such as a UNC path. At minimum, the path must be visible to
the node that currently owns the [quorum resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource). Do not
include a filename in the path or the function will fail, returning **ERROR_DIRECTORY**.
The path can include a trailing backslash.

One way to ensure that an appropriate path exists is to create a temporary network share, as follows:

* Call the function [NetShareAdd](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareadd) to create a temporary
  network share. All cluster nodes must have write access to this share.
* Call **BackupClusterDatabase**, specifying
  the temporary share in the *lpszPathName* parameter.
* Copy the backup files (see below) to one or more safe storage locations.
* Call the function [NetShareDel](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedel) to delete the
  share.

The backup contains the following files.

| Path\File | Description |
| --- | --- |
| *lpszPathName*\chk????.tmp | Snapshot files. |
| *lpszPathName*\quolog.log | The quorum log file. |
| *lpszPathName*\<GUID of resource>\*.CPT | The registry checkpoint files for the resource identified by GUID. |
| *lpszPathName*\<GUID of resource>\*.CPR | The crypto checkpoint files for the resource identified by GUID. |
| *lpszPathName*\Clusbackup.dat | Backup completion marker file (read-only, hidden, 0-byte file) |

Subsequent **BackupClusterDatabase** operations
that use the same *lpszPath* parameter will overwrite the existing backup files.

If possible, make multiple copies of the backup directory on different media and store these copies in separate
locations.

#### Examples

The following example illustrates a static backup routine. For a more complete example
incorporating [RestoreClusterDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-restoreclusterdatabase), see
[Backing Up and Restoring the Cluster Configuration](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backing-up-and-restoring-the-cluster-configuration).
This example uses the [ClusDocEx.h](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusdocex-h) header file defined in the
Failover Cluster documentation.

```cpp

int main( void )
 {
  HCLUSTER hCluster     = NULL;
  WCHAR szClusterName[] = L"CLUSTER_NAME";
  WCHAR szPath[]        = L"\\\\ClusBack\\19991215";
  DWORD dwResult        = ERROR_SUCCESS;

  if( ( hCluster = OpenCluster( szClusterName ) ) != NULL )
   {
    dwResult = BackupClusterDatabase( hCluster, szPath );
    CloseCluster( hCluster );
   }
  else
    dwResult = GetLastError();

  if( dwResult == ERROR_SUCCESS )
   {
    wprintf( L"\nDone. The cluster database has been backed up to %s. ", szPath );
    wprintf( L"The backup consists of the following files:\n    chk????.tmp\n"
             L"    quolog.log\n    *.cpt\n    *.cpr\n\n" );
    return 0;
   }
  else
   {
    wprintf( L"The operation failed (%d)\n", dwResult );
    return 1;
   }
 }

```

## See also

[Backup and Restore Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backup-and-restore-functions)

[RestoreClusterDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-restoreclusterdatabase)