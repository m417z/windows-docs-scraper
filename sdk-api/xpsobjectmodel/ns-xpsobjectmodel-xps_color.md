# XPS_COLOR structure

## Description

The contents of the [XPS_COLOR](https://learn.microsoft.com/previous-versions/windows/desktop/dd372939(v=vs.85)) structure when the *colorType* is **XPS_COLOR_TYPE_CONTEXT**.

## Members

### `colorType`

### `value`

### `value.sRGB`

### `value.sRGB.alpha`

### `value.sRGB.red`

### `value.sRGB.green`

### `value.sRGB.blue`

### `value.scRGB`

### `value.scRGB.alpha`

### `value.scRGB.red`

### `value.scRGB.green`

### `value.scRGB.blue`

### `value.context`

### `value.context.channelCount`

### `value.context.channels`

### `__MIDL___MIDL_itf_xpsobjectmodel_0000_0000_0028`

#### - channelCount

The number of color channels, including the alpha channel.

#### - channels

An array of floating-point color values for up to nine color channels, including the alpha channel.

The first element in the array, *channels*[0], contains the value for the alpha channel. The remaining elements in the array have context-specific color channel values.

## Remarks

For information about how to interpret or apply the values in this structure's members, see the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification).

## See also

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)