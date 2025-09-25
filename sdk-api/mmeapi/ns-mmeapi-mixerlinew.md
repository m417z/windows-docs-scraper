# MIXERLINEW structure

## Description

The **MIXERLINE** structure describes the state and metrics of an audio line.

## Members

### `cbStruct`

Size, in bytes, of the **MIXERLINE** structure. This member must be initialized before calling the [mixerGetLineInfo](https://learn.microsoft.com/previous-versions/dd757303(v=vs.85)) function. The size specified in this member must be large enough to contain the **MIXERLINE** structure. When **mixerGetLineInfo** returns, this member contains the actual size of the information returned. The returned information will not exceed the requested size.

### `dwDestination`

Destination line index. This member ranges from zero to one less than the value specified in the **cDestinations** member of the [MIXERCAPS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercapsa) structure retrieved by the [mixerGetDevCaps](https://learn.microsoft.com/previous-versions/dd757300(v=vs.85)) function. When the [mixerGetLineInfo](https://learn.microsoft.com/previous-versions/dd757303(v=vs.85)) function is called with the MIXER_GETLINEINFOF_DESTINATION flag, properties for the destination line are returned. (The **dwSource** member must be set to zero in this case.) When called with the MIXER_GETLINEINFOF_SOURCE flag, the properties for the source given by the **dwSource** member that is associated with the **dwDestination** member are returned.

### `dwSource`

Index for the audio source line associated with the **dwDestination** member. That is, this member specifies the *n*th audio source line associated with the specified audio destination line. This member is not used for destination lines and must be set to zero when MIXER_GETLINEINFOF_DESTINATION is specified in the [mixerGetLineInfo](https://learn.microsoft.com/previous-versions/dd757303(v=vs.85)) function. When the MIXER_GETLINEINFOF_SOURCE flag is specified, this member ranges from zero to one less than the value specified in the **cConnections** member for the audio destination line given in the **dwDestination** member.

### `dwLineID`

An identifier defined by the mixer device that uniquely refers to the audio line described by the **MIXERLINE** structure. This identifier is unique for each mixer device and can be in any format. An application should use this identifier only as an abstract handle.

### `fdwLine`

Status and support flags for the audio line. This member is always returned to the application and requires no initialization.

| Name | Description |
| --- | --- |
| **MIXERLINE_LINEF_ACTIVE** | Audio line is active. An active line indicates that a signal is probably passing through the line. |
| **MIXERLINE_LINEF_DISCONNECTED** | Audio line is disconnected. A disconnected line's associated controls can still be modified, but the changes have no effect until the line is connected. |
| **MIXERLINE_LINEF_SOURCE** | Audio line is an audio source line associated with a single audio destination line. If this flag is not set, this line is an audio destination line associated with zero or more audio source lines. |

If an application is not using a waveform-audio output device, the audio line associated with that device would not be active (that is, the MIXERLINE_LINEF_ACTIVE flag would not be set).

If the waveform-audio output device is opened, then the audio line is considered active and the MIXERLINE_LINEF_ACTIVE flag will be set.

A paused or starved waveform-audio output device is still considered active. In other words, if the waveform-audio output device is opened by an application regardless of whether data is being played, the associated audio line is considered active.

If a line cannot be strictly defined as active, the mixer device will always set the MIXERLINE_LINEF_ACTIVE flag.

### `dwUser`

Instance data defined by the audio device for the line. This member is intended for custom mixer applications designed specifically for the mixer device returning this information. Other applications should ignore this data.

### `dwComponentType`

Component type for this audio line. An application can use this information to display tailored graphics or to search for a particular component. If an application does not use component types, this member should be ignored. This member can be one of the following values:

| Name | Description |
| --- | --- |
| **MIXERLINE_COMPONENTTYPE_DST_DIGITAL** | Audio line is a digital destination (for example, digital input to a DAT or CD audio device). |
| **MIXERLINE_COMPONENTTYPE_DST_HEADPHONES** | Audio line is an adjustable (gain and/or attenuation) destination intended to drive headphones. Most audio cards use the same audio destination line for speakers and headphones, in which case the mixer device simply uses the MIXERLINE_COMPONENTTYPE_DST_SPEAKERS type. |
| **MIXERLINE_COMPONENTTYPE_DST_LINE** | Audio line is a line level destination (for example, line level input from a CD audio device) that will be the final recording source for the analog-to-digital converter (ADC). Because most audio cards for personal computers provide some sort of gain for the recording audio source line, the mixer device will use the MIXERLINE_COMPONENTTYPE_DST_WAVEIN type. |
| **MIXERLINE_COMPONENTTYPE_DST_MONITOR** | Audio line is a destination used for a monitor. |
| **MIXERLINE_COMPONENTTYPE_DST_SPEAKERS** | Audio line is an adjustable (gain and/or attenuation) destination intended to drive speakers. This is the typical component type for the audio output of audio cards for personal computers. |
| **MIXERLINE_COMPONENTTYPE_DST_TELEPHONE** | Audio line is a destination that will be routed to a telephone line. |
| **MIXERLINE_COMPONENTTYPE_DST_UNDEFINED** | Audio line is a destination that cannot be defined by one of the standard component types. A mixer device is required to use this component type for line component types that have not been defined by Microsoft Corporation. |
| **MIXERLINE_COMPONENTTYPE_DST_VOICEIN** | Audio line is a destination that will be the final recording source for voice input. This component type is exactly like MIXERLINE_COMPONENTTYPE_DST_WAVEIN but is intended specifically for settings used during voice recording/recognition. Support for this line is optional for a mixer device. Many mixer devices provide only MIXERLINE_COMPONENTTYPE_DST_WAVEIN. |
| **MIXERLINE_COMPONENTTYPE_DST_WAVEIN** | Audio line is a destination that will be the final recording source for the waveform-audio input (ADC). This line typically provides some sort of gain or attenuation. This is the typical component type for the recording line of most audio cards for personal computers. |
| **MIXERLINE_COMPONENTTYPE_SRC_ANALOG** | Audio line is an analog source (for example, analog output from a video-cassette tape). |
| **MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY** | Audio line is a source originating from the auxiliary audio line. This line type is intended as a source with gain or attenuation that can be routed to the MIXERLINE_COMPONENTTYPE_DST_SPEAKERS destination and/or recorded from the MIXERLINE_COMPONENTTYPE_DST_WAVEIN destination. |
| **MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC** | Audio line is a source originating from the output of an internal audio CD. This component type is provided for audio cards that provide an audio source line intended to be connected to an audio CD (or CD-ROM playing an audio CD). |
| **MIXERLINE_COMPONENTTYPE_SRC_DIGITAL** | Audio line is a digital source (for example, digital output from a DAT or audio CD). |
| **MIXERLINE_COMPONENTTYPE_SRC_LINE** | Audio line is a line-level source (for example, line-level input from an external stereo) that can be used as an optional recording source. Because most audio cards for personal computers provide some sort of gain for the recording source line, the mixer device will use the MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY type. |
| **MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE** | Audio line is a microphone recording source. Most audio cards for personal computers provide at least two types of recording sources: an auxiliary audio line and microphone input. A microphone audio line typically provides some sort of gain. Audio cards that use a single input for use with a microphone or auxiliary audio line should use the MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE component type. |
| **MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER** | Audio line is a source originating from personal computer speaker. Several audio cards for personal computers provide the ability to mix what would typically be played on the internal speaker with the output of an audio card. Some audio cards support the ability to use this output as a recording source. |
| **MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER** | Audio line is a source originating from the output of an internal synthesizer. Most audio cards for personal computers provide some sort of MIDI synthesizer. |
| **MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE** | Audio line is a source originating from an incoming telephone line. |
| **MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED** | Audio line is a source that cannot be defined by one of the standard component types. A mixer device is required to use this component type for line component types that have not been defined by Microsoft Corporation. |
| **MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT** | Audio line is a source originating from the waveform-audio output digital-to-analog converter (DAC). Most audio cards for personal computers provide this component type as a source to the MIXERLINE_COMPONENTTYPE_DST_SPEAKERS destination. Some cards also allow this source to be routed to the MIXERLINE_COMPONENTTYPE_DST_WAVEIN destination. |

### `cChannels`

Maximum number of separate channels that can be manipulated independently for the audio line. The minimum value for this field is 1 because a line must have at least one channel.

Most modern audio cards for personal computers are stereo devices; for them, the value of this member is 2.

Channel 1 is assumed to be the left channel; channel 2 is assumed to be the right channel.

A multichannel line might have one or more uniform controls (controls that affect all channels of a line uniformly) associated with it.

### `cConnections`

Number of connections that are associated with the audio line. This member is used only for audio destination lines and specifies the number of audio source lines that are associated with it. This member is always zero for source lines and for destination lines that do not have any audio source lines associated with them.

### `cControls`

Number of controls associated with the audio line. This value can be zero. If no controls are associated with the line, the line is likely to be a source that might be selected in a MIXERCONTROL_CONTROLTYPE_MUX or MIXERCONTROL_CONTROLTYPE_MIXER but allows no manipulation of the signal.

### `szShortName`

Short string that describes the audio mixer line specified in the **dwLineID** member. This description should be appropriate as a concise label for the line.

### `szName`

String that describes the audio mixer line specified in the **dwLineID** member. This description should be appropriate as a complete description for the line.

### `Target`

Target media information.

### `Target.dwType`

Target media device type associated with the audio line described in the **MIXERLINE** structure. An application must ignore target information for media device types it does not use. The following values are defined:

| Name | Description |
| --- | --- |
| **MIXERLINE_TARGETTYPE_AUX** | The audio line described by the **MIXERLINE** structure is strictly bound to the auxiliary device detailed in the remaining members of the **Target** structure member of the **MIXERLINE** structure. |
| **MIXERLINE_TARGETTYPE_MIDIIN** | The audio line described by the **MIXERLINE** structure is strictly bound to the MIDI input device detailed in the remaining members of the **Target** structure member of the **MIXERLINE** structure. |
| **MIXERLINE_TARGETTYPE_MIDIOUT** | The audio line described by the **MIXERLINE** structure is strictly bound to the MIDI output device detailed in the remaining members of the **Target** structure member of the **MIXERLINE** structure. |
| **MIXERLINE_TARGETTYPE_UNDEFINED** | The audio line described by the **MIXERLINE** structure is not strictly bound to a defined media type. All remaining **Target** structure members of the **MIXERLINE** structure should be ignored. An application cannot use the MIXERLINE_TARGETTYPE_UNDEFINED target type when calling the [mixerGetLineInfo](https://learn.microsoft.com/previous-versions/dd757303(v=vs.85)) function with the MIXER_GETLINEINFOF_TARGETTYPE flag. |
| **MIXERLINE_TARGETTYPE_WAVEIN** | The audio line described by the **MIXERLINE** structure is strictly bound to the waveform-audio input device detailed in the remaining members of the **Target** structure member of the **MIXERLINE** structure. |
| **MIXERLINE_TARGETTYPE_WAVEOUT** | The audio line described by the **MIXERLINE** structure is strictly bound to the waveform-audio output device detailed in the remaining members of the **Target** structure member of the **MIXERLINE** structure. |

### `Target.dwDeviceID`

Current device identifier of the target media device when the **dwType** member is a target type other than MIXERLINE_TARGETTYPE_UNDEFINED. This identifier is identical to the current media device index of the associated media device. When calling the [mixerGetLineInfo](https://learn.microsoft.com/previous-versions/dd757303(v=vs.85)) function with the MIXER_GETLINEINFOF_TARGETTYPE flag, this member is ignored on input and will be returned to the caller by the audio mixer manager.

### `Target.wMid`

Manufacturer identifier of the target media device when the **dwType** member is a target type other than MIXERLINE_TARGETTYPE_UNDEFINED. This identifier is identical to the **wMid** member of the device-capabilities structure for the associated media. Manufacturer identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `Target.wPid`

Product identifier of the target media device when the **dwType** member is a target type other than MIXERLINE_TARGETTYPE_UNDEFINED. This identifier is identical to the **wPid** member of the device-capabilities structure for the associated media. Product identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `Target.vDriverVersion`

Driver version of the target media device when the **dwType** member is a target type other than MIXERLINE_TARGETTYPE_UNDEFINED. This version is identical to the **vDriverVersion** member of the device-capabilities structure for the associated media.

### `Target.szPname`

Product name of the target media device when the **dwType** member is a target type other than MIXERLINE_TARGETTYPE_UNDEFINED. This name is identical to the **szPname** member of the device-capabilities structure for the associated media.

## See also

[Audio Mixer Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-structures)

Audio Mixers

[MIXERCAPS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercapsa)

[mixerGetDevCaps](https://learn.microsoft.com/previous-versions/dd757300(v=vs.85))

[mixerGetLineInfo](https://learn.microsoft.com/previous-versions/dd757303(v=vs.85))

## Remarks

> [!NOTE]
> The mmeapi.h header defines MIXERLINE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).