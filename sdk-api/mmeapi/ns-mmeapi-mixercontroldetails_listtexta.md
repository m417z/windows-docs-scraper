# MIXERCONTROLDETAILS_LISTTEXTA structure

## Description

The MIXERCONTROLDETAILS_LISTTEXT structure retrieves list text, label text, and/or band-range information for multiple-item controls. This structure is used when the MIXER_GETCONTROLDETAILSF_LISTTEXT flag is specified in the mixerGetControlDetails function.

## Members

### `dwParam1`

 Control class-specific values. The following control types are listed with their corresponding values:

| Name | Description |
|------------|-------------|
| EQUALIZER | MIXERCONTROL. Bounds dwMinimum member.|
| MIXER and MUX | MIXERLINEdwLineID member.|
| MULTIPLESELECT and SINGLESELECT | Undefined; must be zero |

### `dwParam2`

See dwParam1.

### `szName`

Name describing a single item in a multiple-item control. This text can be used as a label or item text, depending on the control class.

## Remarks

The following standard control types use this structure for retrieving the item text descriptions on multiple-item controls:

Fader control:

MIXERCONTROL_CONTROLTYPE_EQUALIZER

List controls:

MIXERCONTROL_CONTROLTYPE_MIXER

MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT

MIXERCONTROL_CONTROLTYPE_MUX

MIXERCONTROL_CONTROLTYPE_SINGLESELECT

> [!NOTE]
> The mmeapi.h header defines MIXERCONTROLDETAILS_LISTTEXT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Audio Mixer Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-structures)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)

[MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola)

[mixerGetControlDetails](https://learn.microsoft.com/previous-versions/dd757299(v=vs.85))

[mixerSetControlDetails](https://learn.microsoft.com/previous-versions/dd757309(v=vs.85))