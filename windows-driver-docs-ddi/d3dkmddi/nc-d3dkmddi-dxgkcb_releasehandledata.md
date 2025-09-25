# DXGKCB_RELEASEHANDLEDATA callback function

## Description

**DXGKCB_RELEASEHANDLEDATA** releases a reference to an allocation.

## Parameters

### `unnamedParam1` [in]

A [**DXGKARGCB_RELEASEHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_releasehandledata) structure containing information about the allocation to be released.

## Remarks

The allocation reference was acquired in a prior call to [**DXGKCB_ACQUIREHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_acquirehandledata).

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_RELEASEHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_releasehandledata) and then call **DxgkCbReleaseHandleData** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_RELEASEHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_releasehandledata)

[**DXGKCB_ACQUIREHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_acquirehandledata)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)