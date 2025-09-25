# _D3DKMT_PRESENTFLAGS structure

## Description

The D3DKMT_PRESENTFLAGS structure identifies how to perform a present operation.

## Members

### `Blt`

A UINT value that specifies whether to bit-block transfer (bitblt) data to the primary surface. This bit-field flag can be used with the **DstRectValid** and **SrcRectValid** bit-field flags.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `ColorFill`

A UINT value that specifies whether to perform a colorfill bitblt to the primary surface by using the value in the **Color** member of the [D3DKMT_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present) structure. This bit-field flag can be used with the **DstRectValid** bit-field flag.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `Flip`

A UINT value that specifies whether to flip to a new surface.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `FlipDoNotFlip`

A UINT value that specifies whether to insert queued waits into the rendering stream. Setting this member indicates to flip to the same surface that is currently being scanned out.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `FlipDoNotWait`

A UINT value that specifies whether the OpenGL installable client driver (ICD) requires that the present operation wait for the number of queued flip surfaces to fall below a particular limit before the operation begins. Setting this member indicates that the ICD does not require waiting. The default limit for the number of queued flip surfaces is three.

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `FlipRestart`

A UINT value that specifies whether to restart a flip to a new surface.

Setting this member is equivalent to setting the sixth bit of the 32-bit **Value** member (0x00000020).

### `DstRectValid`

A UINT value that specifies whether the bitblt uses a destination rectangular area.

Setting this member is equivalent to setting the seventh bit of the 32-bit **Value** member (0x00000040).

### `SrcRectValid`

A UINT value that specifies whether the bitblt uses a source rectangular area.

Setting this member is equivalent to setting the eighth bit of the 32-bit **Value** member (0x00000080).

### `RestrictVidPnSource`

A UINT value that specifies whether to restrict the bitblt. If the **hWindow** member is **NULL**, the **VidPnSourceId** member of the [D3DKMT_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present) structure indicates which output the full-screen bitblt is directed to; if **hWindow** is non-**NULL**, **VidPnSourceId** indicates which output to restrict the windowed bitblt to.

Setting this member is equivalent to setting the ninth bit of the 32-bit **Value** member (0x00000100).

### `SrcColorKey`

A UINT value that specifies whether to perform source color-keying by using the value in the **Color** member of the [D3DKMT_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present) structure. That is, any pixel in the source surface that matches the color key should not be copied to the destination surface, and all of the source pixels that do not match the color key should be copied.

Setting this member is equivalent to setting the tenth bit of the 32-bit **Value** member (0x00000200).

### `DstColorKey`

A UINT value that specifies whether to perform destination color-keying by using the value in the **Color** member of D3DKMT_PRESENT. That is, any pixel in the destination surface that matches the color key should be replaced with the corresponding pixel from the source surface, and all of the destination pixels that do not match the color key should not be replaced.

Setting this member is equivalent to setting the eleventh bit of the 32-bit **Value** member (0x00000400).

### `LinearToSrgb`

