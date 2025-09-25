# DXGKDDI_RESTOREMEMORYFORHOTUPDATE callback function

## Description

Restores memory for driver hot update. This callback function does not initialize virtual functions. The driver needs to reserve resources, which are used to restore virtual GPUs.

## Parameters

### `hContext` [in]

A handle to the driver miniport context.

### `pArgs` [in]

A pointer to the [DXGKARG_RESTOREMEMORYFORHOTUPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_restorememoryforhotupdate) structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_RESTOREMEMORYFORHOTUPDATE DxgkddiRestorememoryforhotupdate;

// Definition

NTSTATUS DxgkddiRestorememoryforhotupdate
(
	IN_CONST_HANDLE hContext
	IN_CONST_PDXGKARG_RESTOREMEMORYFORHOTUPDATE pArgs
)
{...}

```

## Remarks

Before calling DxgkDdiStartDevice, Dxgkrnl calls **DxgkDdiRestoreMemoryForHotUpdate** once for each memory block, which was saved by [DxgkCbSaveMemoryForHotUpdate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_savememoryforhotupdate).

## See also