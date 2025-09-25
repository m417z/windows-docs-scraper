# IDirectMusicSynth::SetChannelPriority

## Description

The `SetChannelPriority` method sets the priority of a MIDI channel.

## Parameters

### `dwChannelGroup`

Specifies the group the channel is in. This value must be one or greater.

### `dwChannel`

Specifies a channel in the channel group. This parameter is an index in the range 0 to 15.

### `dwPriority`

Specifies the priority ranking of the channel. For a list of the ranking values that are defined for this parameter, see the **IDirectMusicPort::GetChannelPriority** reference page in the Microsoft Windows SDK documentation.

## Return value

`SetChannelPriority` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The `SetChannelPriority` method is implemented to support the MIDI synthesis engine. This method allows the allocated voices to run at different priorities, depending on which channel they are on. Sometimes voices are freed when there are too many to deal with at one time, and they are kicked out based on the priority of the channel they are on. If a voice comes in on a higher-priority channel, and if there are no more free voices, the MIDI synthesis engine will steal a channel from the lowest-priority voice and reassign the channels.

For more information, see the description of the **IDirectMusicPort::GetChannelPriority** and **IDirectMusicPort::SetChannelPriority** methods in the Windows SDK documentation.

## See also

[IDirectMusicSynth::GetChannelPriority](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-getchannelpriority)