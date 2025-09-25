# DS_REPL_OP_TYPE enumeration

## Description

The **DS_REPL_OP_TYPE** enumeration type is used to indicate the type of replication operation that a given entry in the replication queue represents.

## Constants

### `DS_REPL_OP_TYPE_SYNC:0`

Indicates an inbound replication over an existing replication agreement from a direct replication partner.

### `DS_REPL_OP_TYPE_ADD`

Indicates the addition of a replication agreement for a new direct replication partner.

### `DS_REPL_OP_TYPE_DELETE`

Indicates the removal of a replication agreement for an existing direct replication partner.

### `DS_REPL_OP_TYPE_MODIFY`

Indicates the modification of a replication agreement for an existing direct replication partner.

### `DS_REPL_OP_TYPE_UPDATE_REFS`

Indicates the addition, deletion, or update of outbound change notification data for a direct replication partner.

## See also

[Active Directory Enumerations](https://learn.microsoft.com/windows/desktop/AD/enumerations-in-active-directory-domain-services)

[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)