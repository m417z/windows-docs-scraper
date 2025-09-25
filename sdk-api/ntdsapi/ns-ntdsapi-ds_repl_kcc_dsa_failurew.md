# DS_REPL_KCC_DSA_FAILUREW structure

## Description

The **DS_REPL_KCC_DSA_FAILURE** structure contains replication state data about a specific inbound replication partner, as returned by the
[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) and [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) function. This state data is compiled and used by the Knowledge Consistency Checker (KCC) to decide when alternate replication routes must be added to account for unreachable servers.

## Members

### `pszDsaDN`

Pointer to a null-terminated string that contains the distinguished name of the directory system agent object in the directory that corresponds to the source server.

### `uuidDsaObjGuid`

Contains the **objectGuid** of the directory system agent object represented by the **pszDsaDN** member.

### `ftimeFirstFailure`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure which the contents of depends on the value passed for the *InfoType* parameter when [DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow) or [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) function was called.

#### DS_REPL_INFO_KCC_DSA_CONNECT_FAILURES

Contains the date and time that the first failure occurred when replicating from the source server.

#### DS_REPL_INFO_KCC_DSA_LINK_FAILURES

Contains the date and time of the last successful replication.

### `cNumFailures`

Contains the number of consecutive failures since the last successful replication.

### `dwLastResult`

Contains the error code associated with the most recent failure, or **ERROR_SUCCESS** if the specific error is unavailable.

## See also

[DS_REPL_KCC_DSA_FAILURES](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_kcc_dsa_failuresw)

[DsReplicaGetInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfow)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)