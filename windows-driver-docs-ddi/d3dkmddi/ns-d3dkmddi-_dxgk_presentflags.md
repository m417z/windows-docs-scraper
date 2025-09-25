# _DXGK_PRESENTFLAGS structure

## Description

The DXGK_PRESENTFLAGS structure identifies, in bit-field flags, the type of present operation to perform.

## Members

### `Blt` [in]

A UINT value that specifies whether a copy operation, instead of a flip operation, occurs between source and destination surfaces.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `ColorFill` [in]

A UINT value that specifies whether a source exists to present from. If this member is set, no source exists, and the driver should fill the destination rectangle on the destination surface with the A8R8G8B8 color that the **Color** member of the [DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present) structure specifies.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `Flip` [in]

A UINT value that specifies whether a flip operation occurs between back and primary surfaces. If this member is set, the driver should perform the present operation by pointing the video scan output to the source rather than copying from the source to the destination. This type of present operation is tear-free.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `FlipWithNoWait` [in]

A UINT value that specifies whether tear-free flip operations should not stall the graphics pipeline. If a tear-free flip stalls the graphics pipeline, the graphics processing unit (GPU) must wait for the tear-free flip to take effect before it runs the subsequent command.

**FlipWithNoWait** can be set to **TRUE** (that is, 1) only if the display miniport driver set the **FlipOnVSyncWithNoWait** bit-field flag in the **FlipCaps** member of the [DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure when the DXGKQAITYPE_DRIVERCAPS value was specified in the **Type** member of the [DXGKARG_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo) structure in a call to the driver's [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `SrcColorKey` [in]

A UINT value that specifies whether to perform source color-keying by using the value in the **Color** member of the [DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present) structure. That is, any pixel in the source surface that matches the color key should not be copied to the destination surface, and all of the source pixels that do not match the color key should be copied.

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `DstColorKey` [in]

A UINT value that specifies whether to perform destination color-keying by using the value in the **Color** member of the [DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present) structure. That is, any pixel in the destination surface that matches the color key should be replaced with the corresponding pixel from the source surface, and all destination pixels that do not match the color key should not be replaced.

Setting this member is equivalent to setting the sixth bit of the 32-bit **Value** member (0x00000020).

### `LinearToSrgb` [in]

A UINT value that specifies whether to convert the linear-formatted source to sRGB format during the copy operation. sRGB format is gamma corrected. For more information about the sRGB format, visit the [sRGB](https://go.microsoft.com/fwlink/p/?linkid=10112) website.

Setting this member is equivalent to setting the seventh bit of the 32-bit **Value** member (0x00000040).

### `Rotate` [in]

A UINT value that specifies whether to rotate the presentation data to match the current orientation of the screen during the presentation bit-block transfer (bitblt). The current orientation of the screen is set in the **Rotation** member of a [D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation) structure, which is set in the **ContentTransformation** member of the [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure for the video present path.

The display miniport driver should rotate the data only if the **Rotate** bit-field flag is set. Even if the driver determines that the current orientation of the screen is rotated from the presentation data and **Rotate** is not set, the driver should not rotate the data.

Setting this member is equivalent to setting the eighth bit of the 32-bit **Value** member (0x00000080).

### `FlipStereo` [in]

Specifies whether the driver should flip both left and right images of a stereo allocation.

If the **FlipOnNextVSync** member of the [DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags) structure is set, the driver should complete the flip to the left image on the next VSync and then complete the flip to the right image on the following VSync.

If the **FlipImmediate** member of the [DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags) structure is set, the driver should immediately start to scan out from the new allocation. For example, if the driver was scanning a right image, it should start the new scan from the same relative offset in the right image of the new allocation.

The **FlipStereo** and **FlipStereoTemporaryMono** members cannot both be set at the same time.

For more requirements, see the Remarks section.

Setting this member is equivalent to setting the ninth bit of the 32-bit **Value** member (0x00000100).

Supported starting with Windows 8.

### `FlipStereoTemporaryMono` [in]

Specifies whether the driver should use the left image of a stereo allocation for the right and left portions of a stereo frame. The driver performs the same present operation as with **FlipStereo**, except that it should scan out only from the left image to produce both images of a stereo frame.

This member should be set only if the driver reports support for this option in the current display mode by setting the **Type** member of the [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure to D3DKMDT_RMT_GRAPHICS_STEREO_ADVANCED_SCAN.

The **FlipStereo** and **FlipStereoTemporaryMono** members cannot both be set at the same time.

The **FlipStereoTemporaryMono** and **FlipStereoPreferRight** members cannot both be set at the same time.

For more requirements, see the Remarks section.

Setting this member is equivalent to setting the tenth bit of the 32-bit **Value** member (0x00000200).

Supported starting with Windows 8.

### `FlipStereoPreferRight` [in]

Specifies that when the driver clones a stereo primary allocation to a mono monitor, it should use the right image.

The **FlipStereoTemporaryMono** and **FlipStereoPreferRight** members cannot both be set at the same time.

For more requirements, see the Remarks section.

Setting this member is equivalent to setting the eleventh bit of the 32-bit **Value** member (0x00000400).

Supported starting with Windows 8.

### `BltStereoUseRight` [in]

Specifies that when the driver presents from a stereo allocation to a mono allocation, it should use the right image. If not set, the driver should use the left image.

Setting this member is equivalent to setting the twelfth bit of the 32-bit **Value** member (0x00000800).

Supported starting with Windows 8.

### `FlipWithMultiPlaneOverlay` [in]

Specifies whether a flip operation occurs between an overlay plane and the primary surface. If this member is set, the driver should perform the present operation by pointing the video scan output to the source plane rather than copying from the source plane to the destination.

Setting this member is equivalent to setting the thirteenth bit of the 32-bit **Value** member (0x00001000).

Supported starting with Windows 8.1.

### `RedirectedFlip`

### `Reserved` [in]

This member is reserved and should be set to zero.

Setting this member to zero is equivalent to setting the remaining 19 bits (0xFFFFE000) of the 32-bit **Value** member to zeros.

Supported starting with Windows 8.

[in] This member is reserved and should be set to zero.

Setting this member to zero is equivalent to setting the remaining 24 bits (0xFFFFFF00) of the 32-bit **Value** member to zeros.

### `Value` [in]

A member in the union that DXGK_PRESENTFLAGS contains that can hold a 32-bit value that identifies the type of present operation to perform.

## Remarks

The **ColorFill**, **SrcColorKey**, and **DstColorKey** bit-field flags are mutually exclusive.

If any of the **FlipStereo**, **FlipStereoTemporaryMono**, or **FlipStereoPreferRight** members are set, these conditions apply:

* The **hAllocation** member of the [DXGKARG_SETVIDPNSOURCEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress) structure should point to an allocation that is created with the **Stereo** member set in the **Flags** member of the [D3DKMT_DISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode) structure.
* The **PrimarySegment** and **PrimaryAddress** members of [DXGKARG_SETVIDPNSOURCEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress) should point to the starting physical address of the allocation.
* The driver should honor the settings of the **FlipImmediate** and **FlipOnNextVSync** members of the [DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags) structure.

## See also

[D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path)

[D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path_transformation)

[D3DKMT_DISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode)

[DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present)

[DXGKARG_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[DXGKARG_SETVIDPNSOURCEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress)

[DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)

[DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)