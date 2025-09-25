# DS_REPL_ATTR_META_DATA_BLOB structure

## Description

The **DS_REPL_ATTR_META_DATA_BLOB** structure is used to contain replication state data for an object attribute. This structure is similar to the [DS_REPL_ATTR_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_meta_data_2) structure, but is obtained from the [Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api) functions when obtaining binary data for the **msDS-ReplAttributeMetaData** attribute.

## Members

### `oszAttributeName`

Contains the offset, in bytes, from the address of this structure to a null-terminated Unicode string that contains the LDAP display name of the attribute corresponding to this metadata. A value of zero indicates an empty or **NULL** string.

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

### `oszLastOriginatingDsaDN`

Contains the offset, in bytes, from the address of this structure to a null-terminated Unicode string that contains the distinguished name of the directory system agent server that originated the last replication. A value of zero indicates an empty or **NULL** string.

## See also

[DS_REPL_ATTR_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_meta_data_2)

[Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api)