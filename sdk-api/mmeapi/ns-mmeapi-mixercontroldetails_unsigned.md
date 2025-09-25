# MIXERCONTROLDETAILS_UNSIGNED structure

## Description

The MIXERCONTROLDETAILS_UNSIGNED structure retrieves and sets unsigned type control properties for an audio mixer control.

## Members

### `dwValue`

Unsigned integer value for a single item or channel. This value must be inclusively within the bounds given in the Bounds structure member of the MIXERCONTROL structure for unsigned integer controls.

## Remarks

The following standard control types use this structure for retrieving and setting properties:

Meter control:

MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER

Number control:

MIXERCONTROL_CONTROLTYPE_UNSIGNED

Fader controls:

MIXERCONTROL_CONTROLTYPE_BASS

MIXERCONTROL_CONTROLTYPE_EQUALIZER

MIXERCONTROL_CONTROLTYPE_FADER

MIXERCONTROL_CONTROLTYPE_TREBLE

MIXERCONTROL_CONTROLTYPE_VOLUME

Time controls:

MIXERCONTROL_CONTROLTYPE_MICROTIME

MIXERCONTROL_CONTROLTYPE_MILLITIME

MIXERCONTROL_CONTROLTYPE_PERCENT

## See also

[Audio Mixer Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-structures)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)

[MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola)

[mixerGetControlDetails](https://learn.microsoft.com/previous-versions/dd757299(v=vs.85))

[mixerSetControlDetails](https://learn.microsoft.com/previous-versions/dd757309(v=vs.85))