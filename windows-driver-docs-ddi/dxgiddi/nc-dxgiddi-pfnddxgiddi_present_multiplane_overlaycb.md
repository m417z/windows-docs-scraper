# PFNDDXGIDDI_PRESENT_MULTIPLANE_OVERLAYCB callback function

## Description

**PFNDDXGIDDI_PRESENT_MULTIPLANE_OVERLAYCB** is called by the DirectX Graphics Infrastructure (DXGI) runtime to notify the user-mode display driver that an application finished rendering and requests that the driver display the source surface by either copying or flipping or that the driver perform a color-fill operation. Must be implemented by Windows Display Driver Model (WDDM) 1.3 or later drivers that support multiplane overlays.

## Parameters

### `hDevice`

A handle to a display device (graphics context).

### `unnamedParam2`

**pPresentDXGI** is a pointer to a [**DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-_dxgi_ddi_arg_presentmultiplaneoverlay) structure that describes how to display to the destination surface.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the user-mode display driver successfully completes its processing of a call to this function, it presents the source surface to the display by calling the [**pfnPresentMultiPlaneOverlayCb (DXGI)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_present_multiplane_overlaycb) function.

## See also

[**DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-_dxgi_ddi_arg_presentmultiplaneoverlay)

[**pfnPresentMultiPlaneOverlayCb (DXGI)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_present_multiplane_overlaycb)