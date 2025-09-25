# _DXGK_SETVIDPNSOURCEADDRESS_FLAGS structure

## Description

The DXGK_SETVIDPNSOURCEADDRESS_FLAGS structure identifies the specific type of operation to perform in a call to the display miniport driver's [DxgkDdiSetVidPnSourceAddress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560767(v=vs.85)) or [DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay) functions.

## Members

### `ModeChange`

A UINT value that specifies for the driver to switch the display mode.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `FlipImmediate`

A UINT value that specifies for the driver to perform a flip operation that occurs without vertical sync.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `FlipOnNextVSync`

A UINT value that specifies for the driver to perform a flip operation that occurs on the next vertical sync.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `FlipStereo` [in]

Supported beginning with Windows 8.

Specifies whether the driver flips both left and right images of a stereo allocation.

If the **FlipOnNextVSync** member of the **DXGK_SETVIDPNSOURCEADDRESS_FLAGS** structure is set, the driver completes the flip to the left image on the next VSync and then completes the flip to the right image on the following VSync.

If the **FlipImmediate** member of the **DXGK_SETVIDPNSOURCEADDRESS_FLAGS** structure is set, the driver immediately starts to scan out from the new allocation. For example, if the driver was scanning a right image, it starts the new scan from the same relative offset in the right image of the new allocation.

The **FlipStereo** and **FlipStereoTemporaryMono** members cannot both be set at the same time.

For more requirements, see the Remarks section.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `FlipStereoTemporaryMono` [in]

Supported beginning with Windows 8.

Specifies whether the driver uses the left image of a stereo allocation for the right and left portions of a stereo frame. The driver performs the same present operation as with **FlipStereo**, except that it scans out only from the left image to produce both images of a stereo frame.

This member should be set only if the driver reports support for this option in the current display mode by setting the **Type** member of the [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure to D3DKMDT_RMT_GRAPHICS_STEREO_ADVANCED_SCAN.

The **FlipStereo** and **FlipStereoTemporaryMono** members cannot both be set at the same time.

The **FlipStereoTemporaryMono** and **FlipStereoPreferRight** members cannot both be set at the same time.

For more requirements, see the Remarks section.

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `FlipStereoPreferRight` [in]

Supported beginning with Windows 8.

Specifies that when the driver clones a stereo primary allocation to a mono monitor, it uses the right image.

The **FlipStereoTemporaryMono** and **FlipStereoPreferRight** members cannot both be set at the same time.

For more requirements, see the Remarks section.

Setting this member is equivalent to setting the sixth bit of the 32-bit **Value** member (0x00000020).

### `SharedPrimaryTransition` [in]

Supported beginning with Windows 8.

Specifies that the driver is transitioning to or from a shared managed primary allocation.

This member is set if either of the following transitions occurs:

* The current primary allocation is not a shared primary allocation, but the new one is.
* The current primary allocation is a shared primary allocation, but the new one is not.

When **SharedPrimaryTransition** is set, the display miniport driver must validate that the hardware can seamlessly switch back and forth between primary and shared primary allocations, and it must perform any hardware programming needed to make the seamless switch occur.

Setting this member is equivalent to setting the seventh bit of the 32-bit **Value** member (0x00000040).

### `IndependentFlipExclusive` [in]

Supported beginning with Windows 10.

When **IndependentFlipExlusive** is set, the flip is done in the independent flip exclusive mode. The front buffer is accessed only by the display hardware (not by the DWM) and the kernel mode driver can apply vertical sync-related optimizations.

### `MoveFlip` [in]

Supported beginning with Windows 10.

When **MoveFlip** is set, the driver is notified to use any state that has been saved from the previous flip to configure the new scanout request.

### `Reserved` [in]

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 23 bits (0xFFFFFF00) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that DXGK_SETVIDPNSOURCEADDRESS_FLAGS contains that can hold a 32-bit value that identifies operation type.

## Remarks

If any of the **FlipStereo**, **FlipStereoTemporaryMono**, or **FlipStereoPreferRight** members are set, these conditions apply:

* The **hAllocation** member of the [DXGKARG_SETVIDPNSOURCEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress) structure points to an allocation that is created with the **Stereo** member set in the **Flags** member of the [D3DKMT_DISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode) structure.
* The **PrimarySegment** and **PrimaryAddress** members of [DXGKARG_SETVIDPNSOURCEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress) point to the starting physical address of the allocation.
* The driver honors the settings of the **FlipImmediate** and **FlipOnNextVSync** members of the **DXGK_SETVIDPNSOURCEADDRESS_FLAGS** structure.

Beginning with Windows 8, the display miniport driver can fail a call to the [DxgkDdiSetVidPnSourceAddress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560767(v=vs.85)) function, returning STATUS_INVALID_PARAMETER, when the **SharedPrimaryTransition** member is set in *pSetVidPnSourceAddress*->**Flags**. However, such a failure is not expected unless there is an error in either the user mode driver's implementation of the [CheckDirectFlipSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkdirectflipsupport) function or in the Desktop Window Manager (DWM). If such a failure occurs, the operating system will not seamlessly fail back to composition mode, and presentation will be incorrect.

## See also

[D3DKMT_DISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode)

[DXGKARG_SETVIDPNSOURCEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress)

[DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags)

[DxgkDdiSetVidPnSourceAddress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560767(v=vs.85))

[DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay)