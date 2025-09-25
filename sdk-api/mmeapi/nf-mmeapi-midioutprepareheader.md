# midiOutPrepareHeader function

## Description

The **midiOutPrepareHeader** function prepares a MIDI system-exclusive or stream buffer for output.

## Parameters

### `hmo`

Handle to the MIDI output device. To get the device handle, call [midiOutOpen](https://learn.microsoft.com/previous-versions/dd798476(v=vs.85)). This parameter can also be the handle of a MIDI stream cast to a **HMIDIOUT** type.

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
| **MMSYSERR_INVALPARAM** | The specified address is invalid or the given stream buffer is greater than 64K. |
| **MMSYSERR_NOMEM** | The system is unable to allocate or lock memory. |

## Remarks

Before you pass a MIDI data block to a device driver, you must prepare the buffer by passing it to the **midiOutPrepareHeader** function. After the header has been prepared, do not modify the buffer. After the driver is done using the buffer, call the [midiOutUnprepareHeader](https://learn.microsoft.com/previous-versions/dd798482(v=vs.85)) function.

The application can re-use the same buffer, or allocate multiple buffers and call **midiOutPrepareHeader** for each buffer. If you re-use the same buffer, it is not necessary to prepare the buffer each time. You can call **midiOutPrepareHeader** once at the beginning and then call [midiOutUnprepareHeader](https://learn.microsoft.com/previous-versions/dd798482(v=vs.85)) once at the end.

A stream buffer cannot be larger than 64K.

Preparing a header that has already been prepared has no effect, and the function returns MMSYSERR_NOERROR.

## See also

[Allocating and Preparing MIDI Data Blocks](https://learn.microsoft.com/windows/desktop/Multimedia/allocating-and-preparing-midi-data-blocks)

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)

[midiOutUnprepareHeader](https://learn.microsoft.com/previous-versions/dd798482(v=vs.85))