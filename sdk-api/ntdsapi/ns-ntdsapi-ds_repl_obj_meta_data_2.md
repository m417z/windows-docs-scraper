# DS_REPL_OBJ_META_DATA_2 structure

## Description

The **DS_REPL_OBJ_META_DATA_2** structure contains an array of [DS_REPL_ATTR_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_meta_data_2) structures, which in turn contain replication state data for the attributes (past and present) for a given object, as returned by the
[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) function. This structure is an enhanced version of the [DS_REPL_OBJ_META_DATA](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_obj_meta_data) structure.

## Members

### `cNumEntries`

Contains the number of elements in the **rgMetaData** array.

### `dwReserved`

Not used.

### `rgMetaData.size_is`

### `rgMetaData.size_is.cNumEntries`

### `rgMetaData`

Contains an array of [DS_REPL_ATTR_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_meta_data_2) structures. The **cNumEntries** member contains the number of elements in this array.

## See also

[DS_REPL_ATTR_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_meta_data_2)

[DS_REPL_OBJ_META_DATA](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_obj_meta_data)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)