# midiInClose function

## Description

The **midiInClose** function closes the specified MIDI input device.

## Parameters

### `hmi`

Handle to the MIDI input device. If the function is successful, the handle is no longer valid after the call to this function.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MIDIERR_STILLPLAYING** | Buffers are still in the queue. |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to allocate or lock memory. |

## Remarks

If there are input buffers that have been sent by using the [midiInAddBuffer](https://learn.microsoft.com/previous-versions/dd798450(v=vs.85)) function and have not been returned to the application, the close operation will fail. To return all pending buffers through the callback function, use the [midiInReset](https://learn.microsoft.com/previous-versions/dd798461(v=vs.85)) function.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)