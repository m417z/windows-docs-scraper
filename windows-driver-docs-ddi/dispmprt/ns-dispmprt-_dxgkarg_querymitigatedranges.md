# _DXGKARG_QUERYMITIGATEDRANGES structure

## Description

Arguments used to query mitigated ranges.

## Members

### `VirtualFunctionIndex`

Zero-based offset of the Virtual Function from the first VF exposed by this Physical Function.

### `BarIndex`

The specific base address register to retrieve mitigations.

### `NumRanges`

Number of ranges to query.

### `pMitigatedRange`

A pointer to the array of mitigated ranges info.

## Remarks

## See also