# D3DDDI_DESTROYPAGINGQUEUE structure

## Description

**D3DDDI_DESTROYPAGINGQUEUE** is used with [pfnDestroyPagingQueueCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroypagingqueuecb) and [D3DKMTDestroyPagingQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroypagingqueue) to wait for a paging queue to finish all operations queued to it and destroy it along with the associated sync object.

## Members

### `hPagingQueue` [in]

A paging queue handle to be destroyed.

## See also

[D3DKMTDestroyPagingQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroypagingqueue)

[pfnDestroyPagingQueueCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroypagingqueuecb)