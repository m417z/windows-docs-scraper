# VarCmp function

## Description

Compares two variants.

## Parameters

### `pvarLeft` [in]

The first variant.

### `pvarRight` [in]

The second variant.

### `lcid` [in]

The locale identifier.

### `dwFlags` [in]

The compare results option.

| Value | Meaning |
| --- | --- |
| **NORM_IGNORECASE**<br><br>0x00000001 | Ignore case. |
| **NORM_IGNORENONSPACE**<br><br>0x00000002 | Ignore nonspace characters. |
| **NORM_IGNORESYMBOLS**<br><br>0x00000004 | Ignore symbols. |
| **NORM_IGNOREWIDTH**<br><br>0x00000008 | Ignore string width. |
| **NORM_IGNOREKANATYPE**<br><br>0x00000040 | Ignore Kana type. |
| **NORM_IGNOREKASHIDA**<br><br>0x00040000 | Ignore Arabic kashida characters. |

## Return value

This function can return one of these values.

| Return code/value | Description |
| --- | --- |
| **VARCMP_LT**<br><br>0 | *pvarLeft* is less than *pvarRight*. |
| **VARCMP_EQ**<br><br>1 | The parameters are equal. |
| **VARCMP_GT**<br><br>2 | *pvarLeft* is greater than *pvarRight*. |
| **VARCMP_NULL**<br><br>3 | Either expression is NULL. |

## Remarks

The function only compares the value of the variant types. It compares strings, integers, and floating points, but not arrays or records.

NORM_IGNOREWIDTH causes **VarCmp** to ignore the difference between half-width and full-width characters, as the following example demonstrates:

"Ｃａｔ"== "cat"

The full-width form is a formatting distinction used in Chinese and Japanese scripts.

## See also

[Automation Programming Reference](https://learn.microsoft.com/previous-versions/windows/desktop/automat/automation-programming-reference)

[Conversion and Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/conversion-and-manipulation-functions)

[Variant Arithmetic Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/variant-arithmetic-functions)