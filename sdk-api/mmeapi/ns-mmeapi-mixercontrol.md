# MIXERCONTROL structure

## Description

The **MIXERCONTROL** structure describes the state and metrics of a single control for an audio line.

## Members

### `cbStruct`

Size, in bytes, of the **MIXERCONTROL** structure.

### `dwControlID`

Audio mixer-defined identifier that uniquely refers to the control described by the **MIXERCONTROL** structure. This identifier can be in any format supported by the mixer device. An application should use this identifier only as an abstract handle. No two controls for a single mixer device can ever have the same control identifier.

### `dwControlType`

Class of the control for which the identifier is specified in **dwControlID**. An application must use this information to display the appropriate control for input from the user. An application can also display tailored graphics based on the control class or search for a particular control class on a specific line. If an application does not know about a control class, this control must be ignored. There are eight control class classifications, each with one or more standard control types:

| Name | Descriptions |
| --- | --- |
| **MIXERCONTROL_CT_CLASS_CUSTOM** | MIXERCONTROL_CONTROLTYPE_CUSTOM |
| **MIXERCONTROL_CT_CLASS_FADER** | MIXERCONTROL_CONTROLTYPE_BASS MIXERCONTROL_CONTROLTYPE_EQUALIZER MIXERCONTROL_CONTROLTYPE_FADER MIXERCONTROL_CONTROLTYPE_TREBLE MIXERCONTROL_CONTROLTYPE_VOLUME |
| **MIXERCONTROL_CT_CLASS_LIST** | MIXERCONTROL_CONTROLTYPE_MIXER MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT MIXERCONTROL_CONTROLTYPE_MUX MIXERCONTROL_CONTROLTYPE_SINGLESELECT |
| **MIXERCONTROL_CT_CLASS_METER** | MIXERCONTROL_CONTROLTYPE_BOOLEANMETER MIXERCONTROL_CONTROLTYPE_PEAKMETER MIXERCONTROL_CONTROLTYPE_SIGNEDMETER MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER |
| **MIXERCONTROL_CT_CLASS_NUMBER** | MIXERCONTROL_CONTROLTYPE_DECIBELS MIXERCONTROL_CONTROLTYPE_PERCENT MIXERCONTROL_CONTROLTYPE_SIGNED MIXERCONTROL_CONTROLTYPE_UNSIGNED |
| **MIXERCONTROL_CT_CLASS_SLIDER** | MIXERCONTROL_CONTROLTYPE_PAN MIXERCONTROL_CONTROLTYPE_QSOUNDPAN MIXERCONTROL_CONTROLTYPE_SLIDER |
| **MIXERCONTROL_CT_CLASS_SWITCH** | MIXERCONTROL_CONTROLTYPE_BOOLEAN MIXERCONTROL_CONTROLTYPE_BUTTON MIXERCONTROL_CONTROLTYPE_LOUDNESS MIXERCONTROL_CONTROLTYPE_MONO MIXERCONTROL_CONTROLTYPE_MUTE MIXERCONTROL_CONTROLTYPE_ONOFF MIXERCONTROL_CONTROLTYPE_STEREOENH |
| **MIXERCONTROL_CT_CLASS_TIME** | MIXERCONTROL_CONTROLTYPE_MICROTIME MIXERCONTROL_CONTROLTYPE_MILLITIME |

### `fdwControl`

Status and support flags for the audio line control. The following values are defined:

| Name | Description |
| --- | --- |
| **MIXERCONTROL_CONTROLF_DISABLED** | The control is disabled, perhaps due to other settings for the mixer hardware, and cannot be used. An application can read current settings from a disabled control, but it cannot apply settings. |
| **MIXERCONTROL_CONTROLF_MULTIPLE** | The control has two or more settings per channel. An equalizer, for example, requires this flag because each frequency band can be set to a different value. An equalizer that affects both channels of a stereo line in a uniform fashion will also specify the MIXERCONTROL_CONTROLF_UNIFORM flag. |
| **MIXERCONTROL_CONTROLF_UNIFORM** | The control acts on all channels of a multichannel line in a uniform fashion. For example, a control that mutes both channels of a stereo line would set this flag. Most MIXERCONTROL_CONTROLTYPE_MUX and MIXERCONTROL_CONTROLTYPE_MIXER controls also specify the MIXERCONTROL_CONTROLF_UNIFORM flag. |

### `cMultipleItems`

Number of items per channel that make up a MIXERCONTROL_CONTROLF_MULTIPLE control. This number is always two or greater for multiple-item controls. If the control is not a multiple-item control, do not use this member; it will be zero.

### `szShortName`

Short string that describes the audio line control specified by **dwControlID**. This description should be appropriate to use as a concise label for the control.

### `szName`

String that describes the audio line control specified by **dwControlID**. This description should be appropriate to use as a complete description for the control.

### `Bounds`

Union of boundary types.

### `Bounds.DUMMYSTRUCTNAME`

### `Bounds.DUMMYSTRUCTNAME.lMinimum`

Minimum signed value for a control that has a signed boundary nature. This member cannot be used in conjunction with **dwMinimum**.

### `Bounds.DUMMYSTRUCTNAME.lMaximum`

Maximum signed value for a control that has a signed boundary nature. This member cannot be used in conjunction with **dwMaximum**.

### `Bounds.DUMMYSTRUCTNAME2`

### `Bounds.DUMMYSTRUCTNAME2.dwMinimum`

Minimum unsigned value for a control that has an unsigned boundary nature. This member cannot be used in conjunction with **lMinimum**.

### `Bounds.DUMMYSTRUCTNAME2.dwMaximum`

Maximum unsigned value for a control that has an unsigned boundary nature. This member cannot be used in conjunction with **lMaximum**.

### `Bounds.dwReserved`

Reserved; do not use.

### `Metrics`

Union of boundary metrics.

### `Metrics.cSteps`

Number of discrete ranges within the union specified for a control specified by the **Bounds** member. This member overlaps with the other members of the **Metrics** structure member and cannot be used in conjunction with those members.

### `Metrics.cbCustomData`

Size, in bytes, required to contain the state of a custom control class. This member is appropriate only for the MIXERCONTROL_CONTROLTYPE_CUSTOM control class.

### `Metrics.dwReserved`

Reserved; do not use.

## See also

[Audio Mixer Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-structures)

Audio Mixers

[MIXERLINECONTROLS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinecontrolsa)

[mixerGetLineControls](https://learn.microsoft.com/previous-versions/dd757302(v=vs.85))