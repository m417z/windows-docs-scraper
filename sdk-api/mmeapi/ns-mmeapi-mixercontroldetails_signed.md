# MIXERCONTROLDETAILS_SIGNED structure

## Description

The MIXERCONTROLDETAILS_SIGNED structure retrieves and sets signed type control properties for an audio mixer control.

## Members

### `lValue`

Signed integer value for a single item or channel. This value must be inclusively within the bounds given in the Bounds member of this structure for signed integer controls.

## Remarks

The following standard control types use this structure for retrieving and setting properties:

Meter controls:

MIXERCONTROL_CONTROLTYPE_PEAKMETER

MIXERCONTROL_CONTROLTYPE_SIGNEDMETER

Member controls:

MIXERCONTROL_CONTROLTYPE_SIGNED

Number controls:

MIXERCONTROL_CONTROLTYPE_DECIBELS

Slider controls:

MIXERCONTROL_CONTROLTYPE_PAN

MIXERCONTROL_CONTROLTYPE_QSOUNDPAN

MIXERCONTROL_CONTROLTYPE_SLIDER

## See also

[Audio Mixer Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-structures)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)

[MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola)

[mixerGetControlDetails](https://learn.microsoft.com/previous-versions/dd757299(v=vs.85))

[mixerSetControlDetails](https://learn.microsoft.com/previous-versions/dd757309(v=vs.85))