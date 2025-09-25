# FsRtlSetEcpListIntoIrp function

## Description

The **FsRtlSetEcpListIntoIrp** routine attaches an extra create parameter (ECP) context structure list to an IRP_MJ_CREATE operation.

## Parameters

### `Irp` [in, out]

A pointer to the IRP for an IRP_MJ_CREATE operation to which the ECP context structure list is to be attached.

### `EcpList` [in]

Pointer to an ECP list that contains one or more ECP context structures. These structures will be attached to the IRP to which the *Irp* parameter points.

## Return value

**FsRtlSetEcpListIntoIrp** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The given ECP list was successfully attached to the given IRP. |
| **STATUS_INVALID_PARAMETER_2** | The given IRP was not an IRP-based IRP_MJ_CREATE operation. |
| **STATUS_INVALID_PARAMETER_3** | An ECP list has already been attached to the given IRP. |

## Remarks

The **FsRtlSetEcpListIntoIrp** routine provides a mechanism for passing extra create parameters down the file system filter stack to underlying filter drivers.

To retrieve an ECP list that is associated with a given IRP_MJ_CREATE operation, use the [FsRtlGetEcpListFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetecplistfromirp) routine.

## See also

[ECP_LIST](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85))

[FsRtlGetEcpListFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetecplistfromirp)