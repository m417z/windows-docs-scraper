# _D3DDDIARG_GETCAPTUREALLOCATIONHANDLE structure

## Description

The D3DDDIARG_GETCAPTUREALLOCATIONHANDLE structure describes the parameters for retrieving an allocation handle from a capture resource handle.

## Members

### `hResource` [in]

A handle to the capture resource that [GetCaptureAllocationHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaptureallocationhandle) retrieves the allocation handle for.

### `hAllocation` [out]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the allocation that is associated with the resource that **hResource** specifies.

## See also

[GetCaptureAllocationHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaptureallocationhandle)