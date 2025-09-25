# D3DDDI_DRIVERESCAPE_TRANSLATERESOURCEHANDLE structure

## Description

The **D3DDDI_DRIVERESCAPE_TRANSLATERESOURCEHANDLE** structure is used to translate the resource handle to the corresponding host handle.

## Members

### `EscapeType`

A [**D3DDDI_DRIVERESCAPETYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_driverescapetype). Must be set to **D3DDDI_DRIVERESCAPETYPE_TRANSLATERESOURCEHANDLE**.

### `hResource`

[in/out] On entry, a handle to a DirectX graphics resource that was returned from [**DxgkddiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation).

On return, a handle that can be sent to the kernel-mode driver and used in functions such as [**DxgkcbAcquirehandledata**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_acquirehandledata), [**DxgkcbReleasehandledata**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_releasehandledata), [**DxcbGethandledata**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata), and [**DxgkcbGethandleparent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandleparent).

## Remarks

The **D3DDDI_DRIVERESCAPE_TRANSLATERESOURCEHANDLE** structure is used with the **D3DDDI_DRIVERESCAPETYPE_TRANSLATERESOURCEHANDLE** known escape type.

## See also

[**D3DDDI_DRIVERESCAPETYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_driverescapetype)

[**DXGKARG_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_escape)

[**DxgkddiEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape)

[**D3DKMTEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape)