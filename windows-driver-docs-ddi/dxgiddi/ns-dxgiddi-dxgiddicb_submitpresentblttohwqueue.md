# DXGIDDICB_SUBMITPRESENTBLTTOHWQUEUE structure

## Description

Contains arguments needed for the [PfnddxgiddiSubmitPresentBltToHwQueuecb](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_submitpresentblttohwqueuecb) function.

## Members

### `hSrcAllocation` [in]

The allocation of which content will be presented.

### `hDstAllocation` [in]

The destination allocation of the present.

### `pDXGIContext`

Fill this with the value in [DXGI_DDI_ARG_PRESENT.pDXGIContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present).

### `hHwQueue`

Hardware queue being submitted to.

### `HwQueueProgressFenceId`

Hardware queue progress fence ID that will be signaled when the Present Blt is done on the GPU.

### `PrivateDriverDataSize`

The size of pPrivateDriverData.

### `pPrivateDriverData` [in]

Private driver data to pass to DdiPresent.