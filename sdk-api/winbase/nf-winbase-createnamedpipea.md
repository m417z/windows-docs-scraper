# CreateNamedPipeA function

## Description

Creates an instance of a named pipe and returns a handle for subsequent pipe operations. A named pipe server process uses this function either to create the first instance of a specific named pipe and establish its basic attributes or to create a new instance of an existing named pipe.

## Parameters

### `lpName` [in]

The unique pipe name. This string must have the following form:

\\\\.\\pipe\*pipename*

The pipename part of the name can include any character other than a backslash, including numbers and special characters. The entire pipe name string can be up to 256 characters long. Pipe names are not case sensitive.

### `dwOpenMode` [in]

The open mode.

The function fails if *dwOpenMode* specifies anything other than 0 or the flags listed in the following tables.

This parameter must specify one of the following pipe access modes. The same mode must be specified for each instance of the pipe.

| Mode | Meaning |
| --- | --- |
| **PIPE_ACCESS_DUPLEX**<br><br>0x00000003 | The pipe is bi-directional; both server and client processes can read from and write to the pipe. This mode gives the server the equivalent of **GENERIC_READ** and **GENERIC_WRITE** access to the pipe. The client can specify **GENERIC_READ** or **GENERIC_WRITE**, or both, when it connects to the pipe using the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. |
| **PIPE_ACCESS_INBOUND**<br><br>0x00000001 | The flow of data in the pipe goes from client to server only. This mode gives the server the equivalent of **GENERIC_READ** access to the pipe. The client must specify **GENERIC_WRITE** access when connecting to the pipe. If the client must read pipe settings by calling the [GetNamedPipeInfo](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-getnamedpipeinfo) or [GetNamedPipeHandleState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnamedpipehandlestatea) functions, the client must specify **GENERIC_WRITE** and **FILE_READ_ATTRIBUTES** access when connecting to the pipe. |
| **PIPE_ACCESS_OUTBOUND**<br><br>0x00000002 | The flow of data in the pipe goes from server to client only. This mode gives the server the equivalent of **GENERIC_WRITE** access to the pipe. The client must specify **GENERIC_READ** access when connecting to the pipe. If the client must change pipe settings by calling the [SetNamedPipeHandleState](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-setnamedpipehandlestate) function, the client must specify **GENERIC_READ** and **FILE_WRITE_ATTRIBUTES** access when connecting to the pipe. |

This parameter can also include one or more of the following flags, which enable the write-through and overlapped modes. These modes can be different for different instances of the same pipe.

| Mode | Meaning |
| --- | --- |
| **FILE_FLAG_FIRST_PIPE_INSTANCE**<br><br>0x00080000 | If you attempt to create multiple instances of a pipe with this flag, creation of the first instance succeeds, but creation of the next instance fails with **ERROR_ACCESS_DENIED**. |
| **FILE_FLAG_WRITE_THROUGH**<br><br>0x80000000 | Write-through mode is enabled. This mode affects only write operations on byte-type pipes and, then, only when the client and server processes are on different computers. If this mode is enabled, functions writing to a named pipe do not return until the data written is transmitted across the network and is in the pipe's buffer on the remote computer. If this mode is not enabled, the system enhances the efficiency of network operations by buffering data until a minimum number of bytes accumulate or until a maximum time elapses. |
| **FILE_FLAG_OVERLAPPED**<br><br>0x40000000 | Overlapped mode is enabled. If this mode is enabled, functions performing read, write, and connect operations that may take a significant time to be completed can return immediately. This mode enables the thread that started the operation to perform other operations while the time-consuming operation executes in the background. For example, in overlapped mode, a thread can handle simultaneous input and output (I/O) operations on multiple instances of a pipe or perform simultaneous read and write operations on the same pipe handle. If overlapped mode is not enabled, functions performing read, write, and connect operations on the pipe handle do not return until the operation is finished. The [ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex) and [WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex) functions can only be used with a pipe handle in overlapped mode. The [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile), [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile), [ConnectNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe), and [TransactNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe) functions can execute either synchronously or as overlapped operations. |

This parameter can include any combination of the following security access modes. These modes can be different for different instances of the same pipe.

