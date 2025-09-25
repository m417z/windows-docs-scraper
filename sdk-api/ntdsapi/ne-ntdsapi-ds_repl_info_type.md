# DS_REPL_INFO_TYPE enumeration

## Description

The **DS_REPL_INFO_TYPE** enumeration is used with the [DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) and [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) functions to specify the type of replication data to retrieve.

## Constants

### `DS_REPL_INFO_NEIGHBORS:0`

Requests replication state data for naming context and source server pairs. Returns a pointer to a
[DS_REPL_NEIGHBORS](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_neighborsw) structure.

### `DS_REPL_INFO_CURSORS_FOR_NC:1`

Requests replication state data with respect to all replicas of a given naming context. Returns a pointer to a
[DS_REPL_CURSORS](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursors) structure.

### `DS_REPL_INFO_METADATA_FOR_OBJ:2`

Requests replication state data for the attributes for the given object. Returns a pointer to a
[DS_REPL_OBJ_META_DATA](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_obj_meta_data) structure.

### `DS_REPL_INFO_KCC_DSA_CONNECT_FAILURES:3`

Requests replication state data with respect to connection failures between inbound replication partners. Returns a pointer to a
[DS_REPL_KCC_DSA_FAILURES](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_kcc_dsa_failuresw) structure.

### `DS_REPL_INFO_KCC_DSA_LINK_FAILURES:4`

Requests replication state data with respect to link failures between inbound replication partners. Returns a pointer to a
[DS_REPL_KCC_DSA_FAILURES](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_kcc_dsa_failuresw) structure.

### `DS_REPL_INFO_PENDING_OPS:5`

Requests the replication tasks currently executing or queued to execute. Returns a pointer to a
[DS_REPL_PENDING_OPS](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_pending_opsw) structure.

### `DS_REPL_INFO_METADATA_FOR_ATTR_VALUE:6`

Requests replication state data for a specific attribute for the given object. Returns a pointer to a
[DS_REPL_ATTR_VALUE_META_DATA](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_value_meta_data) structure.

### `DS_REPL_INFO_CURSORS_2_FOR_NC:7`

Requests replication state data with respect to all replicas of a given naming context. Returns a pointer to a
[DS_REPL_CURSORS_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursors_2) structure.

### `DS_REPL_INFO_CURSORS_3_FOR_NC:8`

Requests replication state data with respect to all replicas of a given naming context. Returns a pointer to a
[DS_REPL_CURSORS_3](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursors_3w) structure.

### `DS_REPL_INFO_METADATA_2_FOR_OBJ:9`

Requests replication state data for the attributes for the given object. Returns a pointer to a
[DS_REPL_OBJ_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_obj_meta_data_2) structure.

### `DS_REPL_INFO_METADATA_2_FOR_ATTR_VALUE:10`

Requests replication state data for a specific attribute for the given object. Returns a pointer to a
[DS_REPL_ATTR_VALUE_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_value_meta_data_2) structure.

### `DS_REPL_INFO_METADATA_EXT_FOR_ATTR_VALUE:11`

### `DS_REPL_INFO_TYPE_MAX`

## See also

[DS_REPL_ATTR_VALUE_META_DATA](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_meta_data)

[DS_REPL_ATTR_VALUE_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_attr_meta_data_2)

[DS_REPL_CURSORS](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursors)

[DS_REPL_CURSORS_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursors_2)

[DS_REPL_CURSORS_3](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_cursors_3w)

[DS_REPL_KCC_DSA_FAILURES](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_kcc_dsa_failuresw)

[DS_REPL_NEIGHBORS](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_neighborsw)

[DS_REPL_OBJ_META_DATA](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_obj_meta_data)

[DS_REPL_OBJ_META_DATA_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_obj_meta_data_2)

[DS_REPL_PENDING_OPS](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_pending_opsw)

[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)

[Enumerations in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/enumerations-in-active-directory-domain-services)