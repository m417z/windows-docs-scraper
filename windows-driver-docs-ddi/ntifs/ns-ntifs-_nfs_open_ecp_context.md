# _NFS_OPEN_ECP_CONTEXT structure

## Description

The NFS_OPEN_ECP_CONTEXT structure is used by the Network File System (NFS) server to open files in response to client requests.

## Members

### `ExportAlias`

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that supplies the export alias (share name) for the NFS server that contains the files to be opened. This member is a hint and can be a name, **NULL**, or a zero-length string.

### `ClientSocketAddress`

A pointer to a [SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh) structure that specifies the transport address of the client computer. This client originates the open file request.

## Remarks

The file-system stack can determine whether NFS_OPEN_ECP_CONTEXT is attached to the create file request. The file-system stack can then use the information in NFS_OPEN_ECP_CONTEXT to determine the client that requested that the file be opened and why it was requested. For information about how to retrieve the NFS_OPEN_ECP_CONTEXT extra information that is attached to a create file request, see [Retrieving ECPs](https://learn.microsoft.com/windows-hardware/drivers/ifs/using-ecps-to-process-irp-mj-create-operations-in-a-file-system-minifilter).

The NFS_OPEN_ECP_CONTEXT structure is read-only. You should use it to retrieve information about the open file ECP only. For more information about this issue, see [System-Defined ECPs](https://learn.microsoft.com/windows-hardware/drivers/ifs/system-defined-ecps).

## See also

[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)