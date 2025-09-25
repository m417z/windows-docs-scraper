# midiOutOpen function

## Description

The **midiOutOpen** function opens a MIDI output device for playback.

## Parameters

### `phmo`

Pointer to an **HMIDIOUT** handle. This location is filled with a handle identifying the opened MIDI output device. The handle is used to identify the device in calls to other MIDI output functions.

### `uDeviceID`

Identifier of the MIDI output device that is to be opened.

### `dwCallback`

Pointer to a callback function, an event handle, a thread identifier, or a handle of a window or thread called during MIDI playback to process messages related to the progress of the playback. If no callback is desired, specify **NULL** for this parameter. For more information on the callback function, see [MidiOutProc](https://learn.microsoft.com/previous-versions/dd798478(v=vs.85)).

### `dwInstance`

User instance data passed to the callback. This parameter is not used with window callbacks or threads.

### `fdwOpen`

Callback flag for opening the device. It can be the following values.

| Value | Meaning |
| --- | --- |
| CALLBACK_EVENT | The *dwCallback* parameter is an event handle. This callback mechanism is for output only. |
| CALLBACK_FUNCTION | The *dwCallback* parameter is a callback function address. |
| CALLBACK_NULL | There is no callback mechanism. This value is the default setting. |
| CALLBACK_THREAD | The *dwCallback* parameter is a thread identifier. |
| CALLBACK_WINDOW | The *dwCallback* parameter is a window handle. |

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MIDIERR_NODEVICE** | No MIDI port was found. This error occurs only when the mapper is opened. |
| **MMSYSERR_ALLOCATED** | The specified resource is already allocated. |
| **MMSYSERR_BADDEVICEID** | The specified device identifier is out of range. |
| **MMSYSERR_INVALPARAM** | The specified pointer or structure is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to allocate or lock memory. |

## Remarks

To determine the number of MIDI output devices present in the system, use the [midiOutGetNumDevs](https://learn.microsoft.com/previous-versions/dd798472(v=vs.85)) function. The device identifier specified by *wDeviceID* varies from zero to one less than the number of devices present. MIDI_MAPPER can also be used as the device identifier.

If a window or thread is chosen to receive callback information, the following messages are sent to the window procedure or thread to indicate the progress of MIDI output: [MM_MOM_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mom-open), [MM_MOM_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mom-close), and [MM_MOM_DONE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mom-done).

If a function is chosen to receive callback information, the following messages are sent to the function to indicate the progress of MIDI output: [MOM_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/mom-open), [MOM_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mom-close), and [MOM_DONE](https://learn.microsoft.com/windows/desktop/Multimedia/mom-done).

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)