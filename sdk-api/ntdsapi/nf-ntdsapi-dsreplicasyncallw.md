# DsReplicaSyncAllW function

## Description

The **DsReplicaSyncAll** function synchronizes a server with all other servers, using transitive replication, as necessary. By default, **DsReplicaSyncAll** synchronizes the server with all other servers in its site; however, you can also use it to synchronize across site boundaries.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `pszNameContext` [in]

Pointer to a null-terminated string that specifies the distinguished name of the naming context to synchronize. The *pszNameContext* parameter is optional; if its value is **NULL**, the configuration naming context is replicated.

### `ulFlags` [in]

Passes additional data used to process the request. This parameter can be a combination of the following values.

#### DS_REPSYNCALL_ABORT_IF_SERVER_UNAVAILABLE

Generates a fatal error if any server cannot be contacted or if any server is unreachable due to a disconnected or broken topology.

#### DS_REPSYNCALL_CROSS_SITE_BOUNDARIES

Synchronizes across site boundaries. By default, **DsReplicaSyncAll** attempts to synchronize only with DCs in the same site as the home system. Set this flag to attempt to synchronize with all DCs in the enterprise forest. However, the DCs can be synchronized only if connected by a synchronous (RPC) transport.

#### DS_REPSYNCALL_DO_NOT_SYNC

Disables all synchronization. The topology is still analyzed, and unavailable or unreachable servers are still identified.

#### DS_REPSYNCALL_ID_SERVERS_BY_DN

In the event of a non-fatal error, returns server distinguished names (DN) instead of their GUID DNS names.

#### DS_REPSYNCALL_NO_OPTIONS

This option has no effect.

#### DS_REPSYNCALL_PUSH_CHANGES_OUTWARD

Pushes changes from the home server out to all partners using transitive replication. This reverses the direction of replication, and the order of execution of the replication sets from the usual "pulling" mode of execution.

#### DS_REPSYNCALL_SKIP_INITIAL_CHECK

Assumes that all servers are responding. This speeds operation of the **DsReplicaSyncAll** function, but if some servers are not responding, some transitive replications may be blocked.

#### DS_REPSYNCALL_SYNC_ADJACENT_SERVERS_ONLY

Disables transitive replication. Synchronization is performed only with adjacent servers.

### `pFnCallBack` [in]

Pointer to an application-defined [SyncUpdateProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms677968(v=vs.85)) function called by the **DsReplicaSyncAll** function when it encounters an error, initiates synchronization of two servers, completes synchronization of two servers, or finishes synchronization of all the servers in the site.

####

####

### `pCallbackData` [in, optional]

Pointer to application-defined data passed as the first argument of the [SyncUpdateProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms677968(v=vs.85)) callback function pointed to by the *pFnCallBack* parameter.

### `pErrors` [out, optional]

A NULL-terminated array of pointers to
[DS_REPSYNCALL_ERRINFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_errinfoa) structures that contain errors that occurred during synchronization. The memory used to hold both the array of pointers and the MsCS\mscs\clusctl_resource_type_get_private_property_fmts.xml data is allocated as a single block of memory and should be freed when no longer required by a single call to **LocalFree** with the pointer value returned in *pErrors* used as the argument.

##### - ulFlags.DS_REPSYNCALL_ABORT_IF_SERVER_UNAVAILABLE

Generates a fatal error if any server cannot be contacted or if any server is unreachable due to a disconnected or broken topology.

##### - ulFlags.DS_REPSYNCALL_CROSS_SITE_BOUNDARIES

Synchronizes across site boundaries. By default, **DsReplicaSyncAll** attempts to synchronize only with DCs in the same site as the home system. Set this flag to attempt to synchronize with all DCs in the enterprise forest. However, the DCs can be synchronized only if connected by a synchronous (RPC) transport.

##### - ulFlags.DS_REPSYNCALL_DO_NOT_SYNC

Disables all synchronization. The topology is still analyzed, and unavailable or unreachable servers are still identified.

##### - ulFlags.DS_REPSYNCALL_ID_SERVERS_BY_DN

In the event of a non-fatal error, returns server distinguished names (DN) instead of their GUID DNS names.

##### - ulFlags.DS_REPSYNCALL_NO_OPTIONS

This option has no effect.

##### - ulFlags.DS_REPSYNCALL_PUSH_CHANGES_OUTWARD

Pushes changes from the home server out to all partners using transitive replication. This reverses the direction of replication, and the order of execution of the replication sets from the usual "pulling" mode of execution.

##### - ulFlags.DS_REPSYNCALL_SKIP_INITIAL_CHECK

Assumes that all servers are responding. This speeds operation of the **DsReplicaSyncAll** function, but if some servers are not responding, some transitive replications may be blocked.

##### - ulFlags.DS_REPSYNCALL_SYNC_ADJACENT_SERVERS_ONLY

Disables transitive replication. Synchronization is performed only with adjacent servers.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is as follows.

## Remarks

The **DsReplicaSyncAll** function attempts to bind to all servers before generating a topology to synchronize from. If a server cannot be contacted, the function excludes that server from the topology and attempts to work around it. Setting the **DS_REPSYNCALL_SKIP_INITIAL_CHECK** flag in *ulFlags* bypasses the initial binding.

If a server cannot be contacted, the **DsReplicaSyncAll** function attempts to route around it and replicate from as many servers as possible, unless **DS_REPSYNCALL_ABORT_IF_SERVER_UNAVAILABLE** is set in *ulFlags*.

The **DsReplicaSyncAll** function can use the callback function pointed to by *pFnCallBack* to keep an end user informed about the current status of the replication. Execution of the **DsReplicaSyncAll** function pauses when it calls the function pointed to by *pFnCallBack*. If the return value from the callback function is **TRUE**, replication continues; otherwise, the **DsReplicaSyncAll** function terminates replication.

> [!NOTE]
> The ntdsapi.h header defines DsReplicaSyncAll as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DS_REPSYNCALL_ERRINFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_errinfoa)

[DS_REPSYNCALL_UPDATE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_updatea)

[Domain Controller and Replication
Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsReplicaSync](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasynca)

[SyncUpdateProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms677968(v=vs.85))