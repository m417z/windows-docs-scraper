# DXGI1_3_DDI_BASE_FUNCTIONS structure

## Description

Contains pointers to functions that a Windows Display Driver Model (WDDM) 1.3 and later user-mode display driver can implement to perform low-level tasks like presenting rendered frames to an output, controlling gamma, getting notifications regarding shared and Windows Graphics Device Interface (GDI) interoperable surfaces, and managing a full-screen transition.

## Members

### `pfnPresent`

A pointer to the driver's [PresentDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

### `pfnGetGammaCaps`

A pointer to the driver's [GetGammaCapsDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

### `pfnSetDisplayMode`

A pointer to the driver's [SetDisplayModeDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions) function.

### `pfnSetResourcePriority`

A pointer to the driver's [SetResourcePriorityDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

### `pfnQueryResourceResidency`

A pointer to the driver's [QueryResourceResidencyDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

### `pfnRotateResourceIdentities`

A pointer to the driver's [RotateResourceIdentitiesDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

### `pfnBlt`

A pointer to the driver's [BltDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

### `pfnResolveSharedResource`

A pointer to the driver's [ResolveSharedResourceDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions) function.

### `pfnBlt1`

A pointer to the driver's [Blt1DXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions) function.

### `pfnOfferResources`

A pointer to the driver's [pfnOfferResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerresources) function.

### `pfnReclaimResources`

A pointer to the driver's [pfnReclaimResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions) function.

### `pfnGetMultiplaneOverlayCaps`

Called by the DXGI runtime to request that the user-mode display driver get basic overlay plane capabilities. Optionally implemented by WDDM 1.3 and later user-mode display drivers.

### `pfnGetMultiplaneOverlayGroupCaps`

Called by the DXGI runtime to request that the user-mode display driver get a group of overlay plane capabilities. Optionally implemented by WDDM 1.3 and later user-mode display drivers.

**Note** This function is called for each of the capability groups that the driver reports.

**Syntax**

```cpp
pfnGetMultiplaneOverlayGroupCaps GetMultiplaneOverlayGroupCaps;

HRESULT __stdcall* GetMultiplaneOverlayGroupCaps(
   DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS *pGroupCaps
)
{ ... }
```

**Parameter**

*pGroupCaps* A pointer to a [DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-_dxgi_ddi_arg_getmultiplaneoverlaygroupcaps) structure that specifies the group of overlay plane capabilities.

**Return value**

Returns one of the following values.

* **S_OK** The driver successfully provided the overlay plane capabilities.
* **D3DDDIERR_DEVICEREMOVED** The driver detected that the display adapter was removed, so the driver did not complete the operation. If the driver is not aware of the adapter removal, the driver is not required to return this error code.

### `pfnReserved1`

Reserved for system use.

### `pfnPresentMultiplaneOverlay`

Called by the Microsoft DirectX Graphics Infrastructure (DXGI) runtime to notify the user-mode display driver that an application finished rendering and requests that the driver display the source surface by either copying or flipping or that the driver perform a color-fill operation. Must be implemented by Windows Display Driver Model (WDDM) 1.3 or later drivers that support multiplane overlays.

When the user-mode display driver successfully completes its processing of a call to this function, it presents the source surface to the display by calling the [pfnPresentMultiPlaneOverlayCb (DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_present_multiplane_overlaycb) function.

```cpp
PFND3DDDI_PRESENTMULTIPLANEOVERLAY pfnPresentMultiPlaneOverlay;

HRESULT __stdcall* pfnPresentMultiPlaneOverlay(
   DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY *pPresentDXGI
)
{ ... }
```

**Parameter**

*pPresentDXGI* A pointer to a [DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-_dxgi_ddi_arg_presentmultiplaneoverlay) structure that describes how to display to the destination surface.

**Return value**

If this callback function succeeds, it returns S_OK. Otherwise it returns an HRESULT error code.

### `pfnReserved2`

Reserved for system use.

### `pfnPresent1`

Notifies the user-mode display driver that an application finished rendering and that all ownership of the shared resource is released, and requests that the driver display to the destination surface.

**Syntax**

```cpp
pfnPresent1 Present1DXGI;

HRESULT __stdcall* Present1DXGI(
   DXGI_DDI_ARG_PRESENT1 *pPresentData
)
{ ... }
```

**Parameter**

*pPresentData* [in] A pointer to a [DXGI_DDI_ARG_PRESENT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present1) structure that describes how to display to the destination surface.

#### Remarks

The **hDevice** member of the [DXGI_DDI_ARG_PRESENT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present1) structure that the *pPresentData* parameter points to is the same handle that the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function passed back to the runtime in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure. Therefore, driver writers must define the type of this handle carefully. In addition, drivers can supply different implementations of the [pfnPresent1(DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_3_ddi_base_functions) function based on which DDI implementation handled the call to *CreateDevice(D3D10)*. The runtime will never mix driver handles across DDI implementations.

The **pDXGIContext** member of [DXGI_DDI_ARG_PRESENT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present1) is an opaque communication mechanism. The runtime passes this DXGI context to the driver. The driver should copy this DXGI context unchanged to the **pDXGIContext** member of the [DXGIDDICB_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_present) structure when the driver calls the [pfnPresentCbDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb) function.

The driver must submit all partially built render data (command buffers) using the [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function, and the driver must make a single call to [pfnPresentCbDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb). When calling either of these callbacks, the driver must follow the threading rules of the [PresentDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function.

**Note** When the driver's [pfnPresent1(DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_3_ddi_base_functions) function copies sRGB-formatted content from a source surface to a non-sRGB destination surface, the driver should copy the sRGB content unchanged (that is, the driver should not perform the sRGB to linear conversion).

#### Threading rules

These rules apply whether the driver supports free threading or not:

* The driver indicates support for free threading by setting the **Caps** member of the [D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps) structure to **D3D11DDICAPS_FREETHREADED**. In this case:
  + Only a single thread can be working against an HCONTEXT context handle at a time.
  + The driver must call [pfnPresentCbDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb) only when the driver’s [pfnPresent1(DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_3_ddi_base_functions) function is called, and by the same thread that called *pfnPresent1(DXGI)*.
* When the driver doesn’t indicate support for free-threading, it can only call the callback functions when a thread has called into the driver. The driver also must still call the [pfnPresentCbDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb) callback within the context of [pfnPresent1(DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_3_ddi_base_functions).

For further info on threading, see [Changes from Direct3D 10](https://learn.microsoft.com/windows-hardware/drivers/display/changes-from-direct3d-10).

### `pfnCheckPresentDurationSupport`

A pointer to the driver's [pfnCheckPresentDurationSupport(DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-_dxgi_ddi_arg_checkpresentdurationsupport) function.

## Remarks

For more info on how to use this structure, see [Supporting the DXGI DDI](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-the-dxgi-ddi).

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)

[DXGI1_2_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions)

[DXGI_DDI_BASE_ARGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_args)

[DXGI_DDI_BASE_FUNCTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)