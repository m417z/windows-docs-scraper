# SERVER_INFO_502 structure

## Description

The
**SERVER_INFO_502** structure is obsolete. The structure contains information about a specified server.

## Members

### `sv502_sessopens`

Type: **DWORD**

The number of files that can be open in one session.

### `sv502_sessvcs`

Type: **DWORD**

T he maximum number of virtual circuits permitted per client.

### `sv502_opensearch`

Type: **DWORD**

The number of search operations that can be carried out simultaneously.

### `sv502_sizreqbuf`

Type: **DWORD**

The size, in bytes, of each server buffer.

### `sv502_initworkitems`

Type: **DWORD**

The initial number of receive buffers, or work items, used by the server.

### `sv502_maxworkitems`

Type: **DWORD**

The maximum number of receive buffers, or work items, the server can allocate. If this limit is reached, the transport must initiate flow control at a significant performance cost.

### `sv502_rawworkitems`

Type: **DWORD**

The number of special work items the server uses for raw mode I/O. A large value for this member can increase performance, but it requires more memory.

### `sv502_irpstacksize`

Type: **DWORD**

The number of stack locations that the server allocated in I/O request packets (IRPs).

### `sv502_maxrawbuflen`

Type: **DWORD**

The maximum raw mode buffer size, in bytes.

### `sv502_sessusers`

Type: **DWORD**

The maximum number of users that can be logged on to the server using a single virtual circuit.

### `sv502_sessconns`

Type: **DWORD**

The maximum number of tree connections that can be made on the server using a single virtual circuit.

### `sv502_maxpagedmemoryusage`

Type: **DWORD**

The maximum size, in bytes, of pageable memory that the server can allocate at any one time.

### `sv502_maxnonpagedmemoryusage`

Type: **DWORD**

The maximum size, in bytes, of nonpaged memory that the server can allocate at any one time.

### `sv502_enablesoftcompat`

Type: **BOOL**

A value that indicates whether the server maps a request to a normal open request with shared-read access when the server receives a compatibility open request with read access. Mapping such requests allows several MS-DOS computers to open a single file for read access.

### `sv502_enableforcedlogoff`

Type: **BOOL**

A value that indicates whether the server should force a client to disconnect, even if the client has open files, once the client's logon time has expired.

### `sv502_timesource`

Type: **BOOL**

A value that indicates whether the server is a reliable time source.

### `sv502_acceptdownlevelapis`

Type: **BOOL**

A value that indicates whether the server accepts function calls from previous-generation LAN Manager clients.

### `sv502_lmannounce`

Type: **BOOL**

A value that indicates whether the server is visible to LAN Manager 2.x clients.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[NetServerSetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserversetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)