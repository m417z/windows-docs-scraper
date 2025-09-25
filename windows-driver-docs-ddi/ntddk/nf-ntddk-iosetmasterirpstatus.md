# IoSetMasterIrpStatus function

## Description

The **IoSetMasterIrpStatus** routine conditionally replaces the **Status** value in an IRP with the specified NTSTATUS value.

## Parameters

### `MasterIrp` [in, out]

A pointer to the master [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp). For more information, see Remarks.

### `Status` [in]

An NTSTATUS value to compare to the **Status** member of the [I/O status block](https://learn.microsoft.com/windows-hardware/drivers/kernel/i-o-status-blocks) in the master IRP.

## Remarks

On receipt of an IRP, a driver can create two or more subordinate IRPs to perform the work requested by the original (or master) IRP. When the subordinate IRPs complete, the driver gathers the completion status codes from the subordinate IRPs and merges them to form a single completion status code for the master IRP.

**IoSetMasterIrpStatus** implements a uniform policy for merging the status codes from multiple subordinate IRPs into a status code for a master IRP. For example, if a master IRP is split into two subordinate IRPs, and one of these subordinate IRPs succeeds and the other fails, the status code from the failing IRP is used as the status code for the master IRP. However, if both subordinate IRPs fail, the more severe failure code is used as the status for the master IRP.

Before the first call to **IoSetMasterIrpStatus**, the driver sets the **IoStatus.Status** member in the master IRP to STATUS_SUCCESS (or to STATUS_FT_READ_FROM_COPY in case it is expected). Next, as each subordinate IRP completes, the driver calls **IoSetMasterIrpStatus** to merge the status code from this IRP with the status code in the master IRP. In this call, the *PIRP* parameter points to the master IRP, and the *Status* parameter is set to the value of the **IoStatus.Status** member in the subordinate IRP.

As a general rule, **IoSetMasterIrpStatus** replaces the status code in *PIRP*->**IoStatus.Status** with the *Status* value in the following cases:

* The status value in **PIRP* is STATUS_SUCCESS, and *Status* is an error code.
* The status value in **PIRP* is an error code, but *Status* is a more severe error code.

There are two exceptions to the general rule. A *Status* value of STATUS_VERIFY_REQUIRED always replaces the status value in **PIRP*. A *Status* value of STATUS_FT_READ_FROM_COPY never replaces the status value in **PIRP*.

## See also

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)