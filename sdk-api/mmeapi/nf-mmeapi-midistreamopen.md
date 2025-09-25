# midiStreamOpen function

## Description

The **midiStreamOpen** function opens a MIDI stream for output. By default, the device is opened in paused mode. The stream handle retrieved by this function must be used in all subsequent references to the stream.

## Parameters

### `phms`

Pointer to a variable to contain the stream handle when the function returns.

### `puDeviceID`

Pointer to a device identifier. The device is opened on behalf of the stream and closed again when the stream is closed.

### `cMidi`

Reserved; must be 1.

### `dwCallback`

Pointer to a callback function, an event handle, a thread identifier, or a handle of a window or thread called during MIDI playback to process messages related to the progress of the playback. If no callback mechanism is desired, specify **NULL** for this parameter.

### `dwInstance`

Application-specific instance data that is returned to the application with every callback function.

### `fdwOpen`

Callback flag for opening the device. One of the following callback flags must be specified.

| Value | Meaning |
| --- | --- |
| CALLBACK_EVENT | The *dwCallback* parameter is an event handle. This callback mechanism is for output only. |
| CALLBACK_FUNCTION | The *dwCallback* parameter is a callback procedure address. For the callback signature, see [MidiOutProc](https://learn.microsoft.com/previous-versions/dd798478(v=vs.85)). |
| CALLBACK_NULL | There is no callback mechanism. This is the default setting. |
| CALLBACK_THREAD | The *dwCallback* parameter is a thread identifier. |
| CALLBACK_WINDOW | The *dwCallback* parameter is a window handle. |

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_BADDEVICEID** | The specified device identifier is out of range. |
| **MMSYSERR_INVALPARAM** | The given handle or flags parameter is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to allocate or lock memory. |

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)