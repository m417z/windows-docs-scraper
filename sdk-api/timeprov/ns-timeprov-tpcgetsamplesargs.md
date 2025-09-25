# TpcGetSamplesArgs structure

## Description

A structure that is used by the
[TimeProvCommand](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovcommand) function.

## Members

### `pbSampleBuf`

An array of
[TimeSample](https://learn.microsoft.com/windows/desktop/api/timeprov/ns-timeprov-timesample) structures.

### `cbSampleBuf`

The size of **pbSampleBuf**, in bytes.

### `dwSamplesReturned`

The number of samples returned.

### `dwSamplesAvailable`

The total number of samples available.

## See also

[TimeProvCommand](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovcommand)

[TimeSample](https://learn.microsoft.com/windows/desktop/api/timeprov/ns-timeprov-timesample)