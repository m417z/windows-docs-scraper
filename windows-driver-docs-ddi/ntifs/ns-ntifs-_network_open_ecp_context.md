# NETWORK_OPEN_ECP_CONTEXT structure

## Description

The **NETWORK_OPEN_ECP_CONTEXT** structure is used to interpret network extra create parameter (ECP) contexts on files.

## Members

### `Size`

The size, in bytes, of this structure.

### `Reserved`

Reserved. Must be set to zero.

### `DUMMYSTRUCTNAME`

A structure that contains restrictions to apply for opening the file (pre-create) and to apply to the file after it is opened (post-create).

### `DUMMYSTRUCTNAME.in`

Structure that contains pre-create restrictions for opening a file.

### `DUMMYSTRUCTNAME.in.Location`

A [**NETWORK_OPEN_LOCATION_QUALIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-network_open_location_qualifier)-typed value that specifies the location restriction to attach to the file.

### `DUMMYSTRUCTNAME.in.Integrity`

A [**NETWORK_OPEN_INTEGRITY_QUALIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-network_open_integrity_qualifier)-typed value that specifies the integrity restriction to attach to the file.

### `DUMMYSTRUCTNAME.in.Flags`

Supported starting with Windows 7. A value that specifies attributes for the file. This member is a bitwise OR of any of the following flags.

| Value | Meaning |
| ----- | ------- |
| NETWORK_OPEN_ECP_IN_FLAG_DISABLE_HANDLE_COLLAPSING (0x1) | Indicates to the SMB redirector that the incoming open request must not be piggybacked and collapsed onto an existing open handle to the same file. |
| NETWORK_OPEN_ECP_IN_FLAG_DISABLE_HANDLE_DURABILITY (0x2) | Causes the SMB2+ redirector to disable durability on this open handle. For more information about opening a file for durable operation, see [Application Requests Creating a File Opened for Durable Operation](https://learn.microsoft.com/openspecs/windows_protocols/ms-smb2/11d04fbc-2c15-4acc-807d-949b6605ed6c). |
| NETWORK_OPEN_ECP_IN_FLAG_DISABLE_OPLOCKS (0x4) | Indicates to the SMB redirector to not grant oplocks for the incoming open request. This flag is available starting with Windows 8. |
| NETWORK_OPEN_ECP_IN_FLAG_FORCE_BUFFERED_SYNCHRONOUS_IO_HACK (0x80000000) | Reserved for internal use and must not be used by applications. This flag forces the redirector to use synchronous I/O even though the handle was opened for asynchronous I/O. |

### `DUMMYSTRUCTNAME.out`

Structure that contains post-create restrictions to apply to a file after it has been opened.

### `DUMMYSTRUCTNAME.out.Location`

A [**NETWORK_OPEN_LOCATION_QUALIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-network_open_location_qualifier)-typed value that specifies the location restriction to attach to the file.

### `DUMMYSTRUCTNAME.out.Integrity`

A [**NETWORK_OPEN_INTEGRITY_QUALIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-network_open_integrity_qualifier)-typed value that specifies the integrity restriction to attach to the file.

### `DUMMYSTRUCTNAME.out.Flags`

 Supported starting with Windows 7. A value that specifies attributes for the file. This member is a bitwise OR of any of the following flags.

| Value | Meaning |
| ----- | ------- |
| NETWORK_OPEN_ECP_IN_FLAG_DISABLE_HANDLE_COLLAPSING (0x1) | Indicates to the SMB redirector that the incoming open request must not be piggybacked and collapsed onto an existing open handle to the same file. |
| NETWORK_OPEN_ECP_IN_FLAG_DISABLE_HANDLE_DURABILITY (0x2) | Causes the SMB2+ redirector to disable durability on this open handle. For more information about opening a file for durable operation, see [Application Requests Creating a File Opened for Durable Operation](https://learn.microsoft.com/openspecs/windows_protocols/ms-smb2/11d04fbc-2c15-4acc-807d-949b6605ed6c). |
| NETWORK_OPEN_ECP_IN_FLAG_FORCE_BUFFERED_SYNCHRONOUS_IO_HACK (0x80000000) | Reserved for internal use and must not be used by applications. This flag forces the redirector to use synchronous I/O even though the handle was opened for asynchronous I/O. |

## Remarks

For information about how to use ECPs to associate extra information with a file when the file is created, see [Using Extra Create Parameters with an IRP_MJ_CREATE Operation](https://learn.microsoft.com/windows-hardware/drivers/ifs/using-extra-create-parameters-with-an-irp-mj-create-operation).

A filter driver should consider the NETWORK_OPEN_ECP_CONTEXT structure to be read-only, using it only to retrieve information about the network ECP context on a file. For more information, see [System-Defined ECPs](https://learn.microsoft.com/windows-hardware/drivers/ifs/system-defined-ecps).

If a caller must verify that the file system acknowledged the **NETWORK_OPEN_ECP_CONTEXT** context structure, the caller should call the [**FltIsEcpAcknowledged**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpacknowledged) or [**FsRtlIsEcpAcknowledged**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisecpacknowledged) routine on the ECP after the operation is complete.

Drivers that run on Windows 7 and later versions of Windows and that must interpret network ECP contexts on files that reside on Windows Vista must use the [**NETWORK_OPEN_ECP_CONTEXT_V0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_network_open_ecp_context_v0) structure instead.

Drivers that run on Windows Vista and later versions of Windows use the **NETWORK_OPEN_ECP_CONTEXT** structure to interpret network ECP contexts on files. However, the **DUMMYSTRUCTNAME.in.Flags** and **DUMMYSTRUCTNAME.out.Flags** members are only supported starting with Windows 7.

## See also

[**FltIsEcpAcknowledged**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpacknowledged)

[**FsRtlIsEcpAcknowledged**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisecpacknowledged)

[**NETWORK_OPEN_ECP_CONTEXT_V0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_network_open_ecp_context_v0)

[**NETWORK_OPEN_LOCATION_QUALIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-network_open_location_qualifier)

[**NETWORK_OPEN_INTEGRITY_QUALIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-network_open_integrity_qualifier)