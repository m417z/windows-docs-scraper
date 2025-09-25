# DS_REPL_NEIGHBORW_BLOB structure

## Description

The **DS_REPL_NEIGHBORW_BLOB** structure contains inbound replication state data for a particular naming context and source server pair. This structure is similar to the [DS_REPL_NEIGHBOR](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_neighborw) structure, but is obtained from the [Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api) functions when obtaining binary data for the **msDS-NCReplInboundNeighbors** attribute.

## Members

### `oszNamingContext`

Contains the offset, in bytes, from the address of this structure to a null-terminated Unicode string that contains the naming context to which this replication state data pertains. Each naming context is replicated independently and has different associated neighbor data, even if the naming contexts are replicated from the same source server.

### `oszSourceDsaDN`

Contains the offset, in bytes, from the address of this structure to a null-terminated Unicode string that contains the distinguished name of the directory service agent corresponding to the source server to which this replication state data pertains. Each source server has different associated neighbor data.

### `oszSourceDsaAddress`

Contains the offset, in bytes, from the address of this structure to a null-terminated Unicode string that contains the transport-specific network address of the source server. That is, a directory name service name for RPC/IP replication, or an SMTP address for an SMTP replication.

### `oszAsyncIntersiteTransportDN`

Contains the offset, in bytes, from the address of this structure to a null-terminated Unicode string that contains the distinguished name of the **interSiteTransport** object that corresponds to the transport over which replication is performed. This member contains **NULL** for RPC/IP replication.

### `dwReplicaFlags`

Contains a set of flags that specify attributes and options for the replication data. This can be zero or a combination of one or more of the following flags.

#### DS_REPL_NBR_WRITEABLE

The local copy of the naming context is writable.

#### DS_REPL_NBR_SYNC_ON_STARTUP

Replication of this naming context from this source is attempted when the destination server is booted. This normally only applies to intra-site neighbors.

#### DS_REPL_NBR_DO_SCHEDULED_SYNCS

Perform replication on a schedule. This flag is normally set unless the schedule for this naming context/source is "never", that is, the empty schedule.

#### DS_REPL_NBR_USE_ASYNC_INTERSITE_TRANSPORT

Perform replication indirectly through the Inter-Site Messaging Service. This flag is set only when replicating over SMTP. This flag is not set when replicating over inter-site RPC/IP.

#### DS_REPL_NBR_TWO_WAY_SYNC

If set, indicates that when inbound replication is complete, the destination server must tell the source server to synchronize in the reverse direction. This feature is used in dial-up scenarios where only one of the two servers can initiate a dial-up connection. For example, this option would be used in a corporate headquarters and branch office, where the branch office connects to the corporate headquarters over the Internet by means of a dial-up ISP connection.

#### DS_REPL_NBR_FULL_SYNC_IN_PROGRESS

The destination server is performing a full synchronization from the source server. Full synchronizations do not use vectors that create updates ([DS_REPL_CURSORS](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursors)) for filtering updates. Full synchronizations are not used as a part of the normal replication protocol.

#### DS_REPL_NBR_FULL_SYNC_NEXT_PACKET

The last packet from the source indicated a modification of an object that the destination server has not yet created. The next packet to be requested instructs the source server to put all attributes of the modified object into the packet.

#### DS_REPL_NBR_NEVER_SYNCED

A synchronization has never been successfully completed from this source.

#### DS_REPL_NBR_COMPRESS_CHANGES

Changes received from this source are to be compressed. This is normally set if, and only if, the source server is in a different site.

#### DS_REPL_NBR_NO_CHANGE_NOTIFICATIONS

No change notifications should be received from this source. Normally set if, and only if, the source server is in a different site.

### `dwReserved`

Reserved for future use.

### `uuidNamingContextObjGuid`

Contains the **objectGuid** of the naming context that corresponds to **pszNamingContext**.

### `uuidSourceDsaObjGuid`

Contains the **objectGuid** of the **nTDSDSA** object that corresponds to **pszSourceDsaDN**.

### `uuidSourceDsaInvocationID`

Contains the invocation identifier used by the source server as of the last replication attempt.

### `uuidAsyncIntersiteTransportObjGuid`

Contains the **objectGuid** of the inter-site transport object that corresponds to **pszAsyncIntersiteTransportDN**.

### `usnLastObjChangeSynced`

Contains the update sequence number of the last object update received.

### `usnAttributeFilter`

Contains the **usnLastObjChangeSynced** value at the end of the last complete, successful replication cycle, or 0 if none. Attributes at the source last updated at a update sequence number less than or equal to this value have already been received and applied by the destination.

### `ftimeLastSyncSuccess`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time the last successful replication cycle was completed from this source. All members of this structure are zero if the replication cycle has never been completed.

### `ftimeLastSyncAttempt`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time of the last replication attempt from this source. All members of this structure are zero if the replication has never been attempted.

### `dwLastSyncResult`

Contains a Windows error code associated with the last replication attempt from this source. Contains **ERROR_SUCCESS** if the last attempt was successful.

### `cNumConsecutiveSyncFailures`

Contains the number of failed replication attempts that have been made from this source since the last successful replication attempt or since the source was added as a neighbor, if no previous attempt succeeded.

## See also

[DS_REPL_NEIGHBOR](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_neighborw)

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api)