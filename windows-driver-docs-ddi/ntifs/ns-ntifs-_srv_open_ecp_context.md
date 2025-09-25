# _SRV_OPEN_ECP_CONTEXT structure

## Description

The SRV_OPEN_ECP_CONTEXT structure is used by a server to conditionally open files in response to client requests.

## Members

### `ShareName`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that supplies the share name for the server that contains the files to be open. This field is optional and can be NULL.

### `SocketAddress`

Pointer to a [SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh) structure that specifies the transport address of a client computer. This client originates the open file request. This field is optional and can be a NULL.

### `OplockBlockState`

A Boolean value that indicates whether the Server Message Block (SMB) server blocks the open thread that is waiting for the oplock break. **TRUE** indicates that the open thread is in the blocking state and **FALSE** otherwise.

### `OplockAppState`

A Boolean value that indicates whether the SMB server requests an oplock with the current open thread. Set to **TRUE** to request the oplock and **FALSE** otherwise.

### `OplockFinalState`

A Boolean value that indicates whether a file-open operation is the final file-open operation to request the oplock. **TRUE** indicates the final file-open operation to obtain the oplock and **FALSE** indicates otherwise.

### `Version`

Version of this structure. This member was added in Windows 10 version 1703, so before trying to access it you must first check to see if it exists. If the structure size is >= [RTL_SIZEOF_THROUGH_FIELD](https://learn.microsoft.com/windows-hardware/drivers/debugger/c---numbers-and-operators)(SRV_OPEN_ECP_CONTEXT, Version), you can access this field. This member can be currently be set to SRV_OPEN_ECP_CONTEXT_VERSION_2.

### `InstanceType`

The [SRV_INSTANCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-srv_instance_type) that the open is coming from. File system minifilters that attach to NTFS or ReFS used by CSVFS can use this field to detect if this open is bypassing CSVFS. If the open goes through CSVFS, then this ECP is either absent or the instance type is SrvInstanceTypeCsv. If the open is bypassing CSVFS and goes directly to the hidden volume, then **InstanceType** is SrvInstanceTypePrimary. The **InstanceType** field is present only if **Version** is >= SRV_OPEN_ECP_CONTEXT_VERSION_2.

## Remarks

The file-system stack can determine whether SRV_OPEN_ECP_CONTEXT is attached to the create file request. The file-system stack can then use the information in SRV_OPEN_ECP_CONTEXT to determine which client requested that the file be opened, and why it requested it. For information about how to retrieve the SRV_OPEN_ECP_CONTEXT extra information that is attached to a create file request, see [Retrieving ECPs](https://learn.microsoft.com/windows-hardware/drivers/ifs/using-ecps-to-process-irp-mj-create-operations-in-a-file-system-minifilter).

The SRV_OPEN_ECP_CONTEXT structure is read-only. You should use it to retrieve information about a server open ECP only. For more information about this issue, see [System-Defined ECPs](https://learn.microsoft.com/windows-hardware/drivers/ifs/system-defined-ecps).

The oplock state values (**OplockBlockState**, **OplockAppState**, and **OplockFinalState**) are used with oplock breaking logic for system management for SMB and SMB2.

## See also

[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh)

[SRV_INSTANCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-srv_instance_type)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)