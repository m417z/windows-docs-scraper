# DsReplicaAddW function

## Description

The **DsReplicaAdd** function adds a replication source reference to a destination naming context.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `NameContext` [in]

The null-terminated string that specifies the distinguished name (DN) of the destination naming context (NC) for which to add the replica. The destination NC record must exist locally as either an object, instantiated or not, or a reference phantom, for example, a phantom with a GUID.

### `SourceDsaDn` [in]

The null-terminated string that specifies the DN of the **NTDS-DSA** object for the source directory system agent. This parameter is required if *Options* includes **DS_REPADD_ASYNCHRONOUS_REPLICA**; otherwise, it is ignored.

### `TransportDn` [in]

The null-terminated string that specifies the DN of the **interSiteTransport** object that represents the transport used for communication with the source server. This parameter is required if *Options* includes **DS_REPADD_INTERSITE_MESSAGING**; otherwise, it is ignored.

### `SourceDsaAddress` [in]

The null-terminated string that specifies the transport-specific address of the source DSA. This source server is identified by a string name, not by its UUID. A string name appropriate for *SourceDsaAddress* is usually a DNS name based on a GUID, where the GUID part of the name is the GUID of the **NTDS-DSA** object for the source server.

### `pSchedule` [in]

Pointer to a [SCHEDULE](https://learn.microsoft.com/windows/desktop/api/schedule/ns-schedule-schedule) structure that contains the replication schedule data for the replication source. This parameter is optional and can be **NULL** if not used.

### `Options` [in]

Passes additional data to be used to process the request. This parameter can be a combination of the following values.

#### DS_REPADD_ASYNCHRONOUS_OPERATION

Performs this operation asynchronously.

#### DS_REPADD_ASYNCHRONOUS_REPLICA

Does not replicate the NC. Instead, save enough state data such that it may be replicated later.

#### DS_REPADD_DISABLE_NOTIFICATION

Disables notification-based synchronization for the NC from this source. This is expected to be a temporary state. Use **DS_REPADD_NEVER_NOTIFY** to permanently disable synchronization.

#### DS_REPADD_DISABLE_PERIODIC

Disables periodic synchronization for the NC from this source.

#### DS_REPADD_INITIAL

Synchronizes the NC from this source when the DSA is started.

#### DS_REPADD_INTERSITE_MESSAGING

Synchronizes from the source DSA using the Intersite Messaging Service (IMS) transport, for example, by SMTP, rather than using the native directory service RPC.

#### DS_REPADD_NEVER_NOTIFY

Disables change notifications from this source. When this flag is set, the source does not notify the destination when changes occur. This is recommended for all intersite replication that may occur over WAN links.

This is expected to be a permanent state; use **DS_REPADD_DISABLE_NOTIFICATION** to temporarily disable notifications.

#### DS_REPADD_PERIODIC

Synchronizes the NC from this source periodically, as defined in *pSchedule*.

#### DS_REPADD_USE_COMPRESSION

Uses compression when replicating. This saves network bandwidth at the expense of CPU overhead at both the source and destination servers.

#### DS_REPADD_WRITEABLE

Creates a writable replica; otherwise, the replica is read-only.

##### - Options.DS_REPADD_ASYNCHRONOUS_OPERATION

Performs this operation asynchronously.

##### - Options.DS_REPADD_ASYNCHRONOUS_REPLICA

Does not replicate the NC. Instead, save enough state data such that it may be replicated later.

##### - Options.DS_REPADD_DISABLE_NOTIFICATION

Disables notification-based synchronization for the NC from this source. This is expected to be a temporary state. Use **DS_REPADD_NEVER_NOTIFY** to permanently disable synchronization.

##### - Options.DS_REPADD_DISABLE_PERIODIC

Disables periodic synchronization for the NC from this source.

##### - Options.DS_REPADD_INITIAL

Synchronizes the NC from this source when the DSA is started.

##### - Options.DS_REPADD_INTERSITE_MESSAGING

Synchronizes from the source DSA using the Intersite Messaging Service (IMS) transport, for example, by SMTP, rather than using the native directory service RPC.

##### - Options.DS_REPADD_NEVER_NOTIFY

Disables change notifications from this source. When this flag is set, the source does not notify the destination when changes occur. This is recommended for all intersite replication that may occur over WAN links.

This is expected to be a permanent state; use **DS_REPADD_DISABLE_NOTIFICATION** to temporarily disable notifications.

##### - Options.DS_REPADD_PERIODIC

Synchronizes the NC from this source periodically, as defined in *pSchedule*.

##### - Options.DS_REPADD_USE_COMPRESSION

Uses compression when replicating. This saves network bandwidth at the expense of CPU overhead at both the source and destination servers.

##### - Options.DS_REPADD_WRITEABLE

Creates a writable replica; otherwise, the replica is read-only.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value can be one of the following.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsReplicaDel](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicadela)

[DsReplicaModify](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicamodifya)

[DsReplicaSync](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasynca)

[DsReplicaUpdateRefs](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaupdaterefsa)

[SCHEDULE](https://learn.microsoft.com/windows/desktop/api/schedule/ns-schedule-schedule)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsReplicaAdd as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).