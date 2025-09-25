# IDirectMusicSynth::SetNumChannelGroups

## Description

The `SetNumChannelGroups` method instructs the synthesizer to set its number of channel groups to a new value.

## Parameters

### `dwGroups`

Specifies the number of channel groups requested.

## Return value

`SetNumChannelGroups` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth is not open or not properly configured. |
| **E_FAIL** | Indicates that the method is unable to allocate the channel groups. |

## Remarks

Even though [IDirectMusicSynth::Open](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-open) tells the DirectMusic "port" how many channel groups to create, the application might later need to dynamically increase or reduce that number with a call to `SetNumChannelGroups`.

Each channel group supports a set of 16 MIDI channels. For example, if *dwChannelGroups* is set to three, the synthesizer creates 48 channels.

For more information, see the description of the **IDirectMusic** interface in the Microsoft Windows SDK documentation.

## See also

[IDirectMusicSynth::Open](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-open)