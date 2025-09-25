# waveInOpen function

## Description

The **waveInOpen** function opens the given waveform-audio input device for recording.

## Parameters

### `phwi`

Pointer to a buffer that receives a handle identifying the open waveform-audio input device. Use this handle to identify the device when calling other waveform-audio input functions. This parameter can be **NULL** if **WAVE_FORMAT_QUERY** is specified for *fdwOpen*.

### `uDeviceID`

Identifier of the waveform-audio input device to open. It can be either a device identifier or a handle of an open waveform-audio input device. You can use the following flag instead of a device identifier.

| Value | Meaning |
| --- | --- |
| WAVE_MAPPER | The function selects a waveform-audio input device capable of recording in the specified format. |

### `pwfx`

Pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that identifies the desired format for recording waveform-audio data. You can free this structure immediately after **waveInOpen** returns.

### `dwCallback`

Pointer to a fixed callback function, an event handle, a handle to a window, or the identifier of a thread to be called during waveform-audio recording to process messages related to the progress of recording. If no callback function is required, this value can be zero. For more information on the callback function, see [waveInProc](https://learn.microsoft.com/previous-versions/dd743849(v=vs.85)).

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
| **WAVE_MAPPED_DEFAULT_COMMUNICATION_DEVICE** | If this flag is specified and the *uDeviceID* parameter is **WAVE_MAPPER**, the function opens the default communication device. <br><br>This flag applies only when *uDeviceID* equals **WAVE_MAPPER**.<br><br>**Note** Requires Windows 7 |
| **WAVE_FORMAT_DIRECT** | If this flag is specified, the ACM driver does not perform conversions on the audio data. |
| **WAVE_FORMAT_QUERY** | The function queries the device to determine whether it supports the given format, but it does not open the device. |
| **WAVE_MAPPED** | The *uDeviceID* parameter specifies a waveform-audio device to be mapped to by the wave mapper. |

## Return value

Returns **MMSYSERR_NOERROR** if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_ALLOCATED** | Specified resource is already allocated. |
| **MMSYSERR_BADDEVICEID** | Specified device identifier is out of range. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |
| **WAVERR_BADFORMAT** | Attempted to open with an unsupported waveform-audio format. |

## Remarks

Use the [waveInGetNumDevs](https://learn.microsoft.com/previous-versions/dd743844(v=vs.85)) function to determine the number of waveform-audio input devices present on the system. The device identifier specified by *uDeviceID* varies from zero to one less than the number of devices present. The WAVE_MAPPER constant can also be used as a device identifier.

If you choose to have a window or thread receive callback information, the following messages are sent to the window procedure or thread to indicate the progress of waveform-audio input: [MM_WIM_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/mm-wim-open), [MM_WIM_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-wim-close), and [MM_WIM_DATA](https://learn.microsoft.com/windows/desktop/Multimedia/mm-wim-data).

If you choose to have a function receive callback information, the following messages are sent to the function to indicate the progress of waveform-audio input: [WIM_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/wim-open), [WIM_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/wim-close), and [WIM_DATA](https://learn.microsoft.com/windows/desktop/Multimedia/wim-data).

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)