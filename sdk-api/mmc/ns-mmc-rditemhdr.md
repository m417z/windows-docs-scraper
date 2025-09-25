# RDITEMHDR structure

## Description

The
**RDITEMHDR** structure is introduced in MMC 1.2.

The
**RDITEMHDR** structure is used by the
[RDCOMPARE](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-rdcompare) structure to specify the type and cookie value of a scope or result item.

## Members

### `dwFlags`

A value that specifies whether the item is a scope or result item. If the **RDCI_ScopeItem** (0x80000000) flag is set, the item is a scope item. Otherwise, the item is a result item.

### `cookie`

The unique identifier of the scope or result item object to be compared as part of the sorting operation.

### `lpReserved`

Reserved for future use.

## Remarks

If the snap-in implements the
[IResultDataCompareEx](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdatacompareex) interface, MMC allocates an
[RDCOMPARE](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-rdcompare) structure and two
**RDITEMHDR** structures and then calls the snap-ins
[IResultDataCompareEx::Compare](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdatacompareex-compare) method. After the method returns, MMC releases the three structures it allocated.

## See also

[IResultDataCompareEx::Compare](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdatacompareex-compare)

[RDCOMPARE](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-rdcompare)