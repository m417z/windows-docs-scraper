# DsReplicaSyncA function

## Description

The **DsReplicaSync** function synchronizes a destination naming context (NC) with one of its sources.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `NameContext` [in]

Pointer to a constant null-terminated string that specifies the distinguished name of the destination NC.

### `pUuidDsaSrc` [in]

Pointer to the UUID of a source that replicates to the destination NC.

### `Options` [in]

Passes additional data used to process the request. This parameter can be a combination of the following values.

#### DS_REPSYNC_ADD_REFERENCE

Causes the source directory system agent (DSA) to verify that the local DSA is present in the source replicates-to list. If not, the local DSA is added. This ensures that the source sends change notifications.

#### DS_REPSYNC_ALL_SOURCES

This value is not supported.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista and Windows Server 2003:** Synchronizes from all sources.

#### DS_REPSYNC_ASYNCHRONOUS_OPERATION

Performs this operation asynchronously.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista and Windows Server 2003:** Required when using **DS_REPSYNC_ALL_SOURCES**.

#### DS_REPSYNC_FORCE

Synchronizes even if the link is currently disabled.

#### DS_REPSYNC_FULL

Synchronizes starting from the first Update Sequence Number (USN).

#### DS_REPSYNC_INTERSITE_MESSAGING

Synchronizes using an ISM.

#### DS_REPSYNC_NO_DISCARD

Does not discard this synchronization request, even if a similar synchronization is pending.

#### DS_REPSYNC_PERIODIC

Indicates this operation is a periodic synchronization request as scheduled by the administrator.

#### DS_REPSYNC_URGENT

Indicates this operation is a notification of an update marked urgent.

#### DS_REPSYNC_WRITEABLE

Replica is writable. Otherwise, it is read-only.

## Return value

If the function performs its operation successfully, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the standard Win32 API errors.

## Remarks

The server that **DsReplicaSync** executes on is called the destination. The destination naming context is brought up-to-date with respect to a source system, identified by the UUID of the source system NTDS Settings object. The destination system must already be configured so that the source system is one of the systems from which it receives replication data.

**Note** Forcing manual synchronization can prevent the directory service from properly prioritizing replication operations. For example, synchronizing a new user may preempt an urgent synchronization performed to provide access to a recently locked out user or to add a new trust password. If you call this API often, you can flood the network with requests, which can interfere with other replication operations. For this reason, it is strongly recommended that this function be used only for single-use scenarios rather than incorporating it into an application that would use it on a regular basis.

> [!NOTE]
> The ntdsapi.h header defines DsReplicaSync as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsReplicaAdd](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaadda)

[DsReplicaDel](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicadela)

[DsReplicaModify](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicamodifya)

[DsReplicaUpdateRefs](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaupdaterefsa)