# mixerGetID function

## Description

The **mixerGetID** function retrieves the device identifier for a mixer device associated with a specified device handle.

## Parameters

### `hmxobj`

Handle to the audio mixer object to map to a mixer device identifier.

### `puMxId`

Pointer to a variable that receives the mixer device identifier. If no mixer device is available for the *hmxobj* object, the value -1 is placed in this location and the MMSYSERR_NODRIVER error value is returned.

### `fdwId`

Flags for mapping the mixer object *hmxobj*. The following values are defined.

| Value | Meaning |
| --- | --- |
| MIXER_OBJECTF_AUX | The *hmxobj* parameter is an auxiliary device identifier in the range of zero to one less than the number of devices returned by the [auxGetNumDevs](https://learn.microsoft.com/previous-versions/dd756713(v=vs.85)) function. |
| MIXER_OBJECTF_HMIDIIN | The *hmxobj* parameter is the handle of a MIDI input device. This handle must have been returned by the [midiInOpen](https://learn.microsoft.com/previous-versions/dd798458(v=vs.85)) function. |
| MIXER_OBJECTF_HMIDIOUT | The *hmxobj* parameter is the handle of a MIDI output device. This handle must have been returned by the [midiOutOpen](https://learn.microsoft.com/previous-versions/dd798476(v=vs.85)) function. |
| MIXER_OBJECTF_HMIXER | The *hmxobj* parameter is a mixer device handle returned by the [mixerOpen](https://learn.microsoft.com/previous-versions/dd757308(v=vs.85)) function. This flag is optional. |
| MIXER_OBJECTF_HWAVEIN | The *hmxobj* parameter is a waveform-audio input handle returned by the [waveInOpen](https://learn.microsoft.com/previous-versions/dd743847(v=vs.85)) function. |
| MIXER_OBJECTF_HWAVEOUT | The *hmxobj* parameter is a waveform-audio output handle returned by the [waveOutOpen](https://learn.microsoft.com/previous-versions/dd743866(v=vs.85)) function. |
| MIXER_OBJECTF_MIDIIN | The *hmxobj* parameter is the identifier of a MIDI input device. This identifier must be in the range of zero to one less than the number of devices returned by the [midiInGetNumDevs](https://learn.microsoft.com/previous-versions/dd798456(v=vs.85)) function. |
| MIXER_OBJECTF_MIDIOUT | The *hmxobj* parameter is the identifier of a MIDI output device. This identifier must be in the range of zero to one less than the number of devices returned by the [midiOutGetNumDevs](https://learn.microsoft.com/previous-versions/dd798472(v=vs.85)) function. |
| MIXER_OBJECTF_MIXER | The *hmxobj* parameter is the identifier of a mixer device in the range of zero to one less than the number of devices returned by the [mixerGetNumDevs](https://learn.microsoft.com/previous-versions/dd757304(v=vs.85)) function. This flag is optional. |
| MIXER_OBJECTF_WAVEIN | The *hmxobj* parameter is the identifier of a waveform-audio input device in the range of zero to one less than the number of devices returned by the [waveInGetNumDevs](https://learn.microsoft.com/previous-versions/dd743844(v=vs.85)) function. |
| MIXER_OBJECTF_WAVEOUT | The *hmxobj* parameter is the identifier of a waveform-audio output device in the range of zero to one less than the number of devices returned by the [waveOutGetNumDevs](https://learn.microsoft.com/previous-versions/dd743860(v=vs.85)) function. |

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_BADDEVICEID** | The *hmxobj* parameter specifies an invalid device identifier. |
| **MMSYSERR_INVALFLAG** | One or more flags are invalid. |
| **MMSYSERR_INVALHANDLE** | The *hmxobj* parameter specifies an invalid handle. |
| **MMSYSERR_INVALPARAM** | One or more parameters are invalid. |
| **MMSYSERR_NODRIVER** | No audio mixer device is available for the object specified by *hmxobj*. The location referenced by *puMxId* also contains the value -1. |

## See also

[Audio Mixer Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-functions)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)