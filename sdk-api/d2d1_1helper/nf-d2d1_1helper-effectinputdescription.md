# EffectInputDescription function

## Description

Creates a [D2D1_EFFECT_INPUT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_effect_input_description) structure.

## Parameters

### `effect`

Type: **[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)***

The effect whose input connection is being specified.

### `inputIndex`

Type: **UINT32**

The input index of the effect that is being considered.

### `inputRectangle`

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

The amount of data that would be available on the input. This can be used to query this information when the data is not yet available.

## Return value

Type: **[D2D1_EFFECT_INPUT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_effect_input_description)**

The filled description structure that describes the input to the effect.