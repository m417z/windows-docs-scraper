# DXGKDDI_SAVEMEMORYFORHOTUPDATE callback function

## Description

Before the driver is unloaded, it must call the DXGKDDI_SAVEMEMORYFORHOTUPDATE callback function to save information. This information is required to continue running virtual GPUs after the driver is started again.

## Parameters

### `hContext` [in]

A handle to the miniport context that is returned by the driver in DXGKDDI_DRIVERHOTUPDATE_INTERFACE.

### `pArgs` [in]

A pointer to a [PDXGKARG_SAVEMEMORYFORHOTUPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_savememoryforhotupdate) structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_SAVEMEMORYFORHOTUPDATE DxgkddiSavememoryforhotupdate;

// Definition

NTSTATUS DxgkddiSavememoryforhotupdate
(
	IN_CONST_HANDLE hContext
	IN_CONST_PDXGKARG_SAVEMEMORYFORHOTUPDATE pArgs
)
{...}

```

## Remarks

This callback supports driver hot update. Before the driver is unloaded, it is called to save information, which is required to continue running virtual GPUs after it is started again. The driver needs to have the state of every active virtual GPU (virtual function). In the context of a **DxgkDdiSaveMemoryForHotUpdate** call, the driver could call [DxgkCbSaveMemoryForHotUpdate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_savememoryforhotupdate) multiple times to save information about running virtual GPUs and other adapter information needed to restore the virtual GPU state after the device is started again.

## See also