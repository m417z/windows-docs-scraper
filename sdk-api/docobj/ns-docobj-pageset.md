# PAGESET structure

## Description

Identifies one or more page-ranges to be printed and, optionally, identifies only the even or odd pages as part of a pageset.

## Members

### `cbStruct`

The number of bytes in this instance of the **PAGESET** structure. This member must be a multiple of 4.

### `fOddPages`

If **TRUE**, only the odd-numbered pages in the page-set indicated by **rgPages** are to be printed.

### `fEvenPages`

If **TRUE**, only the even-numbered pages in the page-set indicated by **rgPages** are to be printed.

### `cPageRange`

The number of page-range pairs specified in **rgPages**.

### `rgPages`

Pointer to an array of [PAGERANGE](https://learn.microsoft.com/windows/desktop/api/docobj/ns-docobj-pagerange) structures specifying the pages to be printed. One or more page ranges can be specified, so long as the number of page ranges is the value of **cPageRange**. The page ranges must be sorted in ascending order and must be non-overlapping.

## See also

[PAGERANGE](https://learn.microsoft.com/windows/desktop/api/docobj/ns-docobj-pagerange)