# DS_REPL_KCC_DSA_FAILURESW structure

## Description

The **DS_REPL_KCC_DSA_FAILURES** structure contains an array of [DS_REPL_KCC_DSA_FAILURE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_kcc_dsa_failurew) structures, which in turn contain replication state data with respect to inbound replication partners, as returned by the
[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) and [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) functions.

## Members

### `cNumEntries`

Contains the number of elements in the **rgMetaData** array.

### `dwReserved`

Reserved for future use.

### `rgDsaFailure.size_is`

### `rgDsaFailure.size_is.cNumEntries`

### `rgDsaFailure`

Contains an array of [DS_REPL_KCC_DSA_FAILURE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_kcc_dsa_failurew) structures that contain the requested replication data. The **cNumEntries** member contains the number of elements in this array.

## See also

[DS_REPL_KCC_DSA_FAILURE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_kcc_dsa_failurew)

[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)