A UINT value that specifies whether to convert the linear-formatted source to sRGB format during the copy operation. sRGB format is gamma corrected. For more information about sRGB format, see the [sRGB](https://go.microsoft.com/fwlink/p/?linkid=10112) website.

Setting this member is equivalent to setting the twelfth bit of the 32-bit **Value** member (0x00000800).

### `PresentCountValid`

A UINT value that specifies whether the value set in the **PresentCount** member of the [D3DKMT_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present) structure is valid.

Setting this member is equivalent to setting the thirteenth bit of the 32-bit **Value** member (0x00001000).

### `Rotate` [in]

A UINT value that specifies whether to rotate the presentation data to match the current orientation of the screen during the presentation bit-block transfer (bitblt). The current orientation of the screen is set in the **Rotation** member of a [D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation) structure, which is set in the **ContentTransformation** member of the [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure for the video present path.

The display miniport driver should rotate the data only if the **Rotate** bit-field flag is set. Even if the driver determines that the current orientation of the screen is rotated from the presentation data and **Rotate** is not set, the driver should not rotate the data.

Setting this member is equivalent to setting the fourteenth bit of the 32-bit **Value** member (0x00002000).

### `PresentToBitmap`

A UINT value that specifies whether to present to a bitmap.

Setting this member is equivalent to setting the fifteenth bit of the 32-bit **Value** member (0x00004000).

Supported starting with Windows 7.

### `RedirectedFlip`

A UINT value that specifies whether to redirect a flip to a new surface.

Setting this member is equivalent to setting the sixteenth bit of the 32-bit **Value** member (0x00008000).

Supported starting with Windows 7.

### `RedirectedBlt`

A UINT value that specifies whether to redirect a bitblt to a new surface.

Setting this member is equivalent to setting the seventeenth bit of the 32-bit **Value** member (0x00010000).

Supported starting with Windows 7.

### `FlipStereo`

Specifies whether the driver should flip both left and right images of a stereo allocation.

If the **FlipOnNextVSync** member of the [DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags) structure is set, the driver should complete the flip to the left image on the next VSync and then complete the flip to the right image on the following VSync.

If the **FlipImmediate** member of the [DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags) structure is set, the driver should immediately start to scan out from the new allocation. For example, if the driver was scanning a right image, it should start the new scan from the same relative offset in the right image of the new allocation.

The **FlipStereo** and **FlipStereoTemporaryMono** members cannot both be set at the same time.

For more requirements, see the Remarks section.

Setting this member is equivalent to setting the eighteenth bit of the 32-bit **Value** member (0x00020000).

Supported starting with Windows 8.

### `FlipStereoTemporaryMono`

Specifies whether the driver should use the left image of a stereo allocation for the right and left portions of a stereo frame. The driver performs the same present operation as with **FlipStereo**, except that it should scan out only from the left image to produce both images of a stereo frame.

This member should be set only if the driver reports support for this option in the current display mode by setting the **Type** member of the [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure to D3DKMDT_RMT_GRAPHICS_STEREO_ADVANCED_SCAN.

The **FlipStereo** and **FlipStereoTemporaryMono** members cannot both be set at the same time.

The **FlipStereoTemporaryMono** and **FlipStereoPreferRight** members cannot both be set at the same time.

For more requirements, see the Remarks section.

Setting this member is equivalent to setting the nineteenth bit of the 32-bit **Value** member (0x00040000).

Supported starting with Windows 8.

### `FlipStereoPreferRight`

Specifies that when the driver clones a stereo primary allocation to a mono monitor, it should use the right image.

The **FlipStereoTemporaryMono** and **FlipStereoPreferRight** members cannot both be set at the same time.

For more requirements, see the Remarks section.

Setting this member is equivalent to setting the twentieth bit of the 32-bit **Value** member (0x00080000).

Supported starting with Windows 8.

### `BltStereoUseRight`

Specifies that when the driver presents from a stereo allocation to a mono allocation, it should use the right image. If not set, the driver should use the left image.

Setting this member is equivalent to setting the twenty-first bit of the 32-bit **Value** member (0x00100000).

Supported starting with Windows 8.

### `PresentHistoryTokenOnly`

Specifies that the driver should submit only a present history token.

A *present history token* is a data packet that the rendering app submits to inform the Desktop Window Manager (DWM) that rendering is complete and the swap chain back buffer is ready to be presented.

Setting this member is equivalent to setting the twenty-second bit of the 32-bit **Value** member (0x00200000).

Supported starting with Windows 8.

### `PresentRegionsValid`

Specifies that the [D3DKMT_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present).**pPresentRegions** member is a valid pointer (not **NULL**).

Setting this member is equivalent to setting the twenty-third bit of the 32-bit **Value** member (0x00400000).

Supported starting with Windows 8.

### `PresentDDA`

This member is reserved and should be set to zero.

Setting this member is equivalent to setting the twenty-fourth bit of the 32-bit **Value** member (0x00800000).

Supported starting with Windows 8.

### `ProtectedContentBlankedOut`

This member is reserved and should be set to zero.

Setting this member is equivalent to setting the twenty-fifth bit of the 32-bit **Value** member (0x01000000).

Supported starting with Windows 8.

### `RemoteSession`

Specifies that the present operation is directed to a remote session.

Setting this member is equivalent to setting the twenty-sixth bit of the 32-bit **Value** member (0x02000000).

Supported starting with Windows 8.

### `CrossAdapter`

The cross adapter.

### `DurationValid`

Indicates whether the duration is valid.

### `PresentIndirect`

Present indirect.

### `PresentHMD`

### `Reserved`

Supported starting with Windows 8.

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 9 bits (0xFF800000) of the 32-bit **Value** member to zeros.

### `Value`

A 32-bit value that identifies how to perform the present operation.

## Remarks

If any of the **FlipStereo**, **FlipStereoTemporaryMono**, or **FlipStereoPreferRight** members are set, these conditions apply:

* The **hAllocation** member of the [DXGKARG_SETVIDPNSOURCEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress) structure should point to an allocation that is created with the **Stereo** member set in the **Flags** member of the [D3DKMT_DISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode) structure.
* The **PrimarySegment** and **PrimaryAddress** members of [DXGKARG_SETVIDPNSOURCEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress) should point to the starting physical address of the allocation.
* The driver should honor the settings of the **FlipImmediate** and **FlipOnNextVSync** members of the [DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags) structure.

## See also

[D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path)

[D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation)

[D3DKMT_DISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode)

[D3DKMT_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present)

[DXGKARG_SETVIDPNSOURCEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress)

[DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags)