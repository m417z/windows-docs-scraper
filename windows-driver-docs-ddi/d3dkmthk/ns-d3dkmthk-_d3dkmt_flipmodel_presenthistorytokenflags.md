# D3DKMT_FLIPMODEL_PRESENTHISTORYTOKENFLAGS structure

## Description

The **D3DKMT_FLIPMODEL_PRESENTHISTORYTOKENFLAGS** structure identifies attributes of a flip present-history operation.

## Members

### `Video`

A UINT value that specifies whether the flip operation is performed with video.

### `RestrictedContent`

A UINT value that specifies whether the flip operation is performed with restricted content.

### `ClipToView`

A UINT value that specifies whether the flip operation is clipped to the view surface.

### `StereoPreferRight`

A UINT value that specifies that when the driver clones a stereo primary allocation to a mono monitor, it should use the right image.

Supported starting with Windows 8.

### `TemporaryMono`

A UINT value that specifies whether the driver should use the left image of a stereo allocation for the right and left portions of a stereo frame.

This member should be set only if the driver reports support for this option in the current display mode by setting the **Type** member of the [**D3DKMDT_VIDPN_SOURCE_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure to D3DKMDT_RMT_GRAPHICS_STEREO_ADVANCED_SCAN.

Supported starting with Windows 8.

### `FlipRestart`

A UINT value that specifies whether to restart a flip to a new surface.

Supported starting with Windows 8.

### `HDRMetaDataChanged`

### `AlphaMode`

A UINT value that specifies whether the DWM should use alpha transparency information when it composes swap buffers.

Setting this member is equivalent to setting the eighth and ninth bits of the 32-bit **Value** member (0x00000180).

Supported starting with Windows 8.

### `SignalLimitOnTokenCompletion`

 A UINT value that specifies the limit for the number of present operations that can be queued for the device after the GPU has finished processing the token.

Setting this member is equivalent to setting the tenth bit of the 32-bit **Value** member (0x00000200).

Supported starting with Windows 8.

### `YCbCrFlags`

### `IndependentFlip`

### `IndependentFlipStage`

### `IndependentFlipReleaseCount`

### `IndependentFlipForceNotifyDwm`

### `UseCustomDuration`

### `IndependentFlipRequestDwmConfirm`

### `IndependentFlipCandidate`

### `IndependentFlipCheckNeeded`

### `IndependentFlipTrueImmediate`

### `IndependentFlipRequestDwmExit`

### `IndependentFlipDoNotFlip`

### `CompSurfaceNotifiedEarly`

### `RequirePairedToken`

Require a paired token.

### `VariableRefreshOverrideEligible`

### `Reserved`

Supported starting with Windows 8.

This member is reserved and should be set to zero.

### `Value`

An alternative way to access the bit-field flags.

## See also

[**D3DKMT_PRESENTHISTORYTOKEN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_presenthistorytoken)