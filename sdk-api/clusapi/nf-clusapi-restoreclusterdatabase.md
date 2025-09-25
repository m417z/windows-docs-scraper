# RestoreClusterDatabase function

## Description

[This function is available for use in the operating systems specified in the Requirements
section. Support for this function was removed in Windows Server 2008 and this function does nothing and returns
**ERROR_CALL_NOT_IMPLEMENTED**.]

Restores
the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) and restarts the
[Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) on the
[node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) from which the function is called. This node is called the
restoring node.

## Parameters

### `lpszPathName` [in]

Null-terminated Unicode string specifying the path to the backup file. Cluster configuration information is
contained in this location; this is sensitive data that should be protected. For example, this data can be
protected by using an access control list to restrict access to the location where the data is stored.

### `bForce` [in]

If **FALSE**, the restore operation will not be completed if either of the following
circumstances applies:

* Other nodes are currently active.
* The partition layout of the current quorum resource is not identical to the partition layout of the
  quorum resource that was in place when the backup was made. (The term "partition layout"
  refers to the number of partitions on the disk and the offsets to each partition. The disk signature and drive
  letter assignments do not have to be identical.)

Setting *bForce* to **TRUE** causes the operation to proceed
regardless of these preceding circumstances; however, the operation may still fail for other reasons.

### `lpszQuorumDriveLetter` [in, optional]

Optional. Identifies the drive letter of the quorum resource on which the
[cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) will be restored. Use this
parameter only if the quorum resource has been replaced since the backup was made. The string must be formatted
as follows:

* The first character must be alphabetic, that is, in the range 'a'-'z' or 'A'-'Z'.
* The second character must be a colon (':').
* The third character must be a terminating null ('\0').

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error
codes.

| Return code | Description |
| --- | --- |
| **ERROR_CLUSTER_NODE_UP** | The operation failed because other cluster nodes are currently active. If you call [RestoreClusterDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-restoreclusterdatabase) again with *bForce* set to **TRUE**, the cluster will attempt to shut down the Cluster service on the other active nodes. |
| **ERROR_QUORUM_DISK_NOT_FOUND** | The operation failed because the quorum disk described in the backup does not match the current quorum disk. If you call [RestoreClusterDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-restoreclusterdatabase) again with *bForce* set to **TRUE**, the cluster will attempt to change the signature and drive letter of the current quorum disk to the values stored in the backup. |

## Remarks

If the restore operation is successful, the restoring node forms a
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) according to the configuration data in the
restored cluster database. As other nodes join the cluster, they update their cluster databases from the database
on the restoring node.

Note that [cluster disks](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) other than the quorum
resource that have added or changed since the backup was made will not be recognized by the restored cluster
database and will remain [offline](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/o-gly) even if the restore
operation is successful. New [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) must be created for these
disks (see
[Creating a Physical Disk Resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/creating-physical-disk-resources)).

The following general procedure is recommended for any cluster restore routine:

1. Call **RestoreClusterDatabase** with
   *bForce* set to **FALSE** and no drive letter specified. This is
   the best approach because, if successful, the operation does not have to force configuration changes.
2. If the first call fails, let the user decide whether to force the procedure to continue or manually fix the
   problem. Be sure to communicate the implications of each decision.

   | Return value | Action if forced | Manual fix |
   | --- | --- | --- |
   | **ERROR_CLUSTER_NODE_UP** | The restore operation will stop the Cluster service on all other nodes. | User manually shuts down the Cluster service on all other cluster nodes. The command **Net Stop ClusSvc** is sufficient; a complete power-down is unnecessary. |
   | **ERROR_QUORUM_DISK_NOT_FOUND** | User must supply the drive letter of the quorum resource. The restore operation will change the disk's signature and drive letter to the values stored in the backup. | User repartitions the quorum disk so that the layout is identical to the layout stored in the backup. |

   If the user agrees to force continuation, call
   **RestoreClusterDatabase** with
   *bForce* set to **TRUE** and the drive letter specified (if
   applicable). Forcing does not guarantee success. If the restore operation fails again, test the return value
   and respond appropriately.

#### Examples

The following example illustrates the procedure described above. For a more complete example that includes
[BackupClusterDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-backupclusterdatabase), see the
[Backing Up and Restoring the Cluster Configuration](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/backing-up-and-restoring-the-cluster-configuration).
This example uses the [ClusDocEx.h](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusdocex-h) header file defined in the
Failover Cluster documentation.

```cpp

int main( void )
{
    WCHAR szPath[] = L"c:\\ClusBack\\19991215";
    WCHAR szInput[3];
    BOOL bForce = FALSE;
    DWORD dwResult = ERROR_SUCCESS;

    // First try: no force
    dwResult = RestoreClusterDatabase( szPath, FALSE, NULL );

    // Allow user to force shutdown if necessary.
    if( dwResult == ERROR_CLUSTER_NODE_UP )
    {
        wprintf( L"The operation failed because other cluster nodes are currently active. " );
        wprintf( L"The Cluster service must be shut down on all other nodes in order for this operation to succeed." );
        wprintf( L"Enter 'f' to force automatic shutdown, or any other key to exit for manual shutdown:  " );
        fgetws( szInput, 2, stdin );
        if( towupper( szInput[0] ) == L'F' )
            dwResult = RestoreClusterDatabase( szPath, TRUE, NULL );
    }

    // Allow user to locate quorum resource if necessary.
    if( dwResult == ERROR_QUORUM_DISK_NOT_FOUND )
    {
        wprintf( L"\n\nERROR: QUORUM DISK NOT FOUND\n" );
        wprintf( L"The restore routine cannot find a quorum resource with the same partition layout as the quorum resource described in the backup. " );
        wprintf( L"The existing quorum resource must have a layout (number of partitions and offsets to each partition) identical to the layout stored in the backup.\n" );
        wprintf( L"Enter the drive letter of the quorum resource to force continuation, or any non-letter key to exit:  " );
        fgetws( szInput, 3, stdin );
        if( iswalpha( szInput[0] ) )
        {
            szInput[1] = L':';
            szInput[2] = L'\0';
            dwResult = RestoreClusterDatabase( szPath, TRUE, szInput );
        }
    }

    // Only one force attempt per error, then report success or failure.
    if( dwResult == ERROR_SUCCESS )
    {
        wprintf( L"\n\nSUCCESS\n" );
        wprintf( L"The restore routine succeeded. Start the Cluster service on the other cluster nodes to complete the restore operation." );
        wprintf( L"As nodes join the cluster, they will update their cluster databases to match the restored configuration." );
        return 0;
    }
    else
    {
        wprintf( L"RestoreClusterDatabase failed (%d)\n", dwResult );
        return 1;
    }

}

```

## See also

[BackupClusterDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-backupclusterdatabase)