# KSDS3D_HRTF_INIT_MSG structure

## Description

The KSDS3D_HRTF_INIT_MSG structure specifies the parameter settings to use to initialize the head-relative transfer function (HRTF).

## Members

### `Size`

Specifies the size in bytes of the structure.

### `Quality`

Specifies the HRTF filter quality level. Set this parameter to one of the following KSDS3D_HRTF_FILTER_QUALITY enumeration values:

* LIGHT_FILTER selects an efficient algorithm that produces a good quality effect.
* FULL_FILTER selects an algorithm that produces a high-quality effect but requires more processing time.

### `SampleRate`

Specifies the sample rate, in samples per second (hertz), at which each channel should be played. For example, a value of 22,050 specifies a sample rate of 22.05 kHz.

### `MaxFilterSize`

Specifies the maximum filter size in bytes. If the filter is in direct form, the maximum size is the order of the filter (numerator and denominator have equal order). If the filter is in cascade form, the maximum size is the maximum number of biquadratic coefficients.

### `FilterTransientMuteLength`

Specifies how long to delay cross-fading to the new filter in order to avoid introducing the new filter's initial transient signal into the output signal. The delay is specified as a number of initial samples produced by the new filter. During this time, the output comes from the old filters only.

### `FilterOverlapBufferLength`

Specifies the total number of samples over which to mute and cross-fade the filter outputs.

### `OutputOverlapBufferLength`

Specifies the number of samples over which to cross-fade the output channels after a transition across azimuth angle zero. This member is used when cross-fading of the output channels is enabled by the **CrossFadeOutput** member of [KSDS3D_HRTF_PARAMS_MSG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksds3d_hrtf_params_msg).

### `Reserved`

Reserved. Set to zero.

## Remarks

This structure is used by the [KSPROPERTY_HRTF3D_INITIALIZE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-hrtf3d-initialize) property.

The **Quality** values FULL_FILTER and LIGHT_FILTER correspond to the GUID_DS3DALG_HRTF_FULL and GUID_DS3DALG_HRTF_LIGHT settings that are described in the Microsoft Windows SDK documentation.

For more information, see [KSPROPSETID_Hrtf3d](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-hrtf3d).

## See also

[KSDS3D_HRTF_PARAMS_MSG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksds3d_hrtf_params_msg)

[KSPROPERTY_HRTF3D_INITIALIZE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-hrtf3d-initialize)

[KSPROPSETID_Hrtf3d](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-hrtf3d)