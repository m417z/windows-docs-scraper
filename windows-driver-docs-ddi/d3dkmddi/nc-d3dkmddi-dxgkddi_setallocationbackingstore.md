## Description

**DXGKDDI_SETALLOCATIONBACKINGSTORE** obtains the system space address to a graphics allocation backing store.

## Parameters

### `hAdapter`

[in] Handle to the miniport's context.

### `pArgs`

[in] Pointer to a [**DXGKARG_SETALLOCATIONBACKINGSTORE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_setallocationbackingstore) structure that contains additional arguments for this function.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code.

## Remarks

The address that **pBackingStore** points to is valid until the allocation is destroyed by [**DXGKDDI_DESTROYALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyallocation).

**DXGKDDI_SETALLOCATIONBACKINGSTORE** is called during [**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation).

See [Sharing the backing store with KMD](https://learn.microsoft.com/windows-hardware/drivers/display/sharing-backing-store-with-kmd) for more information.

## See also

[**DXGKARG_SETALLOCATIONBACKINGSTORE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_setallocationbackingstore)