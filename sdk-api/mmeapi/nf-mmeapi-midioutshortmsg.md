# midiOutShortMsg function

## Description

The **midiOutShortMsg** function sends a short MIDI message to the specified MIDI output device.

## Parameters

### `hmo`

Handle to the MIDI output device. This parameter can also be the handle of a MIDI stream cast to **HMIDIOUT**.

### `dwMsg`

MIDI message. The message is packed into a **DWORD** value with the first byte of the message in the low-order byte. The message is packed into this parameter as follows.

| Word | Byte | Usage |
| --- | --- | --- |
| High | High-order | Not used. |
|  | Low-order | The second byte of MIDI data (when needed). |
| Low | High-order | The first byte of MIDI data (when needed). |
|  | Low-order | The MIDI status. |

The two MIDI data bytes are optional, depending on the MIDI status byte. When a series of messages have the same status byte, the status byte can be omitted from messages after the first one in the series, creating a running status. Pack a message for running status as follows:

| Word | Byte | Usage |
| --- | --- | --- |
| High | High-order | Not used. |
|  | Low-order | Not used. |
| Low | High-order | The second byte of MIDI data (when needed). |
|  | Low-order | The first byte of MIDI data. |

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following:

| Return code | Description |
| --- | --- |
| **MIDIERR_BADOPENMODE** | The application sent a message without a status byte to a stream handle. |
| **MIDIERR_NOTREADY** | The hardware is busy with other data. |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |

## Remarks

This function is used to send any MIDI message except for system-exclusive or stream messages.

This function might not return until the message has been sent to the output device. You can send short messages while streams are playing on the same device (although you cannot use a running status in this case).

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)