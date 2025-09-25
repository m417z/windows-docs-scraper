# KSAC3_DOWNMIX structure

## Description

The KSAC3_DOWNMIX structure specifies whether the program channels in an AC-3-encoded stream need to be downmixed to accommodate the speaker configuration.

## Members

### `fDownMix`

Specifies whether to downmix. If **TRUE**, downmixing to fewer channels is enabled. The number of output channels depends on the number of speakers present (as specified by the [KSPROPERTY_AUDIO_CHANNEL_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-channel-config) property). If **FALSE**, input and output channels are mapped to speakers on a one-to-one basis. In other words, input channel 0 is mapped to output channel 0, input channel 1 is mapped to output channel 1, and so on, up to the number of encoded channels or speakers, whichever is smaller.

### `fDolbySurround`

Specifies how the output channels are encoded. If **TRUE**, the output channels are first encoded as two Dolby Surround Pro Logic channels, Lt and Rt. If **FALSE**, the output channels do not use Dolby Surround Pro Logic encoding.

## Remarks

This structure is used by the [KSPROPERTY_AC3_DOWNMIX](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-ac3-downmix) property.

For information about the mapping of output channels to speakers, see [KSPROPERTY_AUDIO_CHANNEL_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-channel-config).

## See also

[KSPROPERTY_AC3_DOWNMIX](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-ac3-downmix)

[KSPROPERTY_AUDIO_CHANNEL_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-channel-config)