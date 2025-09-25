# STAT_WORKSTATION_0 structure

## Description

Contains statistical information about the specified workstation.

## Members

### `StatisticsStartTime`

Specifies the time statistics collection started.

This member also indicates when statistics for the workstations were last cleared. The value is stored as the number of seconds elapsed since 00:00:00, January 1, 1970.

### `BytesReceived`

Specifies the total number of bytes received by the workstation.

### `SmbsReceived`

Specifies the total number of server message blocks (SMBs) received by the workstation.

### `PagingReadBytesRequested`

Specifies the total number of bytes that have been read by paging I/O requests.

### `NonPagingReadBytesRequested`

Specifies the total number of bytes that have been read by non-paging I/O requests.

### `CacheReadBytesRequested`

Specifies the total number of bytes that have been read by cache I/O requests.

### `NetworkReadBytesRequested`

Specifies the total amount of bytes that have been read by disk I/O requests.

### `BytesTransmitted`

Specifies the total number of bytes transmitted by the workstation.

### `SmbsTransmitted`

Specifies the total number of SMBs transmitted by the workstation.

### `PagingWriteBytesRequested`

Specifies the total number of bytes that have been written by paging I/O requests.

### `NonPagingWriteBytesRequested`

Specifies the total number of bytes that have been written by non-paging I/O requests.

### `CacheWriteBytesRequested`

Specifies the total number of bytes that have been written by cache I/O requests.

### `NetworkWriteBytesRequested`

Specifies the total number of bytes that have been written by disk I/O requests.

### `InitiallyFailedOperations`

Specifies the total number of network operations that failed to begin.

### `FailedCompletionOperations`

Specifies the total number of network operations that failed to complete.

### `ReadOperations`

Specifies the total number of read operations initiated by the workstation.

### `RandomReadOperations`

Specifies the total number of random access reads initiated by the workstation.

### `ReadSmbs`

Specifies the total number of read requests the workstation has sent to servers.

### `LargeReadSmbs`

Specifies the total number of read requests the workstation has sent to servers that are greater than twice the size of the server's negotiated buffer size.

### `SmallReadSmbs`

Specifies the total number of read requests the workstation has sent to servers that are less than 1/4 of the size of the server's negotiated buffer size.

### `WriteOperations`

Specifies the total number of write operations initiated by the workstation.

### `RandomWriteOperations`

Specifies the total number of random access writes initiated by the workstation.

### `WriteSmbs`

Specifies the total number of write requests the workstation has sent to servers.

### `LargeWriteSmbs`

Specifies the total number of write requests the workstation has sent to servers that are greater than twice the size of the server's negotiated buffer size.

### `SmallWriteSmbs`

Specifies the total number of write requests the workstation has sent to servers that are less than 1/4 of the size of the server's negotiated buffer size.

### `RawReadsDenied`

Specifies the total number of raw read requests made by the workstation that have been denied.

### `RawWritesDenied`

Specifies the total number of raw write requests made by the workstation that have been denied.

### `NetworkErrors`

Specifies the total number of network errors received by the workstation.

### `Sessions`

Specifies the total number of sessions established by the workstation.

### `FailedSessions`

Specifies the number of times the workstation attempted to create a session but failed.

### `Reconnects`

Specifies the total number of connections that have failed.

### `CoreConnects`

Specifies the total number of connections to servers supporting the PCNET dialect that have succeeded.

### `Lanman20Connects`

Specifies the total number of connections to servers supporting the LanManager 2.0 dialect that have succeeded.

### `Lanman21Connects`

Specifies the total number of connections to servers supporting the LanManager 2.1 dialect that have succeeded.

### `LanmanNtConnects`

Specifies the total number of connections to servers supporting the NTLM dialect that have succeeded.

### `ServerDisconnects`

Specifies the number of times the workstation was disconnected by a network server.

### `HungSessions`

Specifies the total number of sessions that have expired on the workstation.

### `UseCount`

Specifies the total number of network connections established by the workstation.

### `FailedUseCount`

Specifies the total number of failed network connections for the workstation.

### `CurrentCommands`

Specifies the number of current requests that have not been completed.

## See also

[NetStatisticsGet](https://learn.microsoft.com/windows/win32/api/lmstats/nf-lmstats-netstatisticsget)

[Network Management Overview](https://learn.microsoft.com/windows/win32/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/win32/NetMgmt/network-management-structures)

[Statistics Functions](https://learn.microsoft.com/windows/win32/NetShare/statistics-functions)