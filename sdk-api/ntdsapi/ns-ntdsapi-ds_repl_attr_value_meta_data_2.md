# DS_REPL_ATTR_VALUE_META_DATA_2 structure

## Description

The **DS_REPL_ATTR_VALUE_META_DATA_2** structure is used with the [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) function to provide metadata for a collection of attribute values.

## Members

### `cNumEntries`

Contains the number of elements in the **rgMetaData** array.

### `dwEnumerationContext`

Contains the zero-based index of the next entry to retrieve if more entries are available. This value is passed for the *dwEnumerationContext* parameter in the next call to [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) to retrieve the next block of entries. If no more entries are available, this member contains -1.

### `rgMetaData.size_is`

### `rgMetaData.size_is.cNumEntries`

### `rgMetaData`

Contains an array of [DS_REPL_VALUE_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_value_meta_data_2) structures that contain the individual attribute replication values. The **cNumEntries** member contains the number of elements in this array.

## See also

[DS_REPL_VALUE_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_value_meta_data_2)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)