# SERVER_INFO_503 structure

## Description

The
**SERVER_INFO_503** structure is obsolete. The structure contains information about the specified server.

## Members

### `sv503_sessopens`

Type: **DWORD**

The number of files that can be open in one session.

### `sv503_sessvcs`

Type: **DWORD**

The maximum number of sessions or virtual circuits permitted per client.

### `sv503_opensearch`

Type: **DWORD**

The number of search operations that can be carried out simultaneously.

### `sv503_sizreqbuf`

Type: **DWORD**

The size, in bytes, of each server buffer.

### `sv503_initworkitems`

Type: **DWORD**

The initial number of receive buffers, or work items, used by the server.

### `sv503_maxworkitems`

Type: **DWORD**

The maximum number of receive buffers, or work items, the server can allocate. If this limit is reached, the transport must initiate flow control at a significant performance cost.

### `sv503_rawworkitems`

Type: **DWORD**

The number of special work items the server uses for raw mode I/O. A larger value for this member can increase performance but it requires more memory.

### `sv503_irpstacksize`

Type: **DWORD**

The number of stack locations that the server allocated in I/O request packets (IRPs).

### `sv503_maxrawbuflen`

Type: **DWORD**

The maximum raw mode buffer size, in bytes.

### `sv503_sessusers`

Type: **DWORD**

The maximum number of users that can be logged on to the server using a single session or virtual circuit.

### `sv503_sessconns`

Type: **DWORD**

The maximum number of tree connections that can be made on the server using a single session or virtual circuit.

### `sv503_maxpagedmemoryusage`

Type: **DWORD**

The maximum size, in bytes, of pageable memory that the server can allocate at any one time.

### `sv503_maxnonpagedmemoryusage`

### `sv503_enablesoftcompat`

Type: **BOOL**

A value that indicates whether the server maps a request to a normal open request with shared-read access when the server receives a compatibility open request with read access. Mapping such requests allows several MS-DOS computers to open a single file for read access. This member is unused.

### `sv503_enableforcedlogoff`

Type: **BOOL**

A value that indicates whether the server should force a client to disconnect, even if the client has open files, once the client's logon time has expired.

### `sv503_timesource`

Type: **BOOL**

A value that indicates whether the server is a reliable time source.

### `sv503_acceptdownlevelapis`

Type: **BOOL**

A value that indicates whether the server accepts function calls from previous-generation LAN Manager clients.

### `sv503_lmannounce`

Type: **BOOL**

A value that indicates whether the server is visible to LAN Manager 2.x clients.

### `sv503_domain`

Type: **LPWSTR**

A pointer to a Unicode character string that specifies the name of the server's domain.

### `sv503_maxcopyreadlen`

Type: **DWORD**

The maximum length, in bytes, of copy reads on the server.

This member is unused.

### `sv503_maxcopywritelen`

Type: **DWORD**

The maximum length, in bytes, of copy writes on the server.

This member is unused.

### `sv503_minkeepsearch`

Type: **DWORD**

The minimum length of time the server retains information about incomplete search operations. This member is unused.

### `sv503_maxkeepsearch`

Type: **DWORD**

The maximum length of time, in seconds, the server retains information about incomplete search operations.

### `sv503_minkeepcomplsearch`

Type: **DWORD**

The minimum length of time, in seconds, the server retains information about complete search operations. This member is unused.

### `sv503_maxkeepcomplsearch`

Type: **DWORD**

The maximum length of time, in seconds, the server retains information about complete search operations. This member is unused.

### `sv503_threadcountadd`

Type: **DWORD**

The number of additional threads the server should use in addition to one worker thread per processor it already uses. This member is unused.

### `sv503_numblockthreads`

Type: **DWORD**

The number of threads set aside by the server to service requests that can block the thread for a significant amount of time. This member is unused.

### `sv503_scavtimeout`

Type: **DWORD**

The period of time, in seconds, that the scavenger remains idle before waking up to service requests.

### `sv503_minrcvqueue`

Type: **DWORD**

The minimum number of free receive work items the server requires before it begins to allocate more.

### `sv503_minfreeworkitems`

Type: **DWORD**

The minimum number of available receive work items that the server requires to begin processing a server message block.

### `sv503_xactmemsize`

Type: **DWORD**

The size, in bytes, of the shared memory region used to process server functions.

### `sv503_threadpriority`

Type: **DWORD**

The priority of all server threads in relation to the base priority of the process.

### `sv503_maxmpxct`

Type: **DWORD**

The maximum number of outstanding requests that any one client can send to the server. For example, 10 means you can have 10 unanswered requests at the server. When any single client has 10 requests queued within the server, the client must wait for a server response before sending another request.

### `sv503_oplockbreakwait`

Type: **DWORD**

The period of time, in seconds, to wait before timing out an opportunistic lock break request.

### `sv503_oplockbreakresponsewait`

Type: **DWORD**

The period of time, in seconds, the server waits for a client to respond to an oplock break request from the server.

### `sv503_enableoplocks`

Type: **BOOL**

A value that indicates whether the server allows clients to use opportunistic locks on files. Opportunistic locks are a significant performance enhancement, but have the potential to cause lost cached data on some networks, particularly wide-area networks.

### `sv503_enableoplockforceclose`

Type: **BOOL**

A value that indicates how the server should behave if a client has an opportunistic lock (oplock) and does not respond to an oplock break. This member indicates whether the server will fail the second open (value of 0), or force close the open instance of a client that has an oplock (value equal to 1). This member is unused.

### `sv503_enablefcbopens`

Type: **BOOL**

A value that indicates whether several MS-DOS File Control Blocks (FCBs) are placed in a single location accessible to the server. If enabled, this can save resources on the server.

### `sv503_enableraw`

Type: **BOOL**

A value that indicates whether the server processes raw Server Message Blocks (SMBs). If enabled, this allows more data to transfer per transaction and also improves performance. However, it is possible that processing raw SMBs can impede performance on certain networks. The server maintains the value of this member.

### `sv503_enablesharednetdrives`

Type: **BOOL**

A value that indicates whether the server allows redirected server drives to be shared.

### `sv503_minfreeconnections`

Type: **DWORD**

The minimum number of free connection blocks maintained per endpoint. The server sets these aside to handle bursts of requests by clients to connect to the server.

### `sv503_maxfreeconnections`

Type: **DWORD**

The maximum number of free connection blocks maintained per endpoint. The server sets these aside to handle bursts of requests by clients to connect to the server.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)