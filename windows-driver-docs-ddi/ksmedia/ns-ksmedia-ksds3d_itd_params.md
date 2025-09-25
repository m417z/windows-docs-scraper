# KSDS3D_ITD_PARAMS structure

## Description

The KSDS3D_ITD_PARAMS structure specifies the parameters applied by the interaural time delay (ITD) algorithm to the left or right channel in a 3D node ([KSNODETYPE_3D_EFFECTS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-3d-effects)).

## Members

### `Channel`

Specifies the channel number (channel 0 is the left channel; channel 1 is the right channel).

### `VolSmoothScale`

Specifies the ramp factor for scaling volume levels. For more information, see the following Remarks section.

### `TotalDryAttenuation`

Specifies the attenuation factor for the "dry" signal (the original signal before applying a low-pass filter to produce a muffled effect). For more information, see the following Remarks section.

### `TotalWetAttenuation`

Specifies the attenuation factor for the "wet" signal (the muffled signal after the low-pass filter is applied). For more information, see the following Remarks section.

### `SmoothFrequency`

Specifies the sample frequency of the audio stream. When changing to a new **TotalDryAttenuation** or **TotalWetAttenuation** value, the ITD algorithm needs this value to determine the number of samples over which to apply smoothing in order to complete the transition within some fixed time interval. For example, the ITD algorithm implemented by the [KMixer system driver](https://learn.microsoft.com/windows-hardware/drivers/audio/kernel-mode-wdm-audio-components) uses a transition time interval of roughly 1/8 second.

### `Delay`

Specifies the time delay for this channel. The delay is expressed as an integer number of samples.

## Remarks

This structure is used by the [KSDS3D_ITD_PARAMS_MSG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksds3d_itd_params_msg) structure, which the [KSPROPERTY_ITD3D_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-itd3d-params) property request uses to specify the ITD parameters for the left and right channels of a 3D audio stream.

The **Delay** member specifies the amount by which the current channel delays the sound arriving from the source. The interaural time delay is the difference in delays between the two channels.

The attenuated signal is the sum of the attenuated dry signal and the attenuated wet signal:

**TotalDryAttenuation** + **TotalWetAttenuation**

Increasing the size of **TotalWetAttenuation** relative to **TotalDryAttenuation** produces an increasingly muffled sound. The two attenuation factors are calculated from the sound source's position, orientation, and sound cone.

When a KSPROPERTY_ITD3D_PARAMS set-property request changes either **TotalDryAttenuation** or **TotalWetAttenuation**, the change in attenuation level is smoothed over a number of samples in order to avoid generating spurious clicking noises. The **VolSmoothScale** member specifies the amount by which to scale the attenuation of the signal during each step in the smoothing process. This parameter is either a value slightly less than 1 if the attenuation is increasing or slightly greater than 1 if the attenuation is decreasing. At each step in the smoothing process, the attenuation from the previous step is multiplied by this parameter. The process completes when the target attenuation is reached.

## See also

[KSDS3D_ITD_PARAMS_MSG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksds3d_itd_params_msg)

[KSPROPERTY_ITD3D_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-itd3d-params)