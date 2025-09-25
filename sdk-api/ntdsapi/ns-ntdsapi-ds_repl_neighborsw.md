# DS_REPL_NEIGHBORSW structure

## Description

The **DS_REPL_NEIGHBORS** structure is used with the [DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) and [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) functions to provide inbound replication state data for naming context and source server pairs.

## Members

### `cNumNeighbors`

Contains the number of elements in the **rgNeighbor** array.

### `dwReserved`

Reserved for future use.

### `rgNeighbor.size_is`

### `rgNeighbor.size_is.cNumNeighbors`

### `rgNeighbor`

Contains an array of [DS_REPL_NEIGHBOR](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_neighborw) structures that contain the requested replication data. The **cNumNeighbors** member contains the number of elements in this array.

## See also

[DS_REPL_NEIGHBOR](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_neighborw)

[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)