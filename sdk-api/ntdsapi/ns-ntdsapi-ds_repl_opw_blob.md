# DS_REPL_OPW_BLOB structure

## Description

The **DS_REPL_OPW_BLOB** structure describes a replication task currently executing or pending execution. This structure is similar to the [DS_REPL_OP](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_opw) structure, but is obtained from the [Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api) functions when obtaining binary data for the **msDS-ReplPendingOps** attribute.

## Members

### `ftimeEnqueued`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time that this operation was added to the queue.

### `ulSerialNumber`

Contains the identifier of the operation. This value is unique in the startup routine of every computer. When the computer is restarted, the identifiers are no longer unique.

### `ulPriority`

Contains the priority value of this operation. Tasks with a higher priority value are executed first. The priority is calculated by the server based on the type of operation and its parameters.

### `OpType`

Contains one of the [DS_REPL_OP_TYPE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_repl_op_type) values that indicate the type of operation that this structure represents.

### `ulOptions`

Zero or more bits, the interpretation of which depends on the **OpType**. For **DS_REPL_OP_TYPE_SYNC**, the bits should be interpreted as **DS_REPSYNC_***. **ADD**, **DELETE**, **MODIFY**, and **UPDATE_REFS** use **DS_REPADD_***, **DS_REPDEL_***, **DS_REPMOD_***, and **DS_REPUPD_***. For more information, and descriptions of these bits, see
[DsReplicaSync](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasynca),
[DsReplicaAdd](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaadda),
[DsReplicaDel](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicadela),
[DsReplicaModify](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicamodifya), and
[DsReplicaUpdateRefs](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaupdaterefsa).

Contains a set of flags that provide additional data about the operation. The contents of this member is determined by the contents of the **OpType** member.

This list describes the contents of the *ulOptions* parameter for each *OpType* value.

#### DS_REPL_OP_TYPE_SYNC

Contains zero or a combination of one or more of the **DS_REPSYNC_*** values as defined for the *Options* parameter in [DsReplicaSync](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasynca).

#### DS_REPL_OP_TYPE_ADD

Contains zero or a combination of one or more of the **DS_REPADD_*** values as defined for the *Options* parameter in [DsReplicaAdd](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaadda).

#### DS_REPL_OP_TYPE_DELETE

Contains zero or a combination of one or more of the **DS_REPDEL_*** values as defined for the *Options* parameter in [DsReplicaDel](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicadela).

#### DS_REPL_OP_TYPE_MODIFY

Contains zero or a combination of one or more of the **DS_REPMOD_*** values as defined for the *Options* parameter in [DsReplicaModify](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicamodifya).

#### DS_REPL_OP_TYPE_UPDATE_REFS

Contains zero or a combination of one or more of the **DS_REPSUPD_*** values as defined for the *Options* parameter in [DsReplicaUpdateRefs](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaupdaterefsa).

### `oszNamingContext`

Contains the offset, in bytes, from the address of this structure to a null-terminated string that contains the distinguished name of the naming context associated with this operation. For example, the naming context to be synchronized for **DS_REPL_OP_TYPE_SYNC**.

### `oszDsaDN`

Contains the offset, in bytes, from the address of this structure to a null-terminated string that contains the distinguished name of the directory system agent object associated with the remote server corresponding to this operation. For example, the server from which to ask for changes for **DS_REPL_OP_TYPE_SYNC**. This can be **NULL**.

### `oszDsaAddress`

Contains the offset, in bytes, from the address of this structure to a null-terminated string that contains the transport-specific network address of the remote server associated with this operation. For example, the DNS or SMTP address of the server from which to ask for changes for **DS_REPL_OP_TYPE_SYNC**. This can be **NULL**.

### `uuidNamingContextObjGuid`

Contains the **objectGuid** of the naming context identified by **pszNamingContext**.

### `uuidDsaObjGuid`

Contains the **objectGuid** of the directory system agent object identified by **pszDsaDN**.

## See also

[DS_REPL_OP](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_opw)

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api)