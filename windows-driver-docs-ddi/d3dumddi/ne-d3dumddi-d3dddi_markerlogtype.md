# D3DDDI_MARKERLOGTYPE enumeration

## Description

Indicates the type of marker in the Event Tracing for Windows (ETW) log that the user-mode display driver supports.

## Constants

### `D3DDDIMLT_NONE`

No marker type is supported. In this case, the marker type of submitted commands must be [**D3DDDI_MARKERTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_markertype).**D3DDDIMT_NONE**.

### `D3DDDIMLT_PROFILE`

The context submits GPU work for single-threaded user-mode DDIs. In this case, each time stamp denotes the end of GPU work.

### `D3DDDIMLT_FT_PROFILE`

The context submits GPU work for free-threaded user-mode DDIs. In this case, the driver must have set the **Caps** member of the [**D3D11DDI_THREADING_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps) structure to **D3D11DDICAPS_FREETHREADED**.

### `D3DDDIMLT_BATCHED`

The driver is submitting data that may correspond to multiple command lists in a single submission. If the D3D12 runtime calls [**ExecuteCommandLists**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-executecommandlists) with multiple command lists, the driver must use the batched marker mode when submitting history buffers.

## See also

[**D3D11DDI_THREADING_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps)

[**D3DDDI_MARKERTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_markertype)

[**ExecuteCommandLists**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-executecommandlists)