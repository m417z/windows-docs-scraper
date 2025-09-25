# _D3DKMDT_GDISURFACETYPE enumeration

## Description

The D3DKMDT_GDISURFACETYPE enumeration indicates the type of lockable surface that is used by the Desktop Window Manager (DWM) for redirection.

## Constants

### `D3DKMDT_GDISURFACE_INVALID`

The driver should not see this value.

### `D3DKMDT_GDISURFACE_TEXTURE`

Indicates that the surface has the following properties:

* It has a one-level texture.
* It is not visible to the CPU, and the video memory manager will create it as a shared surface.
* It is opened by a user-mode driver and used as a texture during DWM composition.
* It is used by a user-mode driver as a render target for DirectX rendering.
* It is used as a source or destination surface in GDI hardware-accelerated operations.

### `D3DKMDT_GDISURFACE_STAGING_CPUVISIBLE`

Indicates that the surface has the following properties:

* It is visible to the CPU and will be extensively used by the CPU. The allocation must be a linear format and in a cache-coherent GPU aperture segment.
* It is used as a source surface in GDI hardware-accelerated operations.
* It is used as a destination surface in bitblt (copy-only) GDI operations.
* Its pitch must be returned by the display miniport driver.
* Its pitch value and surface address must be aligned to the value of the **AlignmentShift** member of the [DXGK_PRESENTATIONCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps) structure (that is, [DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)->PresentationCaps.AlignmentShift).

### `D3DKMDT_GDISURFACE_STAGING`

Indicates that the surface has the following properties:

* It is not visible to the CPU.
* It is used as a source or destination surface in GDI hardware-accelerated operations.
* It is used as a source or destination surface in GDI bitblt (copy-only) operations.

### `D3DKMDT_GDISURFACE_LOOKUPTABLE`

Indicates that the surface has the following properties:

* It is not visible to the CPU.
* It is used only during processing of commands that are specified by the **ClearTypeBlend** and **OpCode**.DXGK_GDIOP_BITBLT (copy-only) members of the [DXGK_RENDERKM_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_renderkm_command) structure.
* The format is defined by the D3DDDIFMT_A8 value of the [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration.
* The gamma lookup allocation is created one time and never changes after it is initialized. The allocation is initialized in D3DDDIFMT_A8 format by issuing a [DXGK_RENDERKM_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_renderkm_command)->Opcode.DXGK_GDIOP_BITBLT command from a D3DKMDT_GDISURFACE_STAGING_CPUVISIBLE surface.

### `D3DKMDT_GDISURFACE_EXISTINGSYSMEM`

Indicates that the surface has the following properties:

* It is visible to the CPU. The allocation must be a linear format and in a cache-coherent GPU aperture segment.
* Its pitch value and surface address must be aligned to the value of the **AlignmentShift** member of the [DXGK_PRESENTATIONCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps) structure (that is, [DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)->PresentationCaps.AlignmentShift).
* The surface address is passed to the driver.
* This value is used in the same way as the D3DKMDT_GDISURFACE_STAGING_CPUVISIBLE value.

### `D3DKMDT_GDISURFACE_TEXTURE_CPUVISIBLE`

Reserved for system use. Do not use this value in your driver.

Supported starting with Windows 8.

### `D3DKMDT_GDISURFACE_TEXTURE_CROSSADAPTER`

Indicates that the surface has the following properties:

* It is not visible to the CPU, and the video memory manager will create it as a shared cross-adapter surface.
* Its pitch must be returned by the display miniport driver in the **Pitch** member of the [D3DKMDT_GDISURFACEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_gdisurfacedata) structure.
* The pitch and height must have the required alignment for the cross-adapter resource. You can use the **D3DKMT_CROSS_ADAPTER_RESOURCE_PITCH_ALIGNMENT** and **D3DKMT_CROSS_ADAPTER_RESOURCE_HEIGHT_ALIGNMENT** constants to validate that the driver returns the correct pitch and height for the cross-adapter resource. These constants are defined in D3dukmdt.h.

Supported starting with Windows 8.1.

### `D3DKMDT_GDISURFACE_TEXTURE_CPUVISIBLE_CROSSADAPTER`

Reserved for system use. Do not use this value in your driver.

Supported starting with Windows 8.1.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DKMDT_GDISURFACEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_gdisurfacedata)

[DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[DXGK_PRESENTATIONCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps)

[DXGK_RENDERKM_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_renderkm_command)