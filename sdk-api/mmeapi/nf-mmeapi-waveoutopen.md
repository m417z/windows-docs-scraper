# waveOutOpen function

## Description

The **waveOutOpen** function opens the given waveform-audio output device for playback.

## Parameters

### `phwo`

Pointer to a buffer that receives a handle identifying the open waveform-audio output device. Use the handle to identify the device when calling other waveform-audio output functions. This parameter might be **NULL** if the **WAVE_FORMAT_QUERY** flag is specified for *fdwOpen*.

### `uDeviceID`

Identifier of the waveform-audio output device to open. It can be either a device identifier or a handle of an open waveform-audio input device. You can also use the following flag instead of a device identifier:

| Value | Meaning |
| --- | --- |
| **WAVE_MAPPER** | The function selects a waveform-audio output device capable of playing the given format. |

### `pwfx`

Pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that identifies the format of the waveform-audio data to be sent to the device. You can free this structure immediately after passing it to **waveOutOpen**.

### `dwCallback`

Specifies the callback mechanism. The value must be one of the following:

* A pointer to a callback function. For the function signature, see [waveOutProc](https://learn.microsoft.com/previous-versions/dd743869(v=vs.85)).
* A handle to a window.
* A thread identifier.
* A handle to an event.
* The value **NULL**.

The *fdwOpen* parameter specifies how the *dwCallback* parameter is interpreted. For more information, see Remarks.

### `dwInstance`

User-instance data passed to the callback mechanism. This parameter is not used with the window callback mechanism.

### `fdwOpen`

Flags for opening the device. The following values are defined.

| Value | Meaning |
| --- | --- |
| **CALLBACK_EVENT** | The *dwCallback* parameter is an event handle. |
| **CALLBACK_FUNCTION** | The *dwCallback* parameter is a callback procedure address. |
| **CALLBACK_NULL** | No callback mechanism. This is the default setting. |
| **CALLBACK_THREAD** | The *dwCallback* parameter is a thread identifier. |
| **CALLBACK_WINDOW** | The *dwCallback* parameter is a window handle. |
| **WAVE_ALLOWSYNC** | If this flag is specified, a synchronous waveform-audio device can be opened. If this flag is not specified while opening a synchronous driver, the device will fail to open. |
| **WAVE_MAPPED_DEFAULT_COMMUNICATION_DEVICE** | If this flag is specified and the *uDeviceID* parameter is **WAVE_MAPPER**, the function opens the default communication device. <br><br>This flag applies only when *uDeviceID* equals **WAVE_MAPPER**.<br><br>**Note** Requires Windows 7 |
| **WAVE_FORMAT_DIRECT** | If this flag is specified, the ACM driver does not perform conversions on the audio data. |
| **WAVE_FORMAT_QUERY** | If this flag is specified, **waveOutOpen** queries the device to determine if it supports the given format, but the device is not actually opened. |
| **WAVE_MAPPED** | If this flag is specified, the *uDeviceID* parameter specifies a waveform-audio device to be mapped to by the wave mapper. |

## Return value

Returns **MMSYSERR_NOERROR** if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_ALLOCATED** | Specified resource is already allocated. |
| **MMSYSERR_BADDEVICEID** | Specified device identifier is out of range. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |
| **WAVERR_BADFORMAT** | Attempted to open with an unsupported waveform-audio format. |
| **WAVERR_SYNC** | The device is synchronous but [waveOutOpen](https://learn.microsoft.com/previous-versions/dd743866(v=vs.85)) was called without using the **WAVE_ALLOWSYNC** flag. |

## Remarks

Use the [waveOutGetNumDevs](https://learn.microsoft.com/previous-versions/dd743860(v=vs.85)) function to determine the number of waveform-audio output devices present in the system. If the value specified by the *uDeviceID* parameter is a device identifier, it can vary from zero to one less than the number of devices present. The **WAVE_MAPPER** constant can also be used as a device identifier.

The structure pointed to by *pwfx* can be extended to include type-specific information for certain data formats. For example, for PCM data, an extra **UINT** is added to specify the number of bits per sample. Use the [PCMWAVEFORMAT](https://learn.microsoft.com/previous-versions/dd743663(v=vs.85)) structure in this case. For all other waveform-audio formats, use the [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure to specify the length of the additional data.

If you choose to have a window or thread receive callback information, the following messages are sent to the window procedure function to indicate the progress of waveform-audio output: [MM_WOM_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/mm-wom-open), [MM_WOM_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-wom-close), and [MM_WOM_DONE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-wom-done).

### Callback Mechanism

The *dwCallback* and *fdwOpen* parameters specify how the application is notified about the progress of waveform-audio output.

If *fdwOpen* contains the **CALLBACK_FUNCTION** flag, *dwCallback* is a pointer to a callback function. For the function signature, see [waveOutProc](https://learn.microsoft.com/previous-versions/dd743869(v=vs.85)). The *uMsg* parameter of the callback indicates the progress of the audio output:

* [WOM_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/wom-open)
* [WOM_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/wom-close)
* [WOM_DONE](https://learn.microsoft.com/windows/desktop/Multimedia/wom-done)

If *fdwOpen* contains the **CALLBACK_WINDOW** flag, *dwCallback* is a handle to a window.The window receives the following messages, indicating the progress:

* [MM_WOM_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/mm-wom-open)
* [MM_WOM_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-wom-close)
* [MM_WOM_DONE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-wom-done)

If *fdwOpen* contains the **CALLBACK_THREAD** flag, *dwCallback* is a thread identifier. The thread receives the messages listed previously for **CALLBACK_WINDOW**.

If *fdwOpen* contains the **CALLBACK_EVENT** flag, *dwCallback* is a handle to an event. The event is signaled whenever the state of the waveform buffer changes. The application can use [WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject) or [WaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjects) to wait for the event. When the event is signaled, you can get the current state of the waveform buffer by checking the **dwFlags** member of the [WAVEHDR](https://learn.microsoft.com/previous-versions/dd743837(v=vs.85)) structure. (See [waveOutPrepareHeader](https://learn.microsoft.com/previous-versions/dd743868(v=vs.85)).)

If *fdwOpen* contains the **CALLBACK_NULL** flag, *dwCallback* must be **NULL**. In that case, no callback mechanism is used.

## See also

[Using a Callback Function to Process Driver Messages](https://learn.microsoft.com/windows/desktop/Multimedia/using-a-callback-function-to-process-driver-messages)

[Using a Window or Thread to Process Driver Messages](https://learn.microsoft.com/windows/desktop/Multimedia/using-a-window-or-thread-to-process-driver-messages)

[Using an Event Callback to Process Driver Messages](https://learn.microsoft.com/windows/desktop/Multimedia/using-an-callback-to-process-driver-messages)

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)