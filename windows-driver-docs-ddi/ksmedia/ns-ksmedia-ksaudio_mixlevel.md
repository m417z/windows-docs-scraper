# KSAUDIO_MIXLEVEL structure

## Description

The KSAUDIO_MIXLEVEL structure specifies the mixing level of an input-output path in a supermixer node ([KSNODETYPE_SUPERMIX](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-supermix)).

## Members

### `Mute`

Specifies whether the input channel is muted (not mixed) as it flows into the output channel. A value of **TRUE** indicates that the channel is muted. A value of **FALSE** indicates that the channel's mix level is specified by the **Level** member.

### `Level`

Specifies the mix level that is applied to the input channel as it flows into the output channel. For more information, see the following Remarks section.

## Remarks

A KSAUDIO_MIXLEVEL structure specifies the volume level of a particular data path from one input channel of a supermixer node to an output channel of the same node. An array of these structures is needed to specify the volume levels for all the input-output paths through a supermixer node.

To specify the mixing levels of all paths through a supermixer node with *m* input channels and *n* output channels requires a mix-level table consisting of an *m* x *n* array of KSAUDIO_MIXLEVEL structures. This table is used to set or get the data value for the [KSPROPERTY_AUDIO_MIX_LEVEL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-mix-level-table) property.

The mix-level value in the **Level** member uses the following scale:

-2147483648 is -Infinity decibels (attenuation),

 -2147483647 is -32767.99998474 decibels (attenuation), and

+2147483647 is +32767.99998474 decibels (gain).

A decibel range represented by integer values -2147483648 to +2147483647, where

This scale has a resolution of 1/65536 decibel.

## See also

[KSNODETYPE_SUPERMIX](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-supermix)

[KSPROPERTY_AUDIO_MIX_LEVEL_CAPS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-mix-level-caps)

[KSPROPERTY_AUDIO_MIX_LEVEL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-mix-level-table)