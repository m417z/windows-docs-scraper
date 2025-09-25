# DS_REPL_VALUE_META_DATA_BLOB structure

## Description

The **DS_REPL_VALUE_META_DATA_BLOB** structure is used to contain attribute value replication metadata. This structure is similar to the [DS_REPL_VALUE_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_value_meta_data_2) structure, but is obtained from the [Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api) functions when obtaining binary data for the **msDS-ReplValueMetaData** attribute.

## Members

### `oszAttributeName`

Contains the offset, in bytes, from the address of this structure to a null-terminated Unicode string that contains the LDAP display name of the attribute corresponding to this metadata. A value of zero indicates an empty or **NULL** string.

### `oszObjectDn`

Contains the offset, in bytes, from the address of this structure to a null-terminated Unicode string that contains the distinguished name of the object that this attribute belongs to. A value of zero indicates an empty or **NULL** string.

### `cbData`

Contains the number of bytes in the **pbData** array.

### `obData`

Pointer to a buffer that contains the attribute replication metadata. The **cbData** member contains the length, in bytes, of this buffer.

### `ftimeDeleted`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time that this attribute was deleted.

### `ftimeCreated`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time that this attribute was created.

### `dwVersion`

Contains the version of this attribute. Each originating modification of the attribute increases this value by one. Replication of a modification does not affect the version.

### `ftimeLastOriginatingChange`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time at which the last originating change was made to this attribute. Replication of the change does not affect this value.

### `uuidLastOriginatingDsaInvocationID`

Contains the invocation identifier of the server on which the last change was made to this attribute. Replication of the change does not affect this value.

### `usnOriginatingChange`

Contains the update sequence number (USN) on the originating server at which the last change to this attribute was made. Replication of the change does not affect this value.

### `usnLocalChange`

Contains the USN on the destination server, that is, the server from which the [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) function retrieved the metadata, at which the last change to this attribute was applied. This value is typically different on all servers.

### `oszLastOriginatingDsaDN`

Contains the offset, in bytes, from the address of this structure to a null-terminated Unicode string that contains the distinguished name of the directory system agent server that originated the last replication. A value of zero indicates an empty or **NULL** string.

## See also

[DS_REPL_VALUE_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_value_meta_data_2)

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api)