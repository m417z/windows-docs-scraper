# D2D1_WHITELEVELADJUSTMENT_PROP enumeration

## Description

Defines constants that identify the top level properties of the [White level adjustment effect](https://learn.microsoft.com/windows/desktop/Direct2D/white-level-adjustment-effect). The effect adjusts the white level of the source image by multiplying the source image color by the ratio of the input and output white levels. Input and output white levels are specified in nits.

## Constants

### `D2D1_WHITELEVELADJUSTMENT_PROP_INPUT_WHITE_LEVEL` (0)

Identifies the `InputWhiteLevel` property of the effect. The property is of type FLOAT, and is specified in nits.

### `D2D1_WHITELEVELADJUSTMENT_PROP_OUTPUT_WHITE_LEVEL` (1)

Identifies the `OutputWhiteLevel` property of the effect. The property is of type FLOAT, and is specified in nits.

### `D2D1_WHITELEVELADJUSTMENT_PROP_FORCE_DWORD` (0xFFFFFFFF)