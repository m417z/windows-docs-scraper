# _DXGK_PRESENTATIONCAPS structure

## Description

The DXGK_PRESENTATIONCAPS structure identifies presentation capabilities of a display miniport driver that the driver provides through a call to its [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

## Members

### `NoScreenToScreenBlt` [in]

A UINT value that specifies whether the display miniport driver can perform a bit-block transfer (bitblt) from the primary surface to the same primary surface. If **NoScreenToScreenBlt** is set, the driver cannot perform a screen-to-screen bit-block transfer. Therefore, the Microsoft DirectX graphics kernel subsystem (*Dxgkrnl.sys*) will not request the driver to perform such a bit-block transfer.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `NoOverlapScreenBlt` [in]

A UINT value that specifies whether the display miniport driver can perform a bit-block transfer that overlaps. If **NoOverlapScreenBlt** is set, the driver cannot perform a bit-block transfer that overlaps. Therefore, the DirectX graphics kernel subsystem will not request the driver to perform such a bit-block transfer.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `SupportKernelModeCommandBuffer`

 [in] A UINT value that specifies whether the display miniport driver supports GDI hardware-accelerated command buffer processing. If **SupportKernelModeCommandBuffer** is set, the driver can perform various hardware-accelerated bit-block transfer (bitblt) and fill operations when the DirectX graphics kernel subsystem calls the display miniport driver's [DxgkDdiRenderKm](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm) function.

**Note** A display miniport driver should report that it supports GDI hardware acceleration only if the cache-coherent GPU aperture segment exists and there is no significant performance penalty when the CPU accesses the memory.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

Supported starting with Windows 7.

### `NoSameBitmapAlphaBlend` [in]

A UINT value that specifies whether the display miniport driver can perform an alpha-blending operation when the source and destination allocations are the same. If **NoSameBitmapAlphaBlend** is set, the driver cannot perform such an operation and the DirectX graphics kernel subsystem will not request it.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

Supported starting with Windows 7.

### `NoSameBitmapStretchBlt` [in]

A UINT value that specifies whether the display miniport driver can perform a stretch bit-block transfer operation when the source and destination allocations are the same. If **NoSameBitmapStretchBlt** is set, the driver cannot perform such an operation and the DirectX graphics kernel subsystem will not request it.

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

Supported starting with Windows 7.

### `NoSameBitmapTransparentBlt` [in]

A UINT value that specifies whether the display miniport driver can perform a transparent bit-block transfer operation when the source and destination allocations are the same. If **NoSameBitmapStretchBlt** is set, the driver cannot perform such an operation and the DirectX graphics kernel subsystem will not request it.

Setting this member is equivalent to setting the sixth bit of the 32-bit **Value** member (0x00000020).

Supported starting with Windows 7.

### `NoSameBitmapOverlappedAlphaBlend` [in]

A UINT value that specifies whether the display miniport driver can perform an alpha-blending operation when the source and destination allocations are the same and source and destination rectangles overlap. If **NoSameBitmapOverlappedAlphaBlend** is set, the driver cannot perform such an operation and the DirectX graphics kernel subsystem will not request it.

Setting this member is equivalent to setting the seventh bit of the 32-bit **Value** member (0x00000040).

Supported starting with Windows 7.

### `NoSameBitmapOverlappedStretchBlt` [in]

A UINT value that specifies whether the display miniport driver can perform a stretch bit-block transfer operation when the source and destination allocations are the same and source and destination rectangles overlap. If **NoSameBitmapOverlappedStretchBlt** is set, the driver cannot perform such an operation and the DirectX graphics kernel subsystem will not request it.

Setting this member is equivalent to setting the eight bit of the 32-bit **Value** member (0x00000080).

Supported starting with Windows 7.

### `DriverSupportsCddDwmInterop` [in]

A UINT value that specifies whether the display miniport driver supports Canonical Display Driver (CDD) present operations to texture allocations that are created by the user-mode driver for the Desktop Windows Manager (DWM) to use. If **DriverSupportsCddDwmInterop** is set, the display miniport driver supports such present operations.

If the display miniport driver supports GDI hardware acceleration, **DriverSupportsCddDwmInterop** is ignored. In this case the driver must support present CDD operations to DWM texture allocations that are created by the user-mode driver.

Setting this member is equivalent to setting the ninth bit of the 32-bit **Value** member (0x00000100).

Supported starting with Windows 7.

### `Reserved0` [in]

This member is reserved and should be set to zero.

Setting this member is equivalent to setting the tenth bit of the 32-bit **Value** member (0x00000200).

Supported starting with Windows 7.

### `AlignmentShift` [in]

A UINT value that specifies the minimum alignment value, in bytes, that the **XxxPitch** members of the DXGK_GDIARG_XXX structures require. **AlignmentShift** is given as a binary exponent. For example, to specify a required alignment value of 16 bytes, the display miniport driver should set **AlignmentShift** = 4. The minimum value is **AlignmentShift** = 2, which specifies a 4-byte alignment.

Setting this member is equivalent to setting the eleventh bit of the 32-bit **Value** member (0x00000400).

Supported starting with Windows 7.

### `MaxTextureWidthShift` [in]

A UINT value that specifies the maximum texture width that the display miniport driver supports, which is computed as:

maximum supported texture width = 2 ^ (**MaxTextureWidthShift** + 11) texels.

For example, if **MaxTextureWidthShift** = 0, the maximum supported texture width is 2 ^ 11 = 2048.

Setting this member is equivalent to setting the twelfth bit of the 32-bit **Value** member (0x00000800).

Supported starting with Windows 7.

### `MaxTextureHeightShift` [in]

A UINT value that specifies the maximum texture height that the display miniport driver supports, which is computed as:

maximum supported texture height = 2 ^ (**MaxTextureHeightShift** + 11) texels.

For example, if **MaxTextureHeightShift** = 0, the maximum supported texture height is 2 ^ 11 = 2048.

Setting this member is equivalent to setting the thirteenth bit of the 32-bit **Value** member (0x00001000).

Supported starting with Windows 7.

### `SupportAllBltRops` [in]

A UINT value that specifies whether the display miniport driver supports all GDI ROP3 raster operations with solid color as a pattern in BitBlt and ColorFill commands. If **SupportAllBltRops** is set, the driver supports such raster operations.

Setting this member is equivalent to setting the fourteenth bit of the 32-bit **Value** member (0x00002000).

Supported starting with Windows 7.

### `SupportMirrorStretchBlt` [in]

A UINT value that specifies whether the display miniport driver supports Stretch Blt operations (using the [DXGK_GDIARG_STRETCHBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_stretchblt) structure) in mirror mode. If **SupportMirrorStretchBlt** is set, the driver supports such operations.

Setting this member is equivalent to setting the fifteenth bit of the 32-bit **Value** member (0x00004000).

Supported starting with Windows 7.

### `SupportMonoStretchBltModes` [in]

A UINT value that specifies whether the display miniport driver supports Stretch Blt operations (using the [DXGK_GDIARG_STRETCHBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_stretchblt) structure) in BLACKONWHITE or WHITEONBLACK monochromatic rendering modes. If **SupportMonoStretchBltModes** is set, the driver supports such operations.

Setting this member is equivalent to setting the sixteenth bit of the 32-bit **Value** member (0x00008000).

Supported starting with Windows 7.

### `StagingRectStartPitchAligned` [in]

A UINT value that specifies whether the display miniport driver requires the starting point (upper-left point) in the rectangle on a CPU-visible staging surface to be pitch-aligned, which means that the left coordinate is 0. If **AlignmentShift** is set, the upper-left point of the rectangle is pitch-aligned.

Setting this member is equivalent to setting the seventeenth bit of the 32-bit **Value** member (0x00010000).

Supported starting with Windows 7.

### `NoSameBitmapBitBlt` [in]

A UINT value that specifies whether the display miniport driver can perform a bit-block transfer operation when the source and destination allocations are the same. If **NoSameBitmapBitBlt** is set, the driver cannot perform such an operation. Therefore, the DirectX graphics kernel subsystem will not request that the driver perform such an operation.

Setting this member is equivalent to setting the eighteenth bit of the 32-bit **Value** member (0x00020000).

Supported starting with Windows 7.

### `NoSameBitmapOverlappedBitBlt` [in]

A UINT value that specifies whether the display miniport driver can perform a bit-block transfer operation when the source and destination allocations are the same and source and destination rectangles overlap. If **NoSameBitmapOverlappedBitBlt** is set, the driver cannot perform such an operation and the DirectX graphics kernel subsystem will not request it.

Setting this member is equivalent to setting the nineteenth bit of the 32-bit **Value** member (0x00040000).

Supported starting with Windows 7.

### `Reserved1` [in]

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the twentieth bit of the 32-bit **Value** member (0x00080000).

Supported starting with Windows 7.

### `NoTempSurfaceForClearTypeBlend` [in]

A UINT value that specifies whether the driver needs a temporary surface during processing of commands that are specified by the **ClearTypeBlend** member of the [DXGK_RENDERKM_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_renderkm_command) structure. If **NoTempSurfaceForClearTypeBlend** is set, the driver does not need a temporary surface. In this case, the driver will use less video memory.

Setting this member to zero is equivalent to setting the twenty-first bit of the 32-bit **Value** member (0x00100000).

Supported starting with Windows 7.

### `SupportSoftwareDeviceBitmaps` [in]

This member is reserved and should be set to zero.

Setting this member is equivalent to setting the twenty-second bit of the 32-bit **Value** member (0x00200000).

Supported starting with Windows 8.

### `NoCacheCoherentApertureMemory` [in]

A UINT value that specifies that the driver does not support cache-coherent aperture memory.

Setting this member is equivalent to setting the twenty-third bit of the 32-bit **Value** member (0x00400000).

Supported starting with Windows 8.

### `SupportLinearHeap` [in]

The driver supports linear heap allocation from staging surfaces.

Setting this member is equivalent to setting the twenty-fourth bit of the 32-bit **Value** member (0x00800000).

Supported starting with Windows 8.

### `Reserved` [in]

This member is reserved and should be set to zero.

Setting this member is equivalent to setting the twenty-fifth bit of the 32-bit **Value** member (0x01000000).

Supported starting with Windows 8.

[in] This member is reserved and should be set to zero.

Setting this member is equivalent to setting the twenty-fifth bit of the 32-bit **Value** member (0x02000000).

Supported starting with Windows 8.

### `Value`

A 32-bit value that identifies the driver's presentation capabilities.

## Remarks

A display miniport driver can specify presentation capabilities by setting bits in the 32-bit **Value** member or by setting individual members of the structure in the union that DXGK_PRESENTATIONCAPS contains.

## See also

[D3DKMDT_GDISURFACETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_gdisurfacetype)

[DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

[DxgkDdiRenderKm](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm)