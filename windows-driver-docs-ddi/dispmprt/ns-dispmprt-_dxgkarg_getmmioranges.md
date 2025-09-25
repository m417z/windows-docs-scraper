# _DXGKARG_GETMMIORANGES structure

## Description

Arguments used to get the memory mapped input output (MMIO) range.

## Members

### `VirtualFunctionIndex`

The particular Virtual function to query.

### `BarIndex`

The particular bar to query.

### `NumRanges`

The number of ranges in *pMmioRanges*.

### `pMmioRanges`

Pointer to an array of [DXGK_MMIORANGEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_mmiorangeinfo) structures.

## Remarks

## See also

[DXGKDDI_GETMMIORANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getmmioranges) callback function