# mixerGetLineControlsA function

## Description

The **mixerGetLineControls** function retrieves one or more controls associated with an audio line.

## Parameters

### `hmxobj`

Handle to the mixer device object that is being queried.

### `pmxlc`

Pointer to a [MIXERLINECONTROLS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinecontrolsa) structure. This structure is used to reference one or more [MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola) structures to be filled with information about the controls associated with an audio line. The **cbStruct** member of the **MIXERLINECONTROLS** structure must always be initialized to be the size, in bytes, of the **MIXERLINECONTROLS** structure.

### `fdwControls`

Flags for retrieving information about one or more controls associated with an audio line. The following values are defined.

| Value | Meaning |
| --- | --- |
| MIXER_GETLINECONTROLSF_ALL | The *pmxlc* parameter references a list of [MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola) structures that will receive information on all controls associated with the audio line identified by the **dwLineID** member of the [MIXERLINECONTROLS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinecontrolsa) structure. The **cControls** member must be initialized to the number of controls associated with the line. This number is retrieved from the **cControls** member of the [MIXERLINE](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinea) structure returned by the [mixerGetLineInfo](https://learn.microsoft.com/previous-versions/dd757303(v=vs.85)) function. The **cbmxctrl** member must be initialized to the size, in bytes, of a single **MIXERCONTROL** structure. The **pamxctrl** member must point to the first **MIXERCONTROL** structure to be filled. The **dwControlID** and **dwControlType** members are ignored for this query. |
| MIXER_GETLINECONTROLSF_ONEBYID | The *pmxlc* parameter references a single [MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola) structure that will receive information on the control identified by the **dwControlID** member of the [MIXERLINECONTROLS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinecontrolsa) structure. The **cControls** member must be initialized to 1. The **cbmxctrl** member must be initialized to the size, in bytes, of a single **MIXERCONTROL** structure. The **pamxctrl** member must point to a **MIXERCONTROL** structure to be filled. The **dwLineID** and **dwControlType** members are ignored for this query. This query is usually used to refresh a control after receiving a [MM_MIXM_CONTROL_CHANGE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-mixm-control-change) control change notification message by the user-defined callback (see [mixerOpen](https://learn.microsoft.com/previous-versions/dd757308(v=vs.85))). |
| MIXER_GETLINECONTROLSF_ONEBYTYPE | The **mixerGetLineControls** function retrieves information about the first control of a specific class for the audio line that is being queried. The *pmxlc* parameter references a single [MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola) structure that will receive information about the specific control. The audio line is identified by the **dwLineID** member. The control class is specified in the **dwControlType** member of the [MIXERLINECONTROLS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinecontrolsa) structure.The **dwControlID** member is ignored for this query. This query can be used by an application to get information on a single control associated with a line. For example, you might want your application to use a peak meter only from a waveform-audio output line. |
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
| **MIXERR_INVALCONTROL** | The control reference is invalid. |
| **MIXERR_INVALLINE** | The audio line reference is invalid. |
| **MMSYSERR_BADDEVICEID** | The *hmxobj* parameter specifies an invalid device identifier. |
| **MMSYSERR_INVALFLAG** | One or more flags are invalid. |
| **MMSYSERR_INVALHANDLE** | The *hmxobj* parameter specifies an invalid handle. |
| **MMSYSERR_INVALPARAM** | One or more parameters are invalid. |
| **MMSYSERR_NODRIVER** | No mixer device is available for the object specified by *hmxobj*. |

## See also

[Audio Mixer Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-functions)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)

## Remarks

> [!NOTE]
> The mmeapi.h header defines mixerGetLineControls as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).