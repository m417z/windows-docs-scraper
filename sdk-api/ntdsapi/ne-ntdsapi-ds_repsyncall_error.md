# DS_REPSYNCALL_ERROR enumeration

## Description

The **DS_REPSYNCALL_ERROR** enumeration is used with the [DS_REPSYNCALL_ERRINFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_errinfoa) structure to indicate where in the replication process an error occurred.

## Constants

### `DS_REPSYNCALL_WIN32_ERROR_CONTACTING_SERVER:0`

The server referred to by the **pszSvrId** member of the [DS_REPSYNCALL_ERRINFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_errinfoa) structure cannot be contacted.

### `DS_REPSYNCALL_WIN32_ERROR_REPLICATING:1`

An error occurred during replication of the server identified by the **pszSvrId** member of the [DS_REPSYNCALL_ERRINFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_errinfoa) structure.

### `DS_REPSYNCALL_SERVER_UNREACHABLE:2`

The server identified by the **pszSvrId** member of the [DS_REPSYNCALL_ERRINFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_errinfoa) structure cannot be contacted.

## See also

[DS_REPSYNCALL_ERRINFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_errinfoa)

[DsReplicaSyncAll](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasyncalla)