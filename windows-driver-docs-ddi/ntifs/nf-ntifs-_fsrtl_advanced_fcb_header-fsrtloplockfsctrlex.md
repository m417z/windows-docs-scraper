# FsRtlOplockFsctrlEx function

## Description

The **FsRtlOplockFsctrlEx** routine performs various opportunistic lock (oplock) operations on behalf of a file system or filter driver.

## Parameters

### `Oplock` [in]

Opaque oplock pointer for the file. This pointer must have been initialized by a previous call to [**FsRtlInitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock).

### `Irp` [in]

Pointer to the IRP for the I/O operation. This parameter is required and cannot be **NULL**.

### `OpenCount` [in]

Number of user handles for the file, if an exclusive oplock is being requested. Setting a nonzero value for a level 2, R, or RH oplock request indicates that there are byte-range locks on the file. For information about oplock types, see [Oplock Overview](https://learn.microsoft.com/windows-hardware/drivers/ifs/oplock-overview).

### `Flags` [in]

A bitmask for the associated oplock operations. A file system or filter driver sets bits to specify the behavior of **FsRtlOplockFsctrlEx**. This parameter has the following options:

| Flag | Meaning |
| ---- | ------- |
| OPLOCK_FSCTRL_FLAG_ALL_KEYS_MATCH (0x00000001) | The file system verified that all oplock keys on any currently open handles match. By specifying this flag, you allow the oplock package to grant an oplock of level RW or RWH when more than one open handle to the file exists. For more information about oplock types, see [Oplock Overview](https://learn.microsoft.com/windows-hardware/drivers/ifs/oplock-overview).

## Return value

**FsRtlOplockFsctrlEx** returns one of the following NTSTATUS values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | For an IRP_MJ_CREATE request, STATUS_SUCCESS indicates that the requested filter oplock was granted. For a FSCTL operation, the meaning of STATUS_SUCCESS depends on the FSCTL code. For more information, see the reference pages for the FSCTL codes listed in the following Remarks section. |
| STATUS_CANCELLED | The I/O operation was canceled. STATUS_CANCELLED is an error code. |
| STATUS_INVALID_PARAMETER | The FSCTL code for the I/O operation was not one of the valid values listed in the following Remarks section. STATUS_INVALID_PARAMETER is an error code. |
| STATUS_OPLOCK_NOT_GRANTED | The oplock could not be granted. STATUS_OPLOCK_NOT_GRANTED is an error code. |
| STATUS_PENDING | Used only for FSCTL operations. The meaning of STATUS_PENDING depends on the FSCTL code. For more information, see the reference pages for the FSCTL codes listed in the following Remarks section. STATUS_PENDING is a success code. |
| STATUS_CANNOT_BREAK_OPLOCK | A new oplock could not be granted. The IRP is an IRP_MJ_CREATE request and FILE_OPEN_REQUIRING_OPLOCK was specified in the create options parameter for the operation. STATUS_CANNOT_BREAK_OPLOCK is a success code. |

## Remarks

File systems and legacy filter drivers call **FsRtlOplockFsctrlEx** to perform various oplock operations for a create or file system control I/O operation. Minifilters should call [**FltOplockFsctrlEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrlex) instead of **FsRtlOplockFsctrlEx**.

The IRP pointed to by the *Irp* parameter must be a valid IRP for an [IRP_MJ_FILE_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-file-system-control) or [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) operation.

If the IRP is an [IRP_MJ_FILE_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-file-system-control) request, **FsRtlOplockFsctrlEx** can be used with one of the following FSCTL codes, which is set in *IrpSp->Parameters.FileSystemControl.FsControlCode*:

* [FSCTL_OPBATCH_ACK_CLOSE_PENDING](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-opbatch-ack-close-pending)
* [FSCTL_OPLOCK_BREAK_ACK_NO_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-ack-no-2)
* [FSCTL_OPLOCK_BREAK_ACKNOWLEDGE](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-acknowledge)
* [FSCTL_OPLOCK_BREAK_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-notify)
* [FSCTL_REQUEST_BATCH_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-batch-oplock)
* [FSCTL_REQUEST_FILTER_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-filter-oplock)
* [FSCTL_REQUEST_OPLOCK_LEVEL_1](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-1)
* [FSCTL_REQUEST_OPLOCK_LEVEL_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-2)
* [FSCTL_REQUEST_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock)

For more information about these FSCTLs and about opportunistic locks in general, see the Microsoft Windows SDK documentation.

If the IRP is an IRP_MJ_CREATE request, **FsRtlOplockFsctrlEx** can be used to request a pending filter oplock if all of the following conditions are true:

* The value of the *OpenCount* parameter must be 1.
* The value of the *DesiredAccess* parameter for the IRP_MJ_CREATE request must be FILE_READ_ATTRIBUTES.
* The value of the *ShareAccess* parameter for the IRP_MJ_CREATE request must be FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE.

If the request for a pending filter oplock is granted, **FsRtlOplockFsctrlEx** returns STATUS_SUCCESS. For more information about create parameters, see the reference entry for [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create).

Filters and file systems that call this function must synchronize calls into the system-supplied oplock package. See [Oplock synchronization](https://learn.microsoft.com/windows-hardware/drivers/ifs/oplock-synchronization) for more information.

## See also

[FSCTL_OPBATCH_ACK_CLOSE_PENDING](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-opbatch-ack-close-pending)

[FSCTL_OPLOCK_BREAK_ACKNOWLEDGE](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-acknowledge)

[FSCTL_OPLOCK_BREAK_ACK_NO_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-ack-no-2)

[FSCTL_OPLOCK_BREAK_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-notify)

[FSCTL_REQUEST_BATCH_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-batch-oplock)

[FSCTL_REQUEST_FILTER_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-filter-oplock)

[FSCTL_REQUEST_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock)

[FSCTL_REQUEST_OPLOCK_LEVEL_1](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-1)

[FSCTL_REQUEST_OPLOCK_LEVEL_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-2)

[**FltOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl)

[**FsRtlInitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock)

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[IRP_MJ_FILE_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-file-system-control)