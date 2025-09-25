# DS_REPL_VALUE_META_DATA_EXT structure

## Description

Contains attribute replication meta data for the [DS_REPL_ATTR_VALUE_META_DATA_EXT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_value_meta_data_ext) structure.

## Members

### `pszAttributeName`

Pointer to a null-terminated Unicode string that contains the LDAP display name of the attribute corresponding to this metadata.

### `pszObjectDn`

Pointer to a null-terminated Unicode string that contains the distinguished name of the object that this attribute belongs to.

### `cbData`

Contains the number of bytes in the **pbData** array.

### `pbData.size_is`

### `pbData.size_is.cbData`

### `pbData.ptr`

### `pbData`

Pointer to a buffer that contains the attribute replication metadata. The **cbData** member contains the length, in bytes, of this buffer.

Pointer to a buffer that contains the attribute replication metadata. The **cbData** member contains the length, in bytes, of this buffer.

### `ftimeDeleted`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time this attribute was deleted.

### `ftimeCreated`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time this attribute was created.

### `dwVersion`

Contains the version of this attribute. Each originating modification of the attribute increases this value by one. Replication of a modification does not affect the version.

### `ftimeLastOriginatingChange`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time at which the last originating change was made to this attribute. Replication of the change does not affect this value.

### `uuidLastOriginatingDsaInvocationID`

Contains the invocation identifier of the server on which the last change was made to this attribute. Replication of the change does not affect this value.

### `usnOriginatingChange`

Contains the update sequence number (USN) on the originating server at which the last change to this attribute was made. Replication of the change does not affect this value.

### `usnLocalChange`

Contains the USN on the destination server, that is the server from which the [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) function retrieved the metadata, at which the last change to this attribute was applied. This value is typically different on all servers.

### `pszLastOriginatingDsaDN`

Pointer to a null-terminated Unicode string that contains the distinguished name of the directory system agent server that originated the last replication.

### `dwUserIdentifier`

TBD

### `dwPriorLinkState`

TBD

### `dwCurrentLinkState`

TBD