| Mode | Meaning |
| --- | --- |
| **WRITE_DAC**<br><br>0x00040000L | The caller will have write access to the named pipe's discretionary access control list (ACL). |
| **WRITE_OWNER**<br><br>0x00080000L | The caller will have write access to the named pipe's owner. |
| **ACCESS_SYSTEM_SECURITY**<br><br>0x01000000L | The caller will have write access to the named pipe's SACL. For more information, see [Access-Control Lists (ACLs)](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-lists) and [SACL Access Right](https://learn.microsoft.com/windows/desktop/SecAuthZ/sacl-access-right). |

### `dwPipeMode` [in]

The pipe mode.

The function fails if *dwPipeMode* specifies anything other than 0 or the flags listed in the following tables.

One of the following type modes can be specified. The same type mode must be specified for each instance of the pipe.

| Mode | Meaning |
| --- | --- |
| **PIPE_TYPE_BYTE**<br><br>0x00000000 | Data is written to the pipe as a stream of bytes. This mode cannot be used with PIPE_READMODE_MESSAGE. The pipe does not distinguish bytes written during different write operations. |
| **PIPE_TYPE_MESSAGE**<br><br>0x00000004 | Data is written to the pipe as a stream of messages. The pipe treats the bytes written during each write operation as a message unit. The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_MORE_DATA** when a message is not read completely. This mode can be used with either **PIPE_READMODE_MESSAGE** or **PIPE_READMODE_BYTE**. |

One of the following read modes can be specified. Different instances of the same pipe can specify different read modes.

| Mode | Meaning |
| --- | --- |
| **PIPE_READMODE_BYTE**<br><br>0x00000000 | Data is read from the pipe as a stream of bytes. This mode can be used with either **PIPE_TYPE_MESSAGE** or **PIPE_TYPE_BYTE**. |
| **PIPE_READMODE_MESSAGE**<br><br>0x00000002 | Data is read from the pipe as a stream of messages. This mode can be only used if **PIPE_TYPE_MESSAGE** is also specified. |

One of the following wait modes can be specified. Different instances of the same pipe can specify different wait modes.

| Mode | Meaning |
| --- | --- |
| **PIPE_WAIT**<br><br>0x00000000 | Blocking mode is enabled. When the pipe handle is specified in the [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile), [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile), or [ConnectNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe) function, the operations are not completed until there is data to read, all data is written, or a client is connected. Use of this mode can mean waiting indefinitely in some situations for a client process to perform an action. |
| **PIPE_NOWAIT**<br><br>0x00000001 | Nonblocking mode is enabled. In this mode, [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile), [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile), and [ConnectNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe) always return immediately.<br><br>Note that nonblocking mode is supported for compatibility with Microsoft LAN Manager version 2.0 and should not be used to achieve asynchronous I/O with named pipes. For more information on asynchronous pipe I/O, see [Synchronous and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/ipc/synchronous-and-overlapped-input-and-output). |

One of the following remote-client modes can be specified. Different instances of the same pipe can specify different remote-client modes.

| Mode | Meaning |
| --- | --- |
| **PIPE_ACCEPT_REMOTE_CLIENTS**<br><br>0x00000000 | Connections from remote clients can be accepted and checked against the security descriptor for the pipe. |
| **PIPE_REJECT_REMOTE_CLIENTS**<br><br>0x00000008 | Connections from remote clients are automatically rejected. |

### `nMaxInstances` [in]

The maximum number of instances that can be created for this pipe. The first instance of the pipe can specify this value; the same number must be specified for other instances of the pipe. Acceptable values are in the range 1 through **PIPE_UNLIMITED_INSTANCES** (255).

If this parameter is **PIPE_UNLIMITED_INSTANCES**, the number of pipe instances that can be created is limited only by the availability of system resources. If *nMaxInstances* is greater than **PIPE_UNLIMITED_INSTANCES**, the return value is **INVALID_HANDLE_VALUE** and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INVALID_PARAMETER**.

### `nOutBufferSize` [in]

The number of bytes to reserve for the output buffer. For a discussion on sizing named pipe buffers, see the following Remarks section.

### `nInBufferSize` [in]

The number of bytes to reserve for the input buffer. For a discussion on sizing named pipe buffers, see the following Remarks section.

### `nDefaultTimeOut` [in]

The default time-out value, in milliseconds, if the
[WaitNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitnamedpipea) function specifies **NMPWAIT_USE_DEFAULT_WAIT**. Each instance of a named pipe must specify the same value.

A value of zero will result in a default time-out of 50 milliseconds.

### `lpSecurityAttributes` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies a security descriptor for the new named pipe and determines whether child processes can inherit the returned handle. If *lpSecurityAttributes* is **NULL**, the named pipe gets a default security descriptor and the handle cannot be inherited. The ACLs in the default security descriptor for a named pipe grant full control to the LocalSystem account, administrators, and the creator owner. They also grant read access to members of the Everyone group and the anonymous account.

## Return value

If the function succeeds, the return value is a handle to the server end of a named pipe instance.

If the function fails, the return value is **INVALID_HANDLE_VALUE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To create an instance of a named pipe by using
**CreateNamedPipe**, the user must have **FILE_CREATE_PIPE_INSTANCE** access to the named pipe object. If a new named pipe is being created, the access control list (ACL) from the security attributes parameter defines the discretionary access control for the named pipe.

All instances of a named pipe must specify the same pipe type (byte-type or message-type), pipe access (duplex, inbound, or outbound), instance count, and time-out value. If different values are used, this function fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_ACCESS_DENIED**.

 A client process connects to a named pipe by using the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) or [CallNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-callnamedpipea) function. The client side of a named pipe starts out in byte mode, even if the server side is in message mode. To avoid problems receiving data, set the client side to message mode as well. To change the mode of the pipe, the pipe client must open a read-only pipe with **GENERIC_READ** and **FILE_WRITE_ATTRIBUTES** access.

The pipe server should not perform a blocking read operation until the pipe client has started. Otherwise, a race condition can occur. This typically occurs when initialization code, such as the C run-time, needs to lock and examine inherited handles.

Every time a named pipe is created, the system creates the inbound and/or outbound buffers using nonpaged pool, which is the physical memory used by the kernel. The number of pipe instances (as well as objects such as threads and processes) that you can create is limited by the available nonpaged pool. Each read or write request requires space in the buffer for the read or write data, plus additional space for the internal data structures.

The input and output buffer sizes are advisory. The actual buffer size reserved for each end of the named pipe is either the system default, the system minimum or maximum, or the specified size rounded up to the next allocation boundary. The buffer size specified should be small enough that your process will not run out of nonpaged pool, but large enough to accommodate typical requests.

Whenever a pipe write operation occurs, the system first tries to charge the memory against the pipe write quota. If the remaining pipe write quota is enough to fulfill the request, the write operation completes immediately. If the remaining pipe write quota is too small to fulfill the request, the system will try to expand the buffers to accommodate the data using nonpaged pool reserved for the process. The write operation will block until the data is read from the pipe so that the additional buffer quota can be released. Therefore, if your specified buffer size is too small, the system will grow the buffer as needed, but the downside is that the operation will block. If the operation is overlapped, a system thread is blocked; otherwise, the application thread is blocked.

To free resources used by a named pipe, the application should always close handles when they are no longer needed, which is accomplished either by calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function or when the process associated with the instance handles ends. Note that an instance of a named pipe may have more than one handle associated with it. An instance of a named pipe is always deleted when the last handle to the instance of the named pipe is closed.

**Windows 10, version 1709:** Pipes are only supported within an app-container; ie, from one UWP process to another UWP process that's part of the same app. Also, named pipes must use the syntax `\\.\pipe\LOCAL\` for the pipe name.

#### Examples

For an example, see
[Multithreaded Pipe Server](https://learn.microsoft.com/windows/desktop/ipc/multithreaded-pipe-server).

## See also

[ConnectNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[Pipe Functions](https://learn.microsoft.com/windows/desktop/ipc/pipe-functions)

[Pipes Overview](https://learn.microsoft.com/windows/desktop/ipc/pipes)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[TransactNamedPipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe)

[WaitNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-waitnamedpipea)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)

[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex)