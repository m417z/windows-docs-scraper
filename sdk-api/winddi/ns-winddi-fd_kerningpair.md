# FD_KERNINGPAIR structure

## Description

The FD_KERNINGPAIR structure is used to store information about kerning pairs.

## Members

### `wcFirst`

Specifies the code point of the first character in the kerning pair.

### `wcSecond`

Specifies the code point of the second character in the kerning pair.

### `fwdKern`

Specifies the kerning value, in font (notional) units, for the kerning pair. If this value is greater than zero, the characters will be moved apart; otherwise, the characters will be moved together. For information about the FWORD data type, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

## Remarks

An array of FD_KERNINGPAIR structures must be null-terminated, which means the last FD_KERNINGPAIR structure in the array has all structure members set to zero. An array of FD_KERNINGPAIR structures must be sorted in increasing order according to an unsigned 32-bit key, calculated as follows:

```
    wcFirst + 65536 * wcSecond.
```

## See also

[DrvQueryFontTree](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfonttree)