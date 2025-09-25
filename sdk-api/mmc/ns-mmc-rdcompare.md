# RDCOMPARE structure

## Description

The
**RDCOMPARE** structure is introduced in MMC 1.2.

The
**RDCOMPARE** structure is used by the
[IResultDataCompareEx::Compare](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdatacompareex-compare) method for specifying information used for sorting scope and result items in the result pane of a primary snap-in.

## Members

### `cbSize`

Size of this structure.

### `dwFlags`

Reserved. Always zero.

### `nColumn`

Column being sorted.

### `lUserParam`

A value that specifies user-provided information that is passed into
[IResultData::Sort](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-sort). MMC does not interpret this parameter.

### `prdch1`

A pointer to an
[RDITEMHDR](https://learn.microsoft.com/windows/win32/api/mmc/ns-mmc-rditemhdr) structure that specifies the first item's type (scope or result) and cookie.

### `prdch2`

A pointer to an
[RDITEMHDR](https://learn.microsoft.com/windows/win32/api/mmc/ns-mmc-rditemhdr) structure that specifies the second item's type (scope or result) and cookie.

## Remarks

If the snap-in implements the
[IResultDataCompareEx](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdatacompareex) interface, MMC MMC allocates the parameters to the
[IResultDataCompareEx::Compare](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdatacompareex-compare) snap-in's method and then calls the method. MMC releases the parameters after the method returns.

## See also

[IResultDataCompareEx::Compare](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdatacompareex-compare)

[RDITEMHDR](https://learn.microsoft.com/windows/win32/api/mmc/ns-mmc-rditemhdr)