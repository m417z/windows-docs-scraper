# KSAUDIO_MIX_CAPS structure

## Description

The KSAUDIO_MIX_CAPS structure specifies the mixing capabilities of a particular data path from one input channel of a supermixer node ([KSNODETYPE_SUPERMIX](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-supermix)) to an output channel of the same node. An array of these structures is used by a [KSAUDIO_MIXCAP_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksaudio_mixcap_table) structure to specify the mixing capabilities for all such paths through a supermixer node.

## Members

### `Mute`

Specifies whether the data path from the input channel to the output channel is muted (not mixed). A value of **TRUE** indicates that the data path is muted.

### `Minimum`

Specifies the minimum mix level for the data path from the input channel to the output channel. For more information, see the following Remarks section.

### `Maximum`

Specifies the maximum mix level for the data path from the input channel to the output channel. For more information, see the following Remarks section.

### `Reset`

**Reset** is a misnomer. This member should have been called Resolution instead. It specifies the resolution of the mix level for the data path from the input channel to the output channel. Resolution values use the following scale: a range from 0 to +2147483647, where 0 is no control and any other number is the number of steps between actual hardware settings in the range between **Minimum** and **Maximum**.

### `Resolution`

## Remarks

The mix-level values for the **Maximum** and **Minimum** members use the following scale:

-2147483648 is -Infinity decibels (attenuation),

 -2147483647 is -32767.99998474 decibels (attenuation), and

+2147483647 is +32767.99998474 decibels (gain).

A decibel range represented by integer values -2147483648 to +2147483647, where

This scale has a resolution of 1/65536 decibel.

## See also

[KSAUDIO_MIXCAP_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksaudio_mixcap_table)

[KSNODETYPE_SUPERMIX](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-supermix)

[KSPROPERTY_AUDIO_MIX_LEVEL_CAPS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-mix-level-caps)

[KSPROPERTY_AUDIO_MIX_LEVEL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-mix-level-table)