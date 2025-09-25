# D2D1_COLORMANAGEMENT_PROP enumeration

## Description

Identifiers for the properties of the [Color management effect](https://learn.microsoft.com/windows/desktop/Direct2D/color-management).

## Constants

### `D2D1_COLORMANAGEMENT_PROP_SOURCE_COLOR_CONTEXT:0`

The source color space information.

The type is [ID2D1ColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1colorcontext).

The default value is NULL.

### `D2D1_COLORMANAGEMENT_PROP_SOURCE_RENDERING_INTENT:1`

Which ICC rendering intent to use.

The type is [D2D1_COLORMANAGEMENT_RENDERING_INTENT](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_colormanagement_rendering_intent).

The default value is D2D1_COLORMANAGEMENT_RENDERING_INTENT_PERCEPTUAL.

### `D2D1_COLORMANAGEMENT_PROP_DESTINATION_COLOR_CONTEXT:2`

The destination color space information.

The type is [ID2D1ColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1colorcontext).

The default value is NULL.

### `D2D1_COLORMANAGEMENT_PROP_DESTINATION_RENDERING_INTENT:3`

Which ICC rendering intent to use.

The type is [D2D1_COLORMANAGEMENT_RENDERING_INTENT](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_colormanagement_rendering_intent).

The default value is D2D1_COLORMANAGEMENT_RENDERING_INTENT_PERCEPTUAL.

### `D2D1_COLORMANAGEMENT_PROP_ALPHA_MODE:4`

How to interpret alpha data that is contained in the input image.

The type is [D2D1_COLORMANAGEMENT_ALPHA_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_colormanagement_alpha_mode).

The default value is D2D1_COLORMANAGEMENT_ALPHA_MODE_PREMULTIPLIED.

### `D2D1_COLORMANAGEMENT_PROP_QUALITY:5`

The quality level of the transform.

The type is [D2D1_COLORMANAGEMENT_QUALITY](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_colormanagement_quality).

The default value is D2D1_COLORMANAGEMENT_QUALITY_NORMAL.

### `D2D1_COLORMANAGEMENT_PROP_FORCE_DWORD:0xffffffff`