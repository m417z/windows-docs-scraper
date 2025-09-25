# NETWORK_OPEN_ECP_CONTEXT_V0 structure

## Description

The NETWORK_OPEN_ECP_CONTEXT_V0 structure is used to interpret network extra create parameter (ECP) contexts on files.

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

### `DUMMYSTRUCTNAME.out`

Structure that contains post-create restrictions to apply to a file after it has been opened.

### `DUMMYSTRUCTNAME.out.Location`

A [**NETWORK_OPEN_LOCATION_QUALIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-network_open_location_qualifier)-typed value that specifies the location restriction to attach to the file.

### `DUMMYSTRUCTNAME.out.Integrity`

This member is currently not implemented and should be ignored.

A [**NETWORK_OPEN_INTEGRITY_QUALIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-network_open_integrity_qualifier)-typed value that specifies the integrity restriction to attach to the file.

## Remarks

For information about how to use ECPs to associate extra information with a file when the file is created, see [Using Extra Create Parameters with an IRP_MJ_CREATE Operation](https://learn.microsoft.com/windows-hardware/drivers/ifs/using-extra-create-parameters-with-an-irp-mj-create-operation).

A filter driver should consider the NETWORK_OPEN_ECP_CONTEXT structure to be read-only, using it only to retrieve information about the network ECP context on a file. For more information, see [System-Defined ECPs](https://learn.microsoft.com/windows-hardware/drivers/ifs/system-defined-ecps).

If a caller must verify that the file system acknowledged the **NETWORK_OPEN_ECP_CONTEXT_V0** context structure, the caller should call the [**FltIsEcpAcknowledged**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpacknowledged) or [**FsRtlIsEcpAcknowledged**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisecpacknowledged) routine on the ECP after the operation is complete.

In most cases, drivers that run on Windows Vista and later versions of Windows use the [**NETWORK_OPEN_ECP_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_network_open_ecp_context) structure to interpret network ECP contexts on files. However, drivers that run on Windows 7 and later versions of Windows and that must interpret network ECP contexts on files that reside on Windows Vista must use the **NETWORK_OPEN_ECP_CONTEXT_V0** structure instead.

## See also

[**FltIsEcpAcknowledged**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisecpacknowledged)

[**FsRtlIsEcpAcknowledged**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisecpacknowledged)

[**NETWORK_OPEN_ECP_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_network_open_ecp_context)

[**NETWORK_OPEN_INTEGRITY_QUALIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-network_open_integrity_qualifier)

[**NETWORK_OPEN_LOCATION_QUALIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-network_open_location_qualifier)