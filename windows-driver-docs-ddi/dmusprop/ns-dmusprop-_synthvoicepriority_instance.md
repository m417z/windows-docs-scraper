# _SYNTHVOICEPRIORITY_INSTANCE structure

## Description

The SYNTHVOICEPRIORITY_INSTANCE structure identifies a voice in a MIDI synthesizer by specifying the voice's channel group (set of 16 MIDI channels) and its channel number within that group.

## Members

### `ChannelGroup`

Specifies the channel group that the voice belongs to. Channel groups are numbered beginning at zero. Each channel group contains 16 channels.

### `Channel`

Specifies the channel that the voice is on. This member contains a channel number in the range 0 through 15. It identifies a channel in the channel group.

## Remarks

The [KSPROPERTY_SYNTH_VOICEPRIORITY](https://learn.microsoft.com/previous-versions/ff537407(v=vs.85)) property request uses the SYNTHVOICEPRIORITY_INSTANCE structure for its property descriptor. The structure specifies which voice gets priority when the miniport driver needs to bump voices from the cache.

## See also

[KSPROPERTY_SYNTH_VOICEPRIORITY](https://learn.microsoft.com/previous-versions/ff537407(v=vs.85))