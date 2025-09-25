# _NETWORK_APP_INSTANCE_ECP_CONTEXT structure

## Description

The **NETWORK_APP_INSTANCE_ECP_CONTEXT** structure is an Extra Create Parameter (ECP) and contains an application instance identifier to associate with a file. This structure is used to identify the files opened for a failover cluster client application when that application resumes access to its files on another node.

## Members

### `Size`

Size of this structure. This member is set to **sizeof**(NETWORK_APP_INSTANCE_ECP_CONTEXT).

### `Reserved`

Reserved. Must be set to zero.

### `AppInstanceID`

A unique instance identifier for a failover cluster client application. This is a GUID that associates an application to file opened on a failover cluster node.

## Remarks

When failover to a secondary node in a server cluster occurs, a cluster client application needs resumed access to the files it first opened on the failed node. The Cluster Client Failover infrastructure prevents sharing violations for the application's files on the failover node by validating its access to those files. Access is granted to the files the on the failover node having the same application instance identifier as the files opened on other node had prior to failover. The instance identifier is found in a **NETWORK_APP_INSTANCE_ECP_CONTEXT** structure in a file's ECP list.

For example, a file system filter driver will allocate a **NETWORK_APP_INSTANCE_ECP_CONTEXT** with the unique application instance GUID. The context structure is inserted into the ECP list of a file when it is created or opened. The cluster nodes cache the instance identifier from the ECP when processing the network file system create request. On failover, the resuming node can match the application to its set of opened files and grant access.

The **NETWORK_APP_INSTANCE_ECP_CONTEXT** is identified in an [ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85)) by **GUID_ECP_NETWORK_APP_INSTANCE**. This and other system-defined identifiers are described in [System-Defined ECPs](https://learn.microsoft.com/windows-hardware/drivers/ifs/system-defined-ecps).

For information about how to use ECPs to associate extra information with a file when the file is created, see [Using Extra Create Parameters with an IRP_MJ_CREATE Operation](https://learn.microsoft.com/windows-hardware/drivers/ifs/using-extra-create-parameters-with-an-irp-mj-create-operation).

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)