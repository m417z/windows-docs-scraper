# PFNDDXGIDDI_PRESENTCB callback function

## Description

The **pfnPresentCbDXGI** function copies content from a source allocation to a destination allocation.

## Parameters

### `hDevice`

[in] A handle to a display device (graphics context).

### `unnamedParam2`

[in] **pPresentData** is a pointer to a [**DXGIDDICB_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_present) structure that describes the source and destination allocations that content is copied from and to.

## Return value

**pfnPresentCbDXGI** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | Content was successfully copied. |
| **E_OUTOFMEMORY** | pfnPresentCbDXGI could not complete because of insufficient memory. |
| **E_INVALIDARG** | Parameters were validated and determined to be incorrect. |

## Remarks

The **pDXGIContext** member of the [**DXGIDDICB_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_present) structure that the **pPresentData** parameter points to is an opaque communication mechanism. The runtime passes this DXGI context to the driver in the **pDXGIContext** member of the [**DXGI_DDI_ARG_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present) structure when the runtime calls the driver's [**PresentDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function. The driver should copy this DXGI context unchanged to the **pDXGIContext** member of DXGIDDICB_PRESENT when the driver calls **pfnPresentCbDXGI**.

The Direct3D runtime restricts the set of formats that can be presented through a bit-block transfer (bitblt) operation. For more information about the restrictions, see the Remarks section of the [**BltDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) reference page.

## See also

[**BltDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[**CreateDevice(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[**DXGIDDICB_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_present)

[**DXGI_DDI_ARG_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present)

[**DXGI_DDI_BASE_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_callbacks)

[**PresentDXGI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)