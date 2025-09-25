# DS_REPL_NEIGHBORW structure

## Description

The **DS_REPL_NEIGHBOR** structure contains inbound replication state data for a particular naming context and source server pair, as returned by the
[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) and [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) functions.

## Members

### `pszNamingContext`

Pointer to a null-terminated string that contains the naming context to which this replication state data pertains. Each naming context is replicated independently and has different associated neighbor data, even if the naming contexts are replicated from the same source server.

### `pszSourceDsaDN`

Pointer to a null-terminated string that contains the distinguished name of the directory service agent corresponding to the source server to which this replication state data pertains. Each source server has different associated neighbor data.

### `pszSourceDsaAddress`

Pointer to a null-terminated string that contains the transport-specific network address of the source server. That is, a directory name service name for RPC/IP replication, or an SMTP address for an SMTP replication.

### `pszAsyncIntersiteTransportDN`

Pointer to a null-terminated string that contains the distinguished name of the **interSiteTransport** object that corresponds to the transport over which replication is performed. This member contains **NULL** for RPC/IP replication.

### `dwReplicaFlags`

Contains a set of flags that specify attributes and options for the replication data. This can be zero or a combination of one or more of the following flags.

#### DS_REPL_NBR_WRITEABLE (16 (0x10))

The local copy of the naming context is writable.

#### DS_REPL_NBR_SYNC_ON_STARTUP (32 (0x20))

Replication of this naming context from this source is attempted when the destination server is booted. This normally only applies to intra-site neighbors.

#### DS_REPL_NBR_DO_SCHEDULED_SYNCS (64 (0x40))

Perform replication on a schedule. This flag is normally set unless the schedule for this naming context/source is "never", that is, the empty schedule.

#### DS_REPL_NBR_USE_ASYNC_INTERSITE_TRANSPORT (128 (0x80))

Perform replication indirectly through the Inter-Site Messaging Service. This flag is set only when replicating over SMTP. This flag is not set when replicating over inter-site RPC/IP.

#### DS_REPL_NBR_TWO_WAY_SYNC (512 (0x200))

If set, indicates that when inbound replication is complete, the destination server must tell the source server to synchronize in the reverse direction. This feature is used in dial-up scenarios where only one of the two servers can initiate a dial-up connection. For example, this option would be used in a corporate headquarters and branch office, where the branch office connects to the corporate headquarters over the Internet by means of a dial-up ISP connection.

#### DS_REPL_NBR_RETURN_OBJECT_PARENTS (2048 (0x800))

This neighbor is in a state where it returns parent objects before children objects. It goes into this state after it receives a child object before its parent.

#### DS_REPL_NBR_FULL_SYNC_IN_PROGRESS (65536 (0x10000))

The destination server is performing a full synchronization from the source server. Full synchronizations do not use vectors that create updates ([DS_REPL_CURSORS](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursors)) for filtering updates. Full synchronizations are not used as a part of the normal replication protocol.

#### DS_REPL_NBR_FULL_SYNC_NEXT_PACKET (131072 (0x20000))

The last packet from the source indicated a modification of an object that the destination server has not yet created. The next packet to be requested instructs the source server to put all attributes of the modified object into the packet.

#### DS_REPL_NBR_NEVER_SYNCED (2097152 (0x200000))

A synchronization has never been successfully completed from this source.

#### DS_REPL_NBR_PREEMPTED (16777216 (0x1000000))

The replication engine has temporarily stopped processing this neighbor in order to service another higher-priority neighbor, either for this partition or for another partition. The replication engine will resume processing this neighbor after the higher-priority work is completed.

#### DS_REPL_NBR_IGNORE_CHANGE_NOTIFICATIONS (67108864 (0x4000000))

This neighbor is set to disable notification-based synchronizations. Within a site, domain controllers synchronize with each other based on notifications when changes occur. This setting prevents this neighbor from performing syncs that are triggered by notifications. The neighbor will still do synchronizations based on its schedule, or in response to manually requested synchronizations.

#### DS_REPL_NBR_DISABLE_SCHEDULED_SYNC (134217728 (0x8000000))

This neighbor is set to not perform synchronizations based on its schedule. The only way this neighbor will perform synchronizations is in response to change notifications or to manually requested synchronizations.

#### DS_REPL_NBR_COMPRESS_CHANGES (268435456 (0x10000000))

Changes received from this source are to be compressed. This is normally set if, and only if, the source server is in a different site.

#### DS_REPL_NBR_NO_CHANGE_NOTIFICATIONS (536870912 (0x20000000))

No change notifications should be received from this source. Normally set if, and only if, the source server is in a different site.

#### DS_REPL_NBR_PARTIAL_ATTRIBUTE_SET (1073741824 (0x40000000))

This neighbor is in a state where it is rebuilding the contents of this replica because of a change in the partial attribute set.

### `dwReserved`

Reserved for future use.

### `uuidNamingContextObjGuid`

Contains the **objectGuid** of the naming context corresponding to **pszNamingContext**.

### `uuidSourceDsaObjGuid`

Contains the **objectGuid** of the **nTDSDSA** object corresponding to **pszSourceDsaDN**.

### `uuidSourceDsaInvocationID`

Contains the invocation identifier used by the source server as of the last replication attempt.

### `uuidAsyncIntersiteTransportObjGuid`

Contains the **objectGuid** of the inter-site transport object corresponding to **pszAsyncIntersiteTransportDN**.

### `usnLastObjChangeSynced`

Contains the update sequence number of the last object update received.

### `usnAttributeFilter`

Contains the **usnLastObjChangeSynced** value at the end of the last complete, successful replication cycle, or 0 if none. Attributes at the source last updated at a update sequence number less than or equal to this value have already been received and applied by the destination.

### `ftimeLastSyncSuccess`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time the last successful replication cycle was completed from this source. All members of this structure are zero if the replication cycle has never been completed.

### `ftimeLastSyncAttempt`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time of the last replication attempt from this source. All members of this structure are zero if the replication has never been attempted.

### `dwLastSyncResult`

Contains an error code associated with the last replication attempt from this source. Contains **ERROR_SUCCESS** if the last attempt succeeded.

### `cNumConsecutiveSyncFailures`

Contains the number of failed replication attempts from this source since the last successful replication attempt - or since the source was added as a neighbor, if no previous attempt was successful.

## See also

[DS_REPL_NEIGHBORS](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_neighborsw)

[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)