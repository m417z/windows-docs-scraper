# midiInUnprepareHeader function

## Description

The **midiInUnprepareHeader** function cleans up the preparation performed by the [midiInPrepareHeader](https://learn.microsoft.com/previous-versions/dd798459(v=vs.85)) function.

## Parameters

### `hmi`

Handle to the MIDI input device.

### `pmh`

Pointer to a [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure identifying the buffer to be cleaned up.

### `cbmh`

Size of the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MIDIERR_STILLPLAYING** | The buffer pointed to by *lpMidiInHdr* is still in the queue. |
| **MMSYSERR_INVALPARAM** | The specified pointer or structure is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |

## Remarks

This function is complementary to [midiInPrepareHeader](https://learn.microsoft.com/previous-versions/dd798459(v=vs.85)). You must use this function before freeing the buffer. After passing a buffer to the device driver by using the [midiInAddBuffer](https://learn.microsoft.com/previous-versions/dd798450(v=vs.85)) function, you must wait until the driver is finished with the buffer before using **midiInUnprepareHeader**. Unpreparing a buffer that has not been prepared has no effect, and the function returns MMSYSERR_NOERROR.

## See also

[Allocating and Preparing MIDI Data Blocks](https://learn.microsoft.com/windows/desktop/Multimedia/allocating-and-preparing-midi-data-blocks)

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)