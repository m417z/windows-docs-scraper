## Description

Defines constants that specify a four-character identifier for a font axis.

## Constants

### `DWRITE_FONT_AXIS_TAG_WEIGHT`

Specifies the weight axis, using the identifier 'w','g','h','t'.

### `DWRITE_FONT_AXIS_TAG_WIDTH`

Specifies the width axis, using the identifier 'w','d','t','h'.

### `DWRITE_FONT_AXIS_TAG_SLANT`

Specifies the slant axis, using the identifier 's','l','n','t'.

### `DWRITE_FONT_AXIS_TAG_OPTICAL_SIZE`

Specifies the optical size axis, using the identifier 'o','p','s','z'.

### `DWRITE_FONT_AXIS_TAG_ITALIC`

Specifies the italic axis, using the identifier 'i','t','a','l'.

## Remarks

You can use the **DWRITE_MAKE_FONT_AXIS_TAG(a,b,c,d)** macro to create your own custom identifiers. Here's an example.

```cpp
DWRITE_MAKE_FONT_AXIS_TAG('c', 's', 't', 'm');
```

## See also

[DWRITE_FONT_AXIS_RANGE structure](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_range)
[DWRITE_FONT_AXIS_VALUE structure](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_value)