# DXGKCB_SAVEMEMORYFORHOTUPDATE callback function

## Description

A kernel-mode display miniport driver can call **DXGKCB_SAVEMEMORYFORHOTUPDATE** to save adapter memory to support driver hot update.

## Parameters

### `hAdapter` [in]

A handle to the DXGK adapter that is passed to [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `pArgs` [in]

A pointer to the [DXGKARGCB_SAVEMEMORYFORHOTUPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_savememoryforhotupdate) structure that contains arguments for this callback.

## Return value

**DXGKCB_SAVEMEMORYFORHOTUPDATE** returns STATUS_SUCCESS if the operation succeeds; otherwise it returns an error code from *Ntstatus.h*.

## Remarks

Each call to **DXGKCB_SAVEMEMORYFORHOTUPDATE** saves a block of physical memory pages, as well as optionally metadata that the driver wants to associate with the memory block. When the pages are restored, the driver will get a separate call for each saved memory block together with metadata.

For convenience, the callback provides 3 options to save physical memory:

* As an array of contiguous physical memory ranges (**pDataMemoryRanges**)
* As an MDL (**pDataMdl**)
* As virtual memory buffer (**pData**)

One (and only one) of the pointers to data (**pDataMemoryRanges**, **pDataMdl** or **pData**) must be not NULL.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_SAVEMEMORYFORHOTUPDATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_savememoryforhotupdate) and then call **DxgkCbSaveMemoryForHotUpdate** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[DXGKARGCB_SAVEMEMORYFORHOTUPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_savememoryforhotupdate)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)