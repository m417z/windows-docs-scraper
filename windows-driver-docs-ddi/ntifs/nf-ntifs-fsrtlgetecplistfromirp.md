# FsRtlGetEcpListFromIrp function

## Description

The **FsRtlGetEcpListFromIrp** routine returns a pointer to an extra create parameter (ECP) context structure list that is associated with a given IRP_MJ_CREATE operation.

## Parameters

### `Irp` [in]

A pointer to the IRP for an IRP_MJ_CREATE operation from which the ECP context structure list is to be extracted.

### `EcpList` [out]

Receives a pointer to the ECP context structure list that is associated with the IRP.

## Return value

**FsRtlGetEcpListFromIrp** returns STATUS_SUCCESS or an appropriate error status representing the final completion status of the operation. Possible error status codes include the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The given IRP was not an IRP-based IRP_MJ_CREATE operation. In this case, *EcpList* is undefined. |

## Remarks

To attach an ECP context structure list to an IRP, use the [FsRtlSetEcpListIntoIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlsetecplistintoirp) routine.

## See also

[FsRtlSetEcpListIntoIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlsetecplistintoirp)