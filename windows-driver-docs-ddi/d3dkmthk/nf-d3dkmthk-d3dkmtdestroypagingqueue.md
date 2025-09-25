# D3DKMTDestroyPagingQueue function

## Description

**D3DKMTDestroyPagingQueue** waits for a paging queue to finish all operations queued to it, and destroys it along with the associated sync object.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DDDI_DESTROYPAGINGQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_destroypagingqueue) structure that describes the operation.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The operation was performed successfully.|

This function might also return other **NTSTATUS** values.

## Remarks

In addition to **hPagingQueue**, this device driver interface (DDI) invalidates **hSyncObject** and **FenceValueCPUVirtualAddress** values returned from [D3DKMTCreatePagingQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatepagingqueue).

## See also

[D3DDDI_DESTROYPAGINGQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_destroypagingqueue)

[D3DKMTCreatePagingQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatepagingqueue)