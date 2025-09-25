## Description

Enables the function device object (FDO) to convey its requirement for a fixed delay time between the PME_TO_Ack message is received at the PCI Express Downstream Port that originated the PME_Turn_Off message, and the time the platform asserts PERST# to the slot during the corresponding endpoint's or PCI Express Upstream Port's transition to D3cold while the system is in an ACPI operational state.

## Parameters

### `Context` [_In_reads_opt_(_Inexpressible_("varies"))]

The handle to the device.

### `DelayInMicroSeconds` [_In_]

The delay in units of microsecond. The maximum value is 10000 microseconds.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A device driver that successfully queries for the GUID_D3COLD_AUX_POWER_AND_TIMING_INTERFACE interface receives a pointer to a [**D3COLD_AUX_POWER_AND_TIMING_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_aux_power_and_timing_interface) structure in which the driver sets the **RequestPerstDelay** member to a pointer to its implementation of the _D3COLD_REQUEST_PERST_DELAY_ callback function.

- For a multi-function device, only Function 0 is allowed to call this routine.

- Function 0 must be in D0 when calling this routine.

## See also