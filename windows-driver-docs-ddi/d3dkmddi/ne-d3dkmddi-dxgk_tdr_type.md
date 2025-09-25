## Description

The **DXGK_TDR_TYPE** enumeration specifies the type of timeout detection and recovery (TDR) event that occurred.

## Constants

### `DXGK_TDR_TYPE_UNKNOWN:0`

Reserved. A KMD's [**DxgkDdiCollectDbgInfo2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo2) implementation shouldn't receive this value.

### `DXGK_TDR_TYPE_FORCED:1`

The TDR is forced via [**D3DKMT_ESCAPE_TDRDBGCTRL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_escape) with zero data or with **D3DKMT_TDRDBGCTRLTYPE_FORCETDR** type.

### `DXGK_TDR_TYPE_PREEMPT_TIMEOUT:2`

For drivers that don't support engine reset, this value is used prior to resetting the whole adapter that had one of the GPU engines time out.

### `DXGK_TDR_TYPE_VSYNC_TIMEOUT:3`

This value is used when the display part of the GPU doesn't acknowledge a pending flip request in a timely manner.

### `DXGK_TDR_TYPE_DOD_PRESENT_FORCED:4`

This value is used for Display Only adapters when the TDR is forced via [**D3DKMT_TDRDBGCTRLTYPE_FORCEDODTDR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_tdrdbgctrltype) escape.

### `DXGK_TDR_TYPE_DOD_PRESENT_TIMEOUT:5`

This value is used for Display Only adapters when they don't complete a present within the TDR timeout.

### `DXGK_TDR_TYPE_ENGINE_TIMEOUT:6`

This value is used when a particular GPU engine can't complete pending GPU work or a preemption request within the TDR timeout.

### `DXGK_TDR_TYPE_DOD_VSYNC_FORCED:7`

This value is used for Display Only adapters when the TDR is forced via [**D3DKMT_TDRDBGCTRLTYPE_FORCEDODVSYNCTDR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_tdrdbgctrltype) escape.

### `DXGK_TDR_TYPE_DOD_VSYNC_TIMEOUT:8`

This value is used for Display Only adapters when they don't raise a VSync interrupt within the TDR timeout.

### `DXGK_TDR_TYPE_ENGINE_TIMEOUT_PROMOTED:9`

This value is used when a GPU engine timeout is promoted by the OS to the full adapter reset.

### `DXGK_TDR_TYPE_PAGE_FAULT:10`

This value is used when an adapter reset is requested by a GPU page fault interrupt that set the [**DXGK_PAGE_FAULT_ADAPTER_RESET_REQUIRED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_page_fault_flags) flag to 1.

### `DXGK_TDR_TYPE_INVALID_FENCE:11`

This value is used for certain legacy pre-WDDM 2.4 drivers when the GPU reports an incorrect submission or preempted fence value that results in a GPU reset.

### `DXGK_TDR_TYPE_ENGINE_PAGE_FAULT:12`

This value is used when a GPU engine reset is requested by a GPU page fault interrupt that set the [**DXGK_PAGE_FAULT_ENGINE_RESET_REQUIRED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_page_fault_flags) flag to 1.

### `DXGK_TDR_TYPE_DISPLAY_ENGINE_FAULT:13`

This value is used when a display engine fault is detected by the OS.

## Remarks

For more information, see [TDR debuggability improvements](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-debuggability-improvements).

## See also

[**DXGKARG_COLLECTDBGINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_collectdbginfo2)

[**DxgkDdiCollectDbgInfo2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo2)