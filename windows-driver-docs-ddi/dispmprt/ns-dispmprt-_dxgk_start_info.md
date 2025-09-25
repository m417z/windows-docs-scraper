# _DXGK_START_INFO structure

## Description

The DXGK_START_INFO structure holds information that is needed by the display miniport driver's [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

## Members

### `RequiredDmaQueueEntry`

The number of DMA buffers that the display miniport driver (or the display adapter) must be able to hold in a queue. The display miniport driver must preallocate all resources required to accommodate this number of DMA buffers.

### `AdapterGuid`

A GUID that will serve as an identifier for the adapter being started.

### `AdapterLuid`

Available starting with Windows 8.

A locally unique identifier (LUID) that will serve as an identifier for the adapter being started.

## Remarks

The DirectX graphics kernel subsystem submits DMA buffers to the display miniport driver by calling [DxgkDdiSubmitCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand).

The *DxgkStartInfo* parameter of the [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function is a pointer to a DXGK_START_INFO structure.