# mixerGetControlDetailsW function

## Description

The **mixerGetControlDetails** function retrieves details about a single control associated with an audio line.

## Parameters

### `hmxobj`

Handle to the mixer device object being queried.

### `pmxcd`

Pointer to a [MIXERCONTROLDETAILS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontroldetails_listtexta) structure, which is filled with state information about the control.

### `fdwDetails`

Flags for retrieving control details. The following values are defined.

| Value | Meaning |
| --- | --- |
| MIXER_GETCONTROLDETAILSF_LISTTEXT | The **paDetails** member of the [MIXERCONTROLDETAILS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontroldetails_listtexta) structure points to one or more [MIXERCONTROLDETAILS_LISTTEXT](https://learn.microsoft.com/previous-versions/dd757296(v=vs.85)) structures to receive text labels for multiple-item controls. An application must get all list text items for a multiple-item control at once. This flag cannot be used with MIXERCONTROL_CONTROLTYPE_CUSTOM controls. |
| MIXER_GETCONTROLDETAILSF_VALUE | Current values for a control are retrieved. The **paDetails** member of the [MIXERCONTROLDETAILS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontroldetails_listtexta) structure points to one or more details structures appropriate for the control class. |
| MIXER_OBJECTF_AUX | The *hmxobj* parameter is an auxiliary device identifier in the range of zero to one less than the number of devices returned by the [auxGetNumDevs](https://learn.microsoft.com/previous-versions/dd756713(v=vs.85)) function. |
| MIXER_OBJECTF_HMIDIIN | The *hmxobj* parameter is the handle of a MIDI (Musical Instrument Digital Interface) input device. This handle must have been returned by the [midiInOpen](https://learn.microsoft.com/previous-versions/dd798458(v=vs.85)) function. |
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
| **MIXERR_INVALCONTROL** | The control reference is invalid. |
| **MMSYSERR_BADDEVICEID** | The *hmxobj* parameter specifies an invalid device identifier. |
| **MMSYSERR_INVALFLAG** | One or more flags are invalid. |
| **MMSYSERR_INVALHANDLE** | The *hmxobj* parameter specifies an invalid handle. |
| **MMSYSERR_INVALPARAM** | One or more parameters are invalid. |
| **MMSYSERR_NODRIVER** | No mixer device is available for the object specified by *hmxobj*. |

## Remarks

All members of the [MIXERCONTROLDETAILS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontroldetails_listtexta) structure must be initialized before calling this function.

> [!NOTE]
> The mmeapi.h header defines mixerGetControlDetails as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Audio Mixer Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-functions)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)