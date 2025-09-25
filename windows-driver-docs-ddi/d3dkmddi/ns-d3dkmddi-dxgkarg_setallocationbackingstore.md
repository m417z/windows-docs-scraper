## Description

The **DXGKARG_SETALLOCATIONBACKINGSTORE** structure contains the arguments used by the [**DXGKDDI_SETALLOCATIONBACKINGSTORE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setallocationbackingstore) callback function to obtain the system space address to a graphics allocation backing store.

## Members

### `hDriverAllocation`

[in] Handle to the driver allocation object. This handle was returned from [**DXGKDDI_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation).

### `pBackingStore`

[in] Pointer to an address in system space for the allocation backing store. The address is valid until [**DXGKDDI_DESTROYALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyallocation) is called.

## Remarks

See [Sharing the backing store with KMD](https://learn.microsoft.com/windows-hardware/drivers/display/sharing-backing-store-with-kmd) for more information.

## See also

[**DXGKDDI_SETALLOCATIONBACKINGSTORE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setallocationbackingstore)