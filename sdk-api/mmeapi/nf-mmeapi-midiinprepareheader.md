# midiInPrepareHeader function

## Description

The **midiInPrepareHeader** function prepares a buffer for MIDI input.

## Parameters

### `hmi`

Handle to the MIDI input device.
To get the device handle, call [midiInOpen](https://learn.microsoft.com/previous-versions/dd798458(v=vs.85)).

### `pmh`

Pointer to a [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure that identifies the buffer to be prepared.

Before calling the function, set the **lpData**, **dwBufferLength**, and **dwFlags** members of the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure. The **dwFlags** member must be set to zero.

### `cbmh`

Size, in bytes, of the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |
| **MMSYSERR_INVALPARAM** | The specified address is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to allocate or lock memory. |

## Remarks

Before you pass a MIDI data block to a device driver, you must prepare the buffer by passing it to the **midiInPrepareHeader** function. After the header has been prepared, do not modify the buffer. After the driver is done using the buffer, call the [midiInUnprepareHeader](https://learn.microsoft.com/previous-versions/dd798464(v=vs.85)) function.

The application can re-use the same buffer, or allocate multiple buffers and call **midiInPrepareHeader** for each buffer. If you re-use the same buffer, it is not necessary to prepare the buffer each time. You can call **midiInPrepareHeader** once at the beginning and then call [midiInUnprepareHeader](https://learn.microsoft.com/previous-versions/dd798464(v=vs.85)) once at the end.

Preparing a header that has already been prepared has no effect, and the function returns zero.

## See also

[Allocating and Preparing MIDI Data Blocks](https://learn.microsoft.com/windows/desktop/Multimedia/allocating-and-preparing-midi-data-blocks)

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)

[midiInUnprepareHeader](https://learn.microsoft.com/previous-versions/dd798464(v=vs.85))