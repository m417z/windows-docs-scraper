# DWRITE_PANOSE_WEIGHT enumeration

## Description

The **DWRITE_PANOSE_WEIGHT** enumeration contains values that specify the weight of characters.

## Constants

### `DWRITE_PANOSE_WEIGHT_ANY:0`

Any weight.

### `DWRITE_PANOSE_WEIGHT_NO_FIT:1`

No fit weight.

### `DWRITE_PANOSE_WEIGHT_VERY_LIGHT:2`

Very light weight.

### `DWRITE_PANOSE_WEIGHT_LIGHT:3`

Light weight.

### `DWRITE_PANOSE_WEIGHT_THIN:4`

Thin weight.

### `DWRITE_PANOSE_WEIGHT_BOOK:5`

Book weight.

### `DWRITE_PANOSE_WEIGHT_MEDIUM:6`

Medium weight.

### `DWRITE_PANOSE_WEIGHT_DEMI:7`

Demi weight.

### `DWRITE_PANOSE_WEIGHT_BOLD:8`

Bold weight.

### `DWRITE_PANOSE_WEIGHT_HEAVY:9`

Heavy weight.

### `DWRITE_PANOSE_WEIGHT_BLACK:10`

Black weight.

### `DWRITE_PANOSE_WEIGHT_EXTRA_BLACK:11`

Extra black weight.

### `DWRITE_PANOSE_WEIGHT_NORD`

Extra black weight.

## Remarks

The **DWRITE_PANOSE_WEIGHT** values roughly correspond to the [DWRITE_FONT_WEIGHT](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_weight) values by using (panose_weight - 2) * 100 = font_weight.

## See also

[DWRITE_PANOSE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_panose)