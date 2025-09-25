# _SYNTH_PORTPARAMS structure

## Description

The SYNTH_PORTPARAMS structure contains the configuration parameters for a DirectMusic *port*, which is a DirectMusic term for a device that sends or receives music data. (In KS terminology, a DirectMusic port does not correspond to a DMus port driver. It corresponds to a render or capture pin on a DirectMusic filter.)

## Members

### `ValidParams`

Specifies which of the SYNTH_PORTPARAMS structure members contain valid data. This member is a bitfield whose value is either zero or the bitwise OR of one or more of the following flag bits:

#### SYNTH_PORTPARAMS_VOICES

The **Voices** field is valid.

#### SYNTH_PORTPARAMS_CHANNELGROUPS

The **ChannelGroups** field is valid.

#### SYNTH_PORTPARAMS_AUDIOCHANNELS

The **AudioChannels** field is valid.

#### SYNTH_PORTPARAMS_SAMPLERATE

The **SampleRate** field is valid.

#### SYNTH_PORTPARAMS_EFFECT

The **EffectsFlags** flag is valid.

#### SYNTH_PORTPARAMS_SHARE

The **Share** field is valid.

### `Voices`

Specifies the maximum number of simultaneous voices that the application wishes to play on this port.

### `ChannelGroups`

Specifies the number of channel groups requested for this port. Each channel group contains 16 channels.

### `AudioChannels`

Specifies the number of audio channels.

### `SampleRate`

Specifies the number of samples per second for the audio data produced by the port.

### `EffectsFlags`

Specifies the type of effects produced for audio output from this port. This member is a bitfield whose value is either zero or the bitwise OR of one or more of the following flag bits:

#### SYNTH_EFFECT_REVERB

Reverb is enabled.

#### SYNTH_EFFECT_CHORUS

Chorus effect is enabled.

#### SYNTH_EFFECT_DELAY

Delay effect is enabled.

If no effects are enabled, this member is set to SYNTH_EFFECT_NONE, which is zero.

### `Share`

Specifies whether the port's channel groups are shared. When this member is **TRUE**, all ports use the channel groups assigned to this port. When this member is **FALSE**, the port is opened in exclusive mode and the use of the same channel groups by other ports is not allowed.

## Remarks

A [KSPROPERTY_SYNTH_PORTPARAMETERS](https://learn.microsoft.com/previous-versions/ff537405(v=vs.85)) get-property request uses the SYNTH_PORTPARAMS structure for both its property descriptor and its property value.

## See also

[KSPROPERTY_SYNTH_PORTPARAMETERS](https://learn.microsoft.com/previous-versions/ff537405(v=vs.85))