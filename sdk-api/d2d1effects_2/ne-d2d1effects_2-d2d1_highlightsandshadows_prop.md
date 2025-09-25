# D2D1_HIGHLIGHTSANDSHADOWS_PROP enumeration

## Description

Identifiers for properties of the [Highlights and Shadows effect](https://learn.microsoft.com/windows/desktop/Direct2D/highlights-and-shadows-effect).

## Constants

### `D2D1_HIGHLIGHTSANDSHADOWS_PROP_HIGHLIGHTS:0`

The D2D1_HIGHLIGHTSANDSHADOWS_PROP_HIGHLIGHTS property is a float value indicating how much to increase or decrease highlights. The allowed range is -1.0 to 1.0. The default value is 0.0.

### `D2D1_HIGHLIGHTSANDSHADOWS_PROP_SHADOWS:1`

The D2D1_HIGHLIGHTSANDSHADOWS_PROP_SHADOWS property is a float value indicating how much to increase or decrease shadows. The allowed range is -1.0 to 1.0. The default value is 0.0.

### `D2D1_HIGHLIGHTSANDSHADOWS_PROP_CLARITY:2`

The D2D1_HIGHLIGHTSANDSHADOWS_PROP_CLARITY property is a float value indicating how much to increase or decrease clarity. The allowed range is -1.0 to 1.0. The default value is 0.0.

### `D2D1_HIGHLIGHTSANDSHADOWS_PROP_INPUT_GAMMA:3`

The D2D1_HIGHLIGHTSANDSHADOWS_PROP_INPUT_GAMMA property is a [D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA](https://learn.microsoft.com/windows/desktop/api/d2d1effects_2/ne-d2d1effects_2-d2d1_highlightsandshadows_input_gamma) enumeration value
indicating the gamma of the input image. The Highlights and Shadows effect works in linear gamma space, so if the input image is know to be linear, the D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA_LINEAR value should be used to prevent sRGB to linear conversions from being performed.

### `D2D1_HIGHLIGHTSANDSHADOWS_PROP_MASK_BLUR_RADIUS:4`

The D2D1_HIGHLIGHTSANDSHADOWS_PROP_MASK_BLUR_RADIUS property is a float value controlling the size of the region used around a pixel to classify the pixel as highlight or shadow. Lower values result in more localized adjustments.
The allowed range is 0.0 to 10.0. The default value is 1.25.

### `D2D1_HIGHLIGHTSANDSHADOWS_PROP_FORCE_DWORD:0xffffffff`