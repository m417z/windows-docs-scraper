# DXGK_RENDERKM_COMMAND structure

## Description

The **DXGK_RENDERKM_COMMAND** structure is used to construct a command buffer to control GDI hardware-accelerated rendering.

## Members

### `OpCode`

[in] A [**DXGK_RENDERKM_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_renderkm_operation)-type operation code that identifies the GDI hardware-accelerated rendering operation to process. For more information about GDI hardware acceleration, see the Remarks section.

### `CommandSize`

[in] The size of the current command, in bytes. This is equal to the number of bytes from the beginning of DXGK_RENDERKM_COMMAND up to the next command.

### `Command`

The command.

### `Command.BitBlt`

[in] A bit-block transfer (bitblt) that is described by a [**DXGK_GDIARG_BITBLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_bitblt) structure.

### `Command.ColorFill`

[in] A color fill that is described by a [**DXGK_GDIARG_COLORFILL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_colorfill) structure.

### `Command.AlphaBlend`

[in] An alpha blend that is described by a [**DXGK_GDIARG_ALPHABLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_alphablend) structure.

### `Command.StretchBlt`

[in] A stretch bit-block transfer that is described by a [**DXGK_GDIARG_STRETCHBLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_stretchblt) structure.

### `Command.TransparentBlt`

[in] A transparent bit-block transfer that is described by a [**DXGK_GDIARG_TRANSPARENTBLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_transparentblt) structure.

### `Command.ClearTypeBlend`

[in] A ClearType blend that is described by a [**DXGK_GDIARG_CLEARTYPEBLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_cleartypeblend) structure.

## Remarks

An array of variable-size DXGK_RENDERKM_COMMAND structures defines a command buffer that is used to control GDI hardware-accelerated rendering.

A display miniport driver should report that it supports command buffer processing for GDI hardware acceleration by setting [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)->**PresentationCaps**.**SupportKernelModeCommandBuffer** to TRUE.

A display miniport driver should report that it supports GDI hardware acceleration only if the cache-coherent GPU aperture segment exists, and there is no significant performance penalty when the CPU accesses the memory.

Each command varies in length depending on the value of the **OpCode** member and the number of sub-rectangles in the command.

## See also

[**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[**DXGK_GDIARG_ALPHABLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_alphablend)

[**DXGK_GDIARG_BITBLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_bitblt)

[**DXGK_GDIARG_CLEARTYPEBLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_cleartypeblend)

[**DXGK_GDIARG_COLORFILL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_colorfill)

[**DXGK_GDIARG_STRETCHBLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_stretchblt)

[**DXGK_GDIARG_TRANSPARENTBLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_transparentblt)

[**DXGK_PRESENTATIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps)

[**DXGK_RENDERKM_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_renderkm_operation)