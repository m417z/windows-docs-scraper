# mixerSetControlDetails function

## Description

The **mixerSetControlDetails** function sets properties of a single control associated with an audio line.

## Parameters

### `hmxobj`

Handle to the mixer device object for which properties are being set.

### `pmxcd`

Pointer to a [MIXERCONTROLDETAILS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontroldetails_listtexta) structure. This structure is used to reference control detail structures that contain the desired state for the control.

### `fdwDetails`

Flags for setting properties for a control. The following values are defined.

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
| MIXER_OBJECTF_MIXER | The *hmxobj* parameter is a mixer device identifier in the range of zero to one less than the number of devices returned by the [mixerGetNumDevs](https://learn.microsoft.com/previous-versions/dd757304(v=vs.85)) function. This flag is optional. |
| MIXER_OBJECTF_WAVEIN | The *hmxobj* parameter is the identifier of a waveform-audio input device in the range of zero to one less than the number of devices returned by the [waveInGetNumDevs](https://learn.microsoft.com/previous-versions/dd743844(v=vs.85)) function. |
| MIXER_OBJECTF_WAVEOUT | The *hmxobj* parameter is the identifier of a waveform-audio output device in the range of zero to one less than the number of devices returned by the [waveOutGetNumDevs](https://learn.microsoft.com/previous-versions/dd743860(v=vs.85)) function. |
| MIXER_SETCONTROLDETAILSF_CUSTOM | A custom dialog box for the specified custom mixer control is displayed. The mixer device gathers the required information from the user and returns the data in the specified buffer. The handle for the owning window is specified in the **hwndOwner** member of the [MIXERCONTROLDETAILS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontroldetails_listtexta) structure. (This handle can be set to **NULL**.) The application can then save the data from the dialog box and use it later to reset the control to the same state by using the MIXER_SETCONTROLDETAILSF_VALUE flag. |
| MIXER_SETCONTROLDETAILSF_VALUE | The current value(s) for a control are set. The **paDetails** member of the [MIXERCONTROLDETAILS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontroldetails_listtexta) structure points to one or more mixer-control details structures of the appropriate class for the control. |

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MIXERR_INVALCONTROL** | The control reference is invalid. |
| **MMSYSERR_BADDEVICEID** | The *hmxobj* parameter specifies an invalid device identifier. |
| **MMSYSERR_INVALFLAG** | One or more flags are invalid. |
| **MMSYSERR_INVALHANDLE** | The *hmxobj* parameter specifies an invalid handle. |
| **MMSYSERR_INVALPARAM** | One or more parameters are invalid. |
| **MMSYSERR_NODRIVER** | No mixer device is available for the object specified by *hmxobj*. |

## Remarks

All members of the [MIXERCONTROLDETAILS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontroldetails_listtexta) structure must be initialized before calling **mixerSetControlDetails**.

If an application needs to retrieve only the current state of a custom mixer control and not display a dialog box, then [mixerGetControlDetails](https://learn.microsoft.com/previous-versions/dd757299(v=vs.85)) can be used with the MIXER_GETCONTROLDETAILSF_VALUE flag.

## See also

[Audio Mixer Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-functions)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)