# DS_REPSYNCALL_SYNCW structure

## Description

The **DS_REPSYNCALL_SYNC** structure identifies a single replication operation performed between a source, and destination, server by the
[DsReplicaSyncAll](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasyncalla) function.

## Members

### `pszSrcId`

Pointer to a null-terminated string that specifies the DNS GUID of the source server.

### `pszDstId`

Pointer to a null-terminated string that specifies the DNS GUID of the destination server.

### `pszNC`

### `pguidSrc`

### `pguidDst`

## See also

[DS_REPSYNCALL_UPDATE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repsyncall_updatea)

[Domain Controller and Replication Management Structures](https://learn.microsoft.com/windows/desktop/AD/domain-controller-and-replication-management-structures)

[DsReplicaSyncAll](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasyncalla)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DS_REPSYNCALL_SYNC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).