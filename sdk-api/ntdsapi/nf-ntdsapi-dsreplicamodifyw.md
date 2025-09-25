# DsReplicaModifyW function

## Description

The **DsReplicaModify** function modifies an existing replication source reference for a destination naming context.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `NameContext` [in]

Pointer to a constant null-terminated string that specifies the distinguished name (DN) of the destination naming context (NC).

### `pUuidSourceDsa` [in]

Pointer to the UUID of the source directory system agent (DSA). This parameter may be null if *ModifyFields* does not include **DS_REPMOD_UPDATE_ADDRESS** and *SourceDsaAddress* is not **NULL**.

### `TransportDn` [in]

Reserved for future use. Any value other than **NULL** results in **ERROR_NOT_SUPPORTED** being returned.

### `SourceDsaAddress` [in]

Pointer to a constant null-terminated Unicode string that specifies the transport-specific address of the source DSA. This parameter is ignored if *pUuidSourceDsa* is not **NULL** and *ModifyFields* does not include **DS_REPMOD_UPDATE_ADDRESS**.

### `pSchedule` [in]

Pointer to a [SCHEDULE](https://learn.microsoft.com/windows/desktop/api/schedule/ns-schedule-schedule) structure that contains the replication schedule data for the replication source. This parameter is optional and can be **NULL** if not used. This parameter is required if *ModifyFields* contains the **DS_REPMOD_UPDATE_SCHEDULE** flag.

### `ReplicaFlags` [in]

This parameter is used to control replication behavior and can take the following values.

#### DS_REPL_NBR_SYNC_ON_STARTUP

Replication of this naming context from this source is attempted when the destination server is booted. This normally only applies to intra-site neighbors.

#### DS_REPL_NBR_DO_SCHEDULED_SYNCS

Perform replication on a schedule. This flag is normally set unless the schedule for this naming context and source is "never", that is, the empty schedule.

#### DS_REPL_NBR_TWO_WAY_SYNC

If set, indicates that when inbound replication is complete, the destination server must tell the source server to synchronize in the reverse direction. This feature is used in dial-up scenarios where only one of the two servers can initiate a dial-up connection. For example, this option would be used in a corporate headquarters and branch office, where the branch office connects to the corporate headquarters over the Internet by means of a dial-up ISP connection.

#### DS_REPL_NBR_IGNORE_CHANGE_NOTIFICATIONS

This neighbor is set to disable notification-based synchronization. Within a site, domain controllers synchronize with each other based on notifications when changes occur. This setting prevents this neighbor from performing a synchronization triggered by a notification. The neighbor will still do synchronization based on its schedule or in response to manually requested synchronization.

#### DS_REPL_NBR_DISABLE_SCHEDULED_SYNC

This neighbor is set to not perform synchronization based on its schedule. The only way this neighbor will perform synchronization is in response to change notifications or to manually requested synchronization.

#### DS_REPL_NBR_COMPRESS_CHANGES

Changes received from this source are to be compressed. This is normally set if, and only if, the source server is in a different site.

#### DS_REPL_NBR_NO_CHANGE_NOTIFICATIONS

No change notifications should be received from this source. This is normally set if, and only if, the source server is in a different site.

### `ModifyFields` [in]

Specifies what fields should be modified. At least one field must be specified in *ModifyFields*. This parameter can be a combination of the following values.

#### DS_REPMOD_UPDATE_ADDRESS

Updates the address associated with the referenced server.

#### DS_REPMOD_UPDATE_FLAGS

Updates the flags associated with the replica.

#### DS_REPMOD_UPDATE_RESULT

Not used. Specifying updates of result values is not currently supported. Result values default to 0.

#### DS_REPMOD_UPDATE_SCHEDULE

Updates the periodic replication schedule associated with the replica.

#### DS_REPMOD_UPDATE_TRANSPORT

Updates the transport associated with the replica.

### `Options` [in]

Passes additional data used to process the request. This parameter can be a combination of the following values.

#### DS_REPMOD_ASYNCHRONOUS_OPERATION

Performs this operation asynchronously.

#### DS_REPMOD_WRITEABLE

Indicates that the replica being modified can be written to.

##### - ModifyFields.DS_REPMOD_UPDATE_ADDRESS

Updates the address associated with the referenced server.

##### - ModifyFields.DS_REPMOD_UPDATE_FLAGS

Updates the flags associated with the replica.

##### - ModifyFields.DS_REPMOD_UPDATE_RESULT

Not used. Specifying updates of result values is not currently supported. Result values default to 0.

##### - ModifyFields.DS_REPMOD_UPDATE_SCHEDULE

Updates the periodic replication schedule associated with the replica.

##### - ModifyFields.DS_REPMOD_UPDATE_TRANSPORT

Updates the transport associated with the replica.

##### - Options.DS_REPMOD_ASYNCHRONOUS_OPERATION

Performs this operation asynchronously.

##### - Options.DS_REPMOD_WRITEABLE

Indicates that the replica being modified can be written to.

##### - ReplicaFlags.DS_REPL_NBR_COMPRESS_CHANGES

Changes received from this source are to be compressed. This is normally set if, and only if, the source server is in a different site.

##### - ReplicaFlags.DS_REPL_NBR_DISABLE_SCHEDULED_SYNC

This neighbor is set to not perform synchronization based on its schedule. The only way this neighbor will perform synchronization is in response to change notifications or to manually requested synchronization.

##### - ReplicaFlags.DS_REPL_NBR_DO_SCHEDULED_SYNCS

Perform replication on a schedule. This flag is normally set unless the schedule for this naming context and source is "never", that is, the empty schedule.

##### - ReplicaFlags.DS_REPL_NBR_IGNORE_CHANGE_NOTIFICATIONS

This neighbor is set to disable notification-based synchronization. Within a site, domain controllers synchronize with each other based on notifications when changes occur. This setting prevents this neighbor from performing a synchronization triggered by a notification. The neighbor will still do synchronization based on its schedule or in response to manually requested synchronization.

##### - ReplicaFlags.DS_REPL_NBR_NO_CHANGE_NOTIFICATIONS

No change notifications should be received from this source. This is normally set if, and only if, the source server is in a different site.

##### - ReplicaFlags.DS_REPL_NBR_SYNC_ON_STARTUP

Replication of this naming context from this source is attempted when the destination server is booted. This normally only applies to intra-site neighbors.

##### - ReplicaFlags.DS_REPL_NBR_TWO_WAY_SYNC

If set, indicates that when inbound replication is complete, the destination server must tell the source server to synchronize in the reverse direction. This feature is used in dial-up scenarios where only one of the two servers can initiate a dial-up connection. For example, this option would be used in a corporate headquarters and branch office, where the branch office connects to the corporate headquarters over the Internet by means of a dial-up ISP connection.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value can be one of the following.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsReplicaAdd](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaadda)

[DsReplicaDel](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicadela)

[DsReplicaSync](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasynca)

[DsReplicaUpdateRefs](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaupdaterefsa)

[SCHEDULE](https://learn.microsoft.com/windows/desktop/api/schedule/ns-schedule-schedule)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsReplicaModify as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).