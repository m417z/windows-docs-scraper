# DS_REPL_OBJ_META_DATA structure

## Description

The **DS_REPL_OBJ_META_DATA** structure contains an array of [DS_REPL_ATTR_META_DATA](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_meta_data) structures. These structures contain replication state data for past and present attributes for a given object. The replication state data is returned from the
[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) and [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) functions. The metadata records data about the last modification of a given object attribute.

## Members

### `cNumEntries`

Contains the number of elements in the **rgMetaData** array.

### `dwReserved`

Not used.

### `rgMetaData.size_is`

### `rgMetaData.size_is.cNumEntries`

### `rgMetaData`

Contains an array of [DS_REPL_ATTR_META_DATA](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_meta_data) structures. The **cNumEntries** member contains the number of elements in this array.

## See also

[DS_REPL_ATTR_META_DATA](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_meta_data)

[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)