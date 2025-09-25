# DWRITE_BASELINE enumeration

## Description

The **DWRITE_BASELINE** enumeration contains values that specify the baseline for text alignment.

## Constants

### `DWRITE_BASELINE_DEFAULT`

The Roman baseline for horizontal; the Central baseline for vertical.

### `DWRITE_BASELINE_ROMAN`

The baseline that is used by alphabetic scripts such as Latin, Greek, and Cyrillic.

### `DWRITE_BASELINE_CENTRAL`

Central baseline, which is generally used for vertical text.

### `DWRITE_BASELINE_MATH`

Mathematical baseline, which math characters are centered on.

### `DWRITE_BASELINE_HANGING`

Hanging baseline, which is used in scripts like Devanagari.

### `DWRITE_BASELINE_IDEOGRAPHIC_BOTTOM`

Ideographic bottom baseline for CJK, left in vertical.

### `DWRITE_BASELINE_IDEOGRAPHIC_TOP`

Ideographic top baseline for CJK, right in vertical.

### `DWRITE_BASELINE_MINIMUM`

The bottom-most extent in horizontal, left-most in vertical.

### `DWRITE_BASELINE_MAXIMUM`

The top-most extent in horizontal, right-most in vertical.

## See also

[IDWriteTextAnalyzer1::GetBaseline](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-getbaseline)