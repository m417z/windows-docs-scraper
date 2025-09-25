# STAT_SERVER_0 structure

## Description

Contains statistical information about the server.

## Members

### `sts0_start`

Specifies a DWORD value that indicates the time when statistics collection started (or when the statistics were last cleared). The value is stored as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT. To calculate the length of time that statistics have been collected, subtract the value of this member from the present time.

### `sts0_fopens`

Specifies a DWORD value that indicates the number of times a file is opened on a server. This includes the number of times named pipes are opened.

### `sts0_devopens`

Specifies a DWORD value that indicates the number of times a server device is opened.

### `sts0_jobsqueued`

Specifies a DWORD value that indicates the number of server print jobs spooled.

### `sts0_sopens`

Specifies a DWORD value that indicates the number of times the server session started.

### `sts0_stimedout`

Specifies a DWORD value that indicates the number of times the server session automatically disconnected.

### `sts0_serrorout`

Specifies a DWORD value that indicates the number of times the server sessions failed with an error.

### `sts0_pwerrors`

Specifies a DWORD value that indicates the number of server password violations.

### `sts0_permerrors`

Specifies a DWORD value that indicates the number of server access permission errors.

### `sts0_syserrors`

Specifies a DWORD value that indicates the number of server system errors.

### `sts0_bytessent_low`

Specifies the low-order DWORD of the number of server bytes sent to the network.

### `sts0_bytessent_high`

Specifies the high-order DWORD of the number of server bytes sent to the network.

### `sts0_bytesrcvd_low`

Specifies the low-order DWORD of the number of server bytes received from the network.

### `sts0_bytesrcvd_high`

Specifies the high-order DWORD of the number of server bytes received from the network.

### `sts0_avresponse`

Specifies a DWORD value that indicates the average server response time (in milliseconds).

### `sts0_reqbufneed`

Specifies a DWORD value that indicates the number of times the server required a request buffer but failed to allocate one. This value indicates that the server parameters may need adjustment.

### `sts0_bigbufneed`

Specifies a DWORD value that indicates the number of times the server required a big buffer but failed to allocate one. This value indicates that the server parameters may need adjustment.

## See also

[NetStatisticsGet](https://learn.microsoft.com/windows/desktop/api/lmstats/nf-lmstats-netstatisticsget)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Statistics Functions](https://learn.microsoft.com/windows/desktop/NetShare/statistics-functions)