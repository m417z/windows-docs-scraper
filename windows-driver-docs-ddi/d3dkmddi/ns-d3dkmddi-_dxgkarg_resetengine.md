# DXGKARG_RESETENGINE structure

## Description

The **DXGKARG_RESETENGINE** structure specifies a node within the physical display adapter that can be reset when the display port driver's GPU scheduler calls KMD's [**DxgkDdiResetEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine) function to request a node reset operation.

## Members

### `NodeOrdinal` [in]

The index of a node within the physical adapter that **EngineOrdinal** specifies that is being reset in a call to [**DxgkDdiResetEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine).

### `EngineOrdinal` [in]

The index that defines the physical adapter in a linked display adapter (LDA) configuration that the node specified by **NodeOrdinal** belongs to.

### `LastAbortedFenceId` [out]

The fence identifier for the last packet that was aborted in the middle of execution.

## Remarks

For more information, see [TDR changes in Windows 8](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-changes-in-windows-8).

## See also

[**DxgkDdiResetEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine)