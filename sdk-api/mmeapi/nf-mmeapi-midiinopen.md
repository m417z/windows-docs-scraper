# midiInOpen function

## Description

The **midiInOpen** function opens a specified MIDI input device.

## Parameters

### `phmi`

Pointer to an **HMIDIIN** handle. This location is filled with a handle identifying the opened MIDI input device. The handle is used to identify the device in calls to other MIDI input functions.

### `uDeviceID`

Identifier of the MIDI input device to be opened.

### `dwCallback`

Pointer to a callback function, a thread identifier, or a handle of a window called with information about incoming MIDI messages. For more information on the callback function, see [MidiInProc](https://learn.microsoft.com/previous-versions/dd798460(v=vs.85)).

### `dwInstance`

User instance data passed to the callback function. This parameter is not used with window callback functions or threads.

### `fdwOpen`

Callback flag for opening the device and, optionally, a status flag that helps regulate rapid data transfers. It can be the following values.

| Value | Meaning |
| --- | --- |
| CALLBACK_FUNCTION | The *dwCallback* parameter is a callback procedure address. |
| CALLBACK_NULL | There is no callback mechanism. This value is the default setting. |
| CALLBACK_THREAD | The *dwCallback* parameter is a thread identifier. |
| CALLBACK_WINDOW | The *dwCallback* parameter is a window handle. |
| MIDI_IO_STATUS | When this parameter also specifies CALLBACK_FUNCTION, [MIM_MOREDATA](https://learn.microsoft.com/windows/desktop/Multimedia/mim-moredata) messages are sent to the callback function as well as [MIM_DATA](https://learn.microsoft.com/windows/desktop/Multimedia/mim-data) messages. Or, if this parameter also specifies CALLBACK_WINDOW, [MM_MIM_MOREDATA](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mim-moredata) messages are sent to the window as well as [MM_MIM_DATA](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mim-data) messages. This flag does not affect event or thread callbacks. |

Most applications that use a callback mechanism will specify CALLBACK_FUNCTION for this parameter.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following/

| Return code | Description |
| --- | --- |
| **MMSYSERR_ALLOCATED** | The specified resource is already allocated. |
| **MMSYSERR_BADDEVICEID** | The specified device identifier is out of range. |
| **MMSYSERR_INVALFLAG** | The flags specified by *dwFlags* are invalid. |
| **MMSYSERR_INVALPARAM** | The specified pointer or structure is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to allocate or lock memory. |

## Remarks

To determine the number of MIDI input devices present in the system, use the [midiInGetNumDevs](https://learn.microsoft.com/previous-versions/dd798456(v=vs.85)) function. The device identifier specified by *wDeviceID* varies from zero to one less than the number of devices present.

If a window or thread is chosen to receive callback information, the following messages are sent to the window procedure or thread to indicate the progress of MIDI input: [MM_MIM_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mim-open), [MM_MIM_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mim-close), [MM_MIM_DATA](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mim-data), [MM_MIM_LONGDATA](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mim-longdata), [MM_MIM_ERROR](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mim-error), [MM_MIM_LONGERROR](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mim-longerror), and [MM_MIM_MOREDATA](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mim-moredata).

If a function is chosen to receive callback information, the following messages are sent to the function to indicate the progress of MIDI input: [MIM_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/mim-open), [MIM_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mim-close), [MIM_DATA](https://learn.microsoft.com/windows/desktop/Multimedia/mim-data), [MIM_LONGDATA](https://learn.microsoft.com/windows/desktop/Multimedia/mim-longdata), [MIM_ERROR](https://learn.microsoft.com/windows/desktop/Multimedia/mim-error), [MIM_LONGERROR](https://learn.microsoft.com/windows/desktop/Multimedia/mim-longerror), and [MIM_MOREDATA](https://learn.microsoft.com/windows/desktop/Multimedia/mim-moredata).

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)