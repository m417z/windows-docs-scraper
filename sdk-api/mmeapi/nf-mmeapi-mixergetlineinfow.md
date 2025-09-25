# mixerGetLineInfoW function

## Description

The **mixerGetLineInfo** function retrieves information about a specific line of a mixer device.

## Parameters

### `hmxobj`

Handle to the mixer device object that controls the specific audio line.

### `pmxl`

Pointer to a [MIXERLINE](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinea) structure. This structure is filled with information about the audio line for the mixer device. The **cbStruct** member must always be initialized to be the size, in bytes, of the **MIXERLINE** structure.

### `fdwInfo`

Flags for retrieving information about an audio line. The following values are defined.

| Value | Meaning |
| --- | --- |
| MIXER_GETLINEINFOF_COMPONENTTYPE | The *pmxl* parameter will receive information about the first audio line of the type specified in the **dwComponentType** member of the [MIXERLINE](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinea) structure. This flag is used to retrieve information about an audio line of a specific component type. Remaining structure members except **cbStruct** require no further initialization. |
| MIXER_GETLINEINFOF_DESTINATION | The *pmxl* parameter will receive information about the destination audio line specified by the **dwDestination** member of the [MIXERLINE](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinea) structure. This index ranges from zero to one less than the value in the **cDestinations** member of the [MIXERCAPS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercapsa) structure. All remaining structure members except **cbStruct** require no further initialization. |
| MIXER_GETLINEINFOF_LINEID | The *pmxl* parameter will receive information about the audio line specified by the **dwLineID** member of the [MIXERLINE](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinea) structure. This is usually used to retrieve updated information about the state of an audio line. All remaining structure members except **cbStruct** require no further initialization. |
| MIXER_GETLINEINFOF_SOURCE | The *pmxl* parameter will receive information about the source audio line specified by the **dwDestination** and **dwSource** members of the [MIXERLINE](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinea) structure. The index specified by **dwDestination** ranges from zero to one less than the value in the **cDestinations** member of the [MIXERCAPS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercapsa) structure. The index specified by **dwSource** ranges from zero to one less than the value in the **cConnections** member of the **MIXERLINE** structure returned for the audio line stored in the **dwDestination** member. All remaining structure members except **cbStruct** require no further initialization. |
| MIXER_GETLINEINFOF_TARGETTYPE | The *pmxl* parameter will receive information about the audio line that is for the **dwType** member of the **Target** structure, which is a member of the [MIXERLINE](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinea) structure. This flag is used to retrieve information about an audio line that handles the target type (for example, **MIXERLINE_TARGETTYPE_WAVEOUT**). The application must initialize the **dwType**, **wMid**, **wPid**, **vDriverVersion** and **szPname** members of the [MIXERLINE](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinea) structure before calling **mixerGetLineInfo**. All of these values can be retrieved from the device capabilities structures for all media devices. Remaining structure members except **cbStruct** require no further initialization.<br><br>**Note** In the ANSI version of this function (**mixerGetLineInfoA**), you cannot use the ANSI string returned from **mixerGetLineInfo** or [waveOutGetDevCaps](https://learn.microsoft.com/previous-versions/dd743857(v=vs.85)) for the value of the **psPname** string when calling **mixerGetLineInfo** with the **MIXER_GETLINEINFOF_TARGETTYPE** flag. The reason is that an internal conversion to and from Unicode is performed, which might result in loss of data. |
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

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
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
> The mmeapi.h header defines mixerGetLineInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).