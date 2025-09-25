# midiOutUnprepareHeader function

## Description

The **midiOutUnprepareHeader** function cleans up the preparation performed by the [midiOutPrepareHeader](https://learn.microsoft.com/previous-versions/dd798477(v=vs.85)) function.

## Parameters

### `hmo`

Handle to the MIDI output device. This parameter can also be the handle of a MIDI stream cast to **HMIDIOUT**.

### `pmh`

Pointer to a [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure identifying the buffer to be cleaned up.

### `cbmh`

Size, in bytes, of the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MIDIERR_STILLPLAYING** | The buffer pointed to by *lpMidiOutHdr* is still in the queue. |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |
| **MMSYSERR_INVALPARAM** | The specified pointer or structure is invalid. |

## Remarks

This function is complementary to the [midiOutPrepareHeader](https://learn.microsoft.com/previous-versions/dd798477(v=vs.85)) function. You must call **midiOutUnprepareHeader** before freeing the buffer. After passing a buffer to the device driver with the [midiOutLongMsg](https://learn.microsoft.com/previous-versions/dd798474(v=vs.85)) function, you must wait until the device driver is finished with the buffer before calling **midiOutUnprepareHeader**.

Unpreparing a buffer that has not been prepared has no effect, and the function returns MMSYSERR_NOERROR.

## See also

[Allocating and Preparing MIDI Data Blocks](https://learn.microsoft.com/windows/desktop/Multimedia/allocating-and-preparing-midi-data-blocks)

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)