# DXGK_SETVIDPNSOURCEADDRESS_INPUT_FLAGS structure

## Description

The **DXGK_SETVIDPNSOURCEADDRESS_INPUT_FLAGS** structure contains the set of flags needed to set the VidPN source address.

## Members

### `FlipStereo`

Specifies whether the driver flips both the left and right images of a stereo allocation.

If the **FlipOnNextVSync** member of the [**DXGK_PLANE_SPECIFIC_INPUT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_plane_specific_input_flags) structure is set, the driver completes the flip to the left image on the next VSync and then completes the flip to the right image on the following VSync.

If the **FlipImmediate** member of **DXGK_PLANE_SPECIFIC_INPUT_FLAGS** is set, the driver immediately starts to scan out from the new allocation. For example, if the driver was scanning a right image, it starts the new scan from the same relative offset in the right image of the new allocation.

The **FlipStereo** and **FlipStereoTemporaryMono** members cannot both be set at the same time.

### `FlipStereoTemporaryMono`

Specifies whether the driver uses the left image of a stereo allocation for the right and left portions of a stereo frame. The driver performs the same present operation as with **FlipStereo**, except that it scans out only from the left image to produce both images of a stereo frame.

This member should be set only if the driver reports support for this option in the current display mode by setting the **Type** member of the [**D3DKMDT_VIDPN_SOURCE_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure to **D3DKMDT_RMT_GRAPHICS_STEREO_ADVANCED_SCAN**.

### `FlipStereoPreferRight`

Specifies that when the driver clones a stereo primary allocation to a mono monitor, it uses the right image.

The **FlipStereoTemporaryMono** and **FlipStereoPreferRight** members cannot both be set at the same time.

### `RetryAtLowerIrql`

The scheduler sets this flag if the call is made at PASSIVE_LEVEL. Hence, the driver can perform hardware changes in this call.

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 28 bits (0xFFFFFFF8) of the 32-bit **Value** member to zeros.

### `Value`

An alternative way to access the bits.

## See also

[**D3DKMDT_VIDPN_SOURCE_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode)

[**DXGK_PLANE_SPECIFIC_INPUT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_plane_specific_input_flags)

[**DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddresswithmultiplaneoverlay3)

[**DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay3)