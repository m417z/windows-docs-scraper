# _D3DKMT_QUERYCLOCKCALIBRATION structure

## Description

Arguments used to query clock calibration information.

## Members

### `hAdapter` [in]

The adapter to query clock information for.

### `NodeOrdinal` [in]

Node ordinal of the requested engine.

### `PhysicalAdapterIndex` [in]

The physical adapter index, in an LDA chain.

### `ClockData` [out]

Output frequency, GPU clock, and CPU clock on the specified engine.

## Remarks

## See also