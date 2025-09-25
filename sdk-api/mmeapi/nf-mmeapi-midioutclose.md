# midiOutClose function

## Description

The **midiOutClose** function closes the specified MIDI output device.

## Parameters

### `hmo`

Handle to the MIDI output device. If the function is successful, the handle is no longer valid after the call to this function.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MIDIERR_STILLPLAYING** | Buffers are still in the queue. |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to load mapper string description. |

## Remarks

If there are output buffers that have been sent by using the [midiOutLongMsg](https://learn.microsoft.com/previous-versions/dd798474(v=vs.85)) function and have not been returned to the application, the close operation will fail. To mark all pending buffers as being done, use the [midiOutReset](https://learn.microsoft.com/previous-versions/dd798479(v=vs.85)) function.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)