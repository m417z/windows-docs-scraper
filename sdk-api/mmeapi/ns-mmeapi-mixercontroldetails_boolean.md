# MIXERCONTROLDETAILS_BOOLEAN structure

## Description

The **MIXERCONTROLDETAILS_BOOLEAN** structure retrieves and sets Boolean control properties for an audio mixer control

## Members

### `fValue`

Boolean value for a single item or channel. This value is assumed to be zero for a FALSE state (such as off or disabled), and nonzero for a TRUE state (such as on or enabled).

## Remarks

The following standard control types use this structure for retrieving and setting properties.

Meter controls:

MIXERCONTROL_CONTROLTYPE_BOOLEANMETER

Switch controls:

MIXERCONTROL_CONTROLTYPE_BOOLEAN

MIXERCONTROL_CONTROLTYPE_BUTTON

MIXERCONTROL_CONTROLTYPE_LOUDNESS

MIXERCONTROL_CONTROLTYPE_MONO

MIXERCONTROL_CONTROLTYPE_MUTE

MIXERCONTROL_CONTROLTYPE_ONOFF

MIXERCONTROL_CONTROLTYPE_STEREOENH

List controls:

MIXERCONTROL_CONTROLTYPE_MIXER

MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT

MIXERCONTROL_CONTROLTYPE_MUX

MIXERCONTROL_CONTROLTYPE_SINGLESELECT

## See also

[Audio Mixer Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-structures)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)

[MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola)

[mixerGetControlDetails](https://learn.microsoft.com/previous-versions/dd757299(v=vs.85))

[mixerSetControlDetails](https://learn.microsoft.com/previous-versions/dd757309(v=vs.85))