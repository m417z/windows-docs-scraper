# DXGKDDI_BEGINEXCLUSIVEACCESS callback function

## Description

*Dxgkrnl* calls **DxgkDdiBeginExclusiveAccess** to notify the kernel-mode driver that an IOMMU domain switch is about to occur.

## Parameters

### `hAdapter`

[in] A handle to a context block that is associated with a display adapter.

### `pBeginExclusiveAccess`

[in] Pointer to a [**DXGKARG_BEGINEXCLUSIVEACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_beginexclusiveaccess) structure that contains the input arguments for **DxgkDdiBeginExclusiveAccess**.

## Return value

**DxgkDdiBeginExclusiveAccess** should return STATUS_SUCCESS if the operation succeeds. Otherwise, it should return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

IOMMU domain attach and detach is extremely fast, but is nonetheless not currently atomic. This means that a transaction issued over PCIe isn't guaranteed to be translated correctly while swapping to a domain with different mappings.

To handle this situation, *Dxgkrnl* calls the following KMD DDI pair:

* **DxgkDdiBeginExclusiveAccess** to notify KMD that an IOMMU domain switch is about to occur.
* [**DxgkDdiEndExclusiveAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_endexclusiveaccess) after the IOMMU domain switch is complete.

The driver must ensure that its hardware is silent whenever the device is switched to a new IOMMU domain. That is, the driver must ensure that it doesn't read or write to system memory from the device between these two calls.

Between these two calls, *Dxgkrnl* guarantees the following:

* The scheduler will be suspended. All active workloads will be flushed, and no new workloads will be sent to or scheduled on the hardware.
* No other DDI calls will be made.

As part of these calls, the driver may choose to disable and suppress interrupts (including vsync interrupts) for the duration of the exclusive access, even without explicit notification from the OS.

## See also

[**DRIVER_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_driver_initialization_data)

[**DXGKARG_BEGINEXCLUSIVEACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_beginexclusiveaccess)

[**DxgkDdiEndExclusiveAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_endexclusiveaccess)