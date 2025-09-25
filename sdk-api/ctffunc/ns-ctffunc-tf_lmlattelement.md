# TF_LMLATTELEMENT structure

## Description

The **TF_LMLATTELEMENT** structure contains information about a lattice element. A lattice element is used in speech recognition. This structure is used with the [IEnumTfLatticeElements::Next](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-ienumtflatticeelements-next) method.

## Members

### `dwFrameStart`

Contains the starting offset, in 100-nanosecond units, of the element relative to the start of the phrase.

### `dwFrameLen`

Contains the length, in 100-nanosecond units, of the element.

### `dwFlags`

Not currently used.

### `iCost`

Specifies the actual confidence for this element. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| SP_LOW_CONFIDENCE | The speech engine has low confidence in the element. |
| SP_NORMAL_CONFIDENCE | The speech engine has normal confidence in the element. |
| SP_HIGH_CONFIDENCE | The speech engine has high confidence in the element. |

### `bstrText`

Contains the display text for the element. If the spoken word is "two", the display text will be "2". The caller must free this string using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

## See also

[IEnumTfLatticeElements::Next](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-ienumtflatticeelements-next)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)