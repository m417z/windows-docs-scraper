# NORM_FORM enumeration

## Description

Specifies the supported normalization forms.

## Constants

### `NormalizationOther:0`

Not supported.

### `NormalizationC:0x1`

Unicode normalization form C, canonical composition. Transforms each decomposed grouping, consisting of a base character plus combining characters, to the canonical precomposed equivalent. For example, A + ¨ becomes Ä.

### `NormalizationD:0x2`

Unicode normalization form D, canonical decomposition. Transforms each precomposed character to its canonical decomposed equivalent. For example, Ä becomes A + ¨.

### `NormalizationKC:0x5`

Unicode normalization form KC, compatibility composition. Transforms each base plus combining characters to the canonical precomposed equivalent and all compatibility characters to their equivalents. For example, the ligature ﬁ becomes f + i; similarly, A + ¨ + ﬁ + n becomes Ä + f + i + n.

### `NormalizationKD:0x6`

Unicode normalization form KD, compatibility decomposition. Transforms each precomposed character to its canonical decomposed equivalent and all compatibility characters to their equivalents. For example, Ä + ﬁ + n becomes A + ¨ + f + i + n.

## Remarks

For more information about the normalization forms, see [Using Unicode Normalization to Represent Strings](https://learn.microsoft.com/windows/desktop/Intl/using-unicode-normalization-to-represent-strings).

## See also

[IsNormalizedString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isnormalizedstring)

[National Language Support Enumeration Types](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-enumeration-types)

[NormalizeString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-normalizestring)

[Using Unicode Normalization to Represent Strings](https://learn.microsoft.com/windows/desktop/Intl/using-unicode-normalization-to-represent-strings)