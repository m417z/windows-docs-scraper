# MFOffset structure

## Description

Specifies an offset as a fixed-point real number.

## Members

### `fract`

The fractional part of the number.

### `value`

The integer part of the number.

## Remarks

The value of the number is **value** + (**fract** / 65536.0f).

#### Examples

```cpp
MFOffset MakeOffset(float v)
{
    MFOffset offset;
    offset.value = short(v);
    offset.fract = WORD(65536 * (v-offset.value));
    return offset;
}

```

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)