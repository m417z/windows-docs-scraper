# DXGKDDI_SETTRACKEDWORKLOADPOWERLEVEL callback function

## Description

Called by the workload tracker to modify the power level on a context.

## Parameters

### `hContext`

A handle to the hardware context.

### `pTrackedWorkloadPowerLevel`

Pointer to a [DXGKARG_SETTRACKEDWORKLOADPOWERLEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_settrackedworkloadpowerlevel) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

DXGKDDI_SETTRACKEDWORKLOADPOWERLEVEL DxgkddiSettrackedworkloadpowerlevel;

// Definition

NTSTATUS DxgkddiSettrackedworkloadpowerlevel
(
	IN_CONST_HANDLE hContext
	INOUT_PDXGKARG_SETTRACKEDWORKLOADPOWERLEVEL pTrackedWorkloadPowerLevel
)
{...}

```

## Remarks

If the next packet submission for this context takes place, then the new frequency/configuration parameters for the GPU should be effective. The OS will just call the DDI to set the ratio if it changes significantly from the previously computed level. Whenever we switch to this context, the driver needs to make sure the correct GPU configuration including the appropriate frequencies is applied to any subsequent packets execution.

## See also