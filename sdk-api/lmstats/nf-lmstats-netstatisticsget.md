# NetStatisticsGet function

## Description

Retrieves operating statistics for a service. Currently, only the workstation and server services are supported.

## Parameters

### `ServerName` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `Service` [in]

Pointer to a string that specifies the name of the service about which to get the statistics. Only the values **SERVICE_SERVER** and **SERVICE_WORKSTATION** are currently allowed.

### `Level` [in]

Specifies the information level of the data. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **0** | Return statistics about a workstation or a server. The *bufptr* parameter points to a [STAT_WORKSTATION_0](https://learn.microsoft.com/windows/win32/api/lmstats/ns-lmstats-stat_workstation_0~r1) or a [STAT_SERVER_0](https://learn.microsoft.com/windows/desktop/api/lmstats/ns-lmstats-stat_server_0) structure. |

### `Options` [in]

This parameter must be zero.

### `Buffer` [out]

Pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

No special group membership is required to obtain workstation statistics. Only members of the Administrators or Server Operators local group can successfully execute the
**NetStatisticsGet** function on a remote server.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[STAT_SERVER_0](https://learn.microsoft.com/windows/desktop/api/lmstats/ns-lmstats-stat_server_0)

[STAT_WORKSTATION_0](https://learn.microsoft.com/windows/win32/api/lmstats/ns-lmstats-stat_workstation_0~r1)

[Statistics
Functions](https://learn.microsoft.com/windows/desktop/NetShare/statistics-functions)