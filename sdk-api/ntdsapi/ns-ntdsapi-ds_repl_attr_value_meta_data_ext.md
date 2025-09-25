# DS_REPL_ATTR_VALUE_META_DATA_EXT structure

## Description

Provides metadata for a collection of attribute replication values.

## Members

### `cNumEntries`

The number of elements in the **rgMetaData** array.

### `dwEnumerationContext`

The zero-based index of the next entry to retrieve if more entries are available. This value is passed for
the *dwEnumerationContext* parameter in the next call to
[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) to retrieve the next block of
entries. If no more entries are available, this member contains -1.

### `rgMetaData.size_is`

### `rgMetaData.size_is.cNumEntries`

### `rgMetaData`

An array of [DS_REPL_VALUE_META_DATA_EXT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_value_meta_data_ext)
structures that contain the attribute replication values. The **cNumEntries** member
contains the number of elements in this array.

An array of [DS_REPL_VALUE_META_DATA_EXT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_value_meta_data_ext)
structures that contain the attribute replication values. The **cNumEntries** member
contains the number of elements in this array.

## See also

[DS_REPL_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_repl_info_type)

[Domain Controller and Replication Management Structures](https://learn.microsoft.com/windows/desktop/AD/domain-controller-and-replication-management-structures)