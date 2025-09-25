# DS_REPL_ATTR_META_DATA_2 structure

## Description

The **DS_REPL_ATTR_META_DATA_2** structure is used with the [DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) and [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) functions to contain replication state data for an object attribute.

## Members

### `pszAttributeName`

Pointer to a null-terminated Unicode string that contains the LDAP display name of the attribute that corresponds to this metadata.

### `dwVersion`

Contains the version of this attribute. Each originating modification of the attribute increases this value by one. Replication of a modification does not affect the version.

### `ftimeLastOriginatingChange`

Contains the time at which the last originating change was made to this attribute. Replication of the change does not affect this value.

### `uuidLastOriginatingDsaInvocationID`

Contains the invocation identification of the server on which the last change was made to this attribute. Replication of the change does not affect this value.

### `usnOriginatingChange`

Contains the update sequence number (USN) on the originating server at which the last change to this attribute was made. Replication of the change does not affect this value.

### `usnLocalChange`

Contains the USN on the destination server (the server from which the [DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) function retrieved the metadata) at which the last change to this attribute was applied. This value typically is different on all servers.

### `pszLastOriginatingDsaDN`

Pointer to a null-terminated Unicode string that contains the distinguished name of the directory system agent server that originated the last replication.

## See also

[DS_REPL_OBJ_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_obj_meta_data_2)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)