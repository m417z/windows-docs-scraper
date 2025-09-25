# PFND3DDDI_BLT callback function

## Description

The **Blt** function copies the contents of a source surface to a destination surface.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_BLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_blt) structure that describes the parameters of the bit-block transfer (bitblt).

## Return value

**Blt** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The bitblt for the resource is successfully performed. |
| **E_OUTOFMEMORY** | [Blt]() could not allocate the required memory for it to complete. |

## Remarks

The Microsoft Direct3D runtime calls the user-mode display driver's **Blt** function to copy the contents of a source surface to a destination surface. After mapping the surface references to allocation references, the user-mode display driver should issue the appropriate hardware commands. If either the source or destination allocation is in system memory, the user-mode display driver might be required to synchronize (that is, call the [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function) if the outstanding hardware command stream contains references to the system-memory allocation. If both the source and destination allocations are in system memory, the driver should synchronize as necessary but should not copy the contents of the source surface. The Direct3D runtime copies the contents after the call to **pfnRenderCb** returns.

The user-mode display driver must handle the following conditions that might occur during a copy operation:

* The destination and source surfaces are part of the same resource (that is, the **hSrcResource** and **hDstResource** members of [D3DDDIARG_BLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_blt) specify handles to the same resource).
* The source and destination rectangles overlap (that is, the coordinates of the [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structures in the **SrcRect** and **DstRect** members of D3DDDIARG_BLT overlap).

The user-mode display driver must handle all of the bitblt to and from video memory, including bitblt from video memory to system memory. If the user-mode display driver cannot use the graphics processing unit (GPU) to issue a bitblt from video memory to system memory, the user-mode display driver can copy the data by using the CPU.

The user-mode display driver must support colorkeying only with formats that were introduced before Microsoft DirectX 8.0. For formats that were introduced in DirectX 8.0 and later runtimes, colorkeying support is not required.

The type of bitblt to perform is indicated through the bit-field flags that are specified in the **Flags** member of [D3DDDIARG_BLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_blt). Video memory to video memory bitblts can include colorkeying, stretching, mirroring, and linear-to-sRGB format conversion. System memory to video memory bitblts can include stretching and linear-to-sRGB format conversion; however, these types of bitblts never include mirroring or colorkeying. All video memory to system memory bitblts and system memory to system memory bitblts are straight copies only; that is, these types of bitblts never include stretching, mirroring, colorkeying, or linear-to-sRGB format conversion. For more information about sRGB format, see the [sRGB](https://go.microsoft.com/fwlink/p/?linkid=10112) website.

For more information about rules that the **Blt** function must follow when converting depth-stencil values, see [Copying Depth-Stencil Values](https://learn.microsoft.com/windows-hardware/drivers/display/copying-depth-stencil-values).

The Direct3D runtime can call the user-mode display driver's **Blt** function to copy the contents of any source surface type (such as, offscreen-plain type, render-target type, or texture type) to any other destination surface type.

## See also

[D3DDDIARG_BLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_blt)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)