# mixerOpen function

## Description

The **mixerOpen** function opens a specified mixer device and ensures that the device will not be removed until the application closes the handle.

## Parameters

### `phmx`

Pointer to a variable that will receive a handle identifying the opened mixer device. Use this handle to identify the device when calling other audio mixer functions. This parameter cannot be **NULL**.

### `uMxId`

Identifier of the mixer device to open. Use a valid device identifier or any **HMIXEROBJ** (see the [mixerGetID](https://learn.microsoft.com/previous-versions/dd757301(v=vs.85)) function for a description of mixer object handles). A "mapper" for audio mixer devices does not currently exist, so a mixer device identifier of -1 is not valid.

### `dwCallback`

Handle to a window called when the state of an audio line and/or control associated with the device being opened is changed. Specify **NULL** for this parameter if no callback mechanism is to be used.

### `dwInstance`

Reserved. Must be zero.

### `fdwOpen`

Flags for opening the device. The following values are defined.

| Value | Meaning |
| --- | --- |
| **CALLBACK_WINDOW** | The *dwCallback* parameter is assumed to be a window handle (**HWND**). |
| **MIXER_OBJECTF_AUX** | The *uMxId* parameter is an auxiliary device identifier in the range of zero to one less than the number of devices returned by the [auxGetNumDevs](https://learn.microsoft.com/previous-versions/dd756713(v=vs.85)) function. |
| **MIXER_OBJECTF_HMIDIIN** | The *uMxId* parameter is the handle of a MIDI input device. This handle must have been returned by the [midiInOpen](https://learn.microsoft.com/previous-versions/dd798458(v=vs.85)) function. |
| **MIXER_OBJECTF_HMIDIOUT** | The *uMxId* parameter is the handle of a MIDI output device. This handle must have been returned by the [midiOutOpen](https://learn.microsoft.com/previous-versions/dd798476(v=vs.85)) function. |
| **MIXER_OBJECTF_HMIXER** | The *uMxId* parameter is a mixer device handle returned by the **mixerOpen** function. This flag is optional. |
| **MIXER_OBJECTF_HWAVEIN** | The *uMxId* parameter is a waveform-audio input handle returned by the [waveInOpen](https://learn.microsoft.com/previous-versions/dd743847(v=vs.85)) function. |
| **MIXER_OBJECTF_HWAVEOUT** | The *uMxId* parameter is a waveform-audio output handle returned by the [waveOutOpen](https://learn.microsoft.com/previous-versions/dd743866(v=vs.85)) function. |
| **MIXER_OBJECTF_MIDIIN** | The *uMxId* parameter is the identifier of a MIDI input device. This identifier must be in the range of zero to one less than the number of devices returned by the [midiInGetNumDevs](https://learn.microsoft.com/previous-versions/dd798456(v=vs.85)) function. |
| **MIXER_OBJECTF_MIDIOUT** | The *uMxId* parameter is the identifier of a MIDI output device. This identifier must be in the range of zero to one less than the number of devices returned by the [midiOutGetNumDevs](https://learn.microsoft.com/previous-versions/dd798472(v=vs.85)) function. |
| **MIXER_OBJECTF_MIXER** | The *uMxId* parameter is a mixer device identifier in the range of zero to one less than the number of devices returned by the [mixerGetNumDevs](https://learn.microsoft.com/previous-versions/dd757304(v=vs.85)) function. This flag is optional. |
| **MIXER_OBJECTF_WAVEIN** | The *uMxId* parameter is the identifier of a waveform-audio input device in the range of zero to one less than the number of devices returned by the [waveInGetNumDevs](https://learn.microsoft.com/previous-versions/dd743844(v=vs.85)) function. |
| **MIXER_OBJECTF_WAVEOUT** | The *uMxId* parameter is the identifier of a waveform-audio output device in the range of zero to one less than the number of devices returned by the [waveOutGetNumDevs](https://learn.microsoft.com/previous-versions/dd743860(v=vs.85)) function. |

## Return value

Returns **MMSYSERR_NOERROR** if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_ALLOCATED** | The specified resource is already allocated by the maximum number of clients possible. |
| **MMSYSERR_BADDEVICEID** | The *uMxId* parameter specifies an invalid device identifier. |
| **MMSYSERR_INVALFLAG** | One or more flags are invalid. |
| **MMSYSERR_INVALHANDLE** | The *uMxId* parameter specifies an invalid handle. |
| **MMSYSERR_INVALPARAM** | One or more parameters are invalid. |
| **MMSYSERR_NODRIVER** | No mixer device is available for the object specified by *uMxId*. Note that the location referenced by *uMxId* will also contain the value –1. |
| **MMSYSERR_NOMEM** | Unable to allocate resources. |

## Remarks

Use the [mixerGetNumDevs](https://learn.microsoft.com/previous-versions/dd757304(v=vs.85)) function to determine the number of audio mixer devices present in the system. The device identifier specified by *uMxId* varies from zero to one less than the number of devices present.

If a window is chosen to receive callback information, the [MM_MIXM_LINE_CHANGE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mixm-line-change) and [MM_MIXM_CONTROL_CHANGE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mixm-control-change) messages are sent to the window procedure function to indicate when an audio line or control state changes. For both messages, the *wParam* parameter is the handle of the mixer device. The *lParam* parameter is the line identifier for **MM_MIXM_LINE_CHANGE** or the control identifier for **MM_MIXM_CONTROL_CHANGE** that changed state.

To query for audio mixer support or a media device, use the [mixerGetID](https://learn.microsoft.com/previous-versions/dd757301(v=vs.85)) function.

On 64-bit systems, this function may not work as expected in situations where you pass a 64-bit **LPHWAVEOUT** pointer in the *uMxId* parameter, because the *uMxId* parameter is truncated to 32 bits.

## See also

[Audio Mixer Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-functions)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)