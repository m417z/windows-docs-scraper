## Description

Enables the function device object (FDO) to indicate whether the core power rail is needed.

## Parameters

### `Context` [_In_reads_opt_(_Inexpressible_("varies"))]

The handle to the device.

### `CorePowerRailNeeded:` [_In_]

A flag that indicates whether or not the driver needs the core power rail.

## Remarks

A device driver that successfully queries for the GUID_D3COLD_AUX_POWER_AND_TIMING_INTERFACE interface receives a pointer to a [**D3COLD_AUX_POWER_AND_TIMING_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_d3cold_aux_power_and_timing_interface) structure in which the driver sets the **RequestCorePowerRail** member to a pointer to its implementation of the _D3COLD_REQUEST_CORE_POWER_RAIL_ callback function.

- If the driver indicates that the core power rail is needed, it is guaranteed that the core power rail is turned on when this call returns.

- When a driver indicates that the core power rail is no longer needed, there is no guarantee of the core power rail state onwards.

- This routine can never fail.

## See also