# APO_FLAG enumeration

## Description

The APO_FLAG enumeration defines constants that are used as flags by an audio processing object (APO).

This enumeration is used by the [APO_REG_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ns-audioenginebaseapo-apo_reg_properties) structure to help describe the registration properties of an APO.

## Constants

### `APO_FLAG_NONE`

Indicates that there are no flags enabled for this APO.

### `APO_FLAG_INPLACE`

Indicates that this APO can perform in-place processing. This allows the processor to use a common buffer for input and output.

### `APO_FLAG_SAMPLESPERFRAME_MUST_MATCH`

Indicates that the samples per frame for the input and output connections must match.

### `APO_FLAG_FRAMESPERSECOND_MUST_MATCH`

Indicates that the frames per second for the input and output connections must match.

### `APO_FLAG_BITSPERSAMPLE_MUST_MATCH`

Indicates that bits per sample AND bytes per sample container for the input and output connections must match.

### `APO_FLAG_MIXER`

### `APO_FLAG_DEFAULT`

The value of this member is determined by the logical OR result of the three preceding members. In other words:

APO_FLAG_DEFAULT = ( APO_FLAG_SAMPLESPERFRAME_MUST_MATCH | APO_FLAG_FRAMESPERSECOND_MUST_MATCH | APO_FLAG_BITSPERSAMPLE_MUST_MATCH ).

## See also

[APO_REG_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ns-audioenginebaseapo-apo_reg_properties)