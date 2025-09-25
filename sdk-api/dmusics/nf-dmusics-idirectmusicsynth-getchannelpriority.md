# IDirectMusicSynth::GetChannelPriority

## Description

The `GetChannelPriority` method outputs the priority of a MIDI channel.

## Parameters

### `dwChannelGroup`

Specifies the channel group that the channel belongs to. This parameter must be one or greater.

### `dwChannel`

Specifies the index of the channel in the channel group. This is a value in the range 0 to 15.

### `pdwPriority`

Output pointer for the priority ranking. This parameter points to a caller-allocated variable into which the method writes the priority ranking value. For a list of the priority values that are defined for this parameter, see the **IDirectMusicPort::GetChannelPriority** reference page in the Microsoft Windows SDK documentation.

## Return value

`GetChannelPriority` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

This method is used with the [IDirectMusicSynth::SetChannelPriority](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-setchannelpriority) method to control the channel priorities and facilitate correct voice stealing.

For more information, see the descriptions of the **IDirectMusicPort::GetChannelPriority** and **IDirectMusicPort::SetChannelPriority** methods in the Windows SDK documentation.

## See also

[IDirectMusicSynth::SetChannelPriority](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-setchannelpriority)