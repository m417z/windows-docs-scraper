# KSDS3D_HRTF_PARAMS_MSG structure

## Description

The KSDS3D_HRTF_PARAMS_MSG structure specifies the parameter settings to apply to a head-relative transfer function (HRTF).

## Members

### `Size`

Specifies the size in bytes of the structure.

### `Enabled`

Specifies whether to enable HRTF processing. If nonzero, HRTF is enabled. If zero, it is disabled.

### `SwapChannels`

Specifies whether the algorithm should swap channels. If **TRUE**, the algorithm should swap the channels to perform a left-to-right reversal of the location of the source. If **FALSE**, the algorithm should not swap the channels.

### `ZeroAzimuth`

Specifies whether the azimuth angle is zero. If **TRUE**, then only half of the filter coefficients are downloaded to the filter because the azimuth angle is zero. If **FALSE**, all the coefficients are downloaded.

### `CrossFadeOutput`

Specifies whether to cross-fade the output channels after crossing azimuth angle zero. If **TRUE**, the algorithm should cross-fade the output channels. If **FALSE**, it should not cross-fade the channels.

### `FilterSize`

Specifies the additional size in bytes of the filter coefficients that are appended to this structure.

## Remarks

This structure is used by the [KSPROPERTY_HRTF3D_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-hrtf3d-params) property.

For more information, see [KSPROPSETID_Hrtf3d](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-hrtf3d).

## See also

[KSPROPERTY_HRTF3D_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-hrtf3d-params)

[KSPROPSETID_Hrtf3d](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-hrtf3d)