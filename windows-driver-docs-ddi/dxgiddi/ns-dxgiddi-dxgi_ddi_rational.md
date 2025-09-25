# DXGI_DDI_RATIONAL structure

## Description

The DXGI_DDI_RATIONAL structure describes a fractional value that represents vertical and horizontal frequencies of a display mode (that is, vertical sync and horizontal sync).

## Members

### `Numerator` [in]

The numerator of the frequency fraction.

### `Denominator` [in]

The denominator of the frequency fraction.

## Remarks

Vertical frequencies are stored in Hertz (Hz); horizontal frequencies are stored in kilohertz (kHz). The dynamic range of this encoding format, given 10^-7 resolution, is {0..(2^32 - 1) / 10^7}. This range translates to {0..428.4967296} [Hz] for vertical frequencies and {0..428.4967296} [kHz] for horizontal frequencies. This submicrosecond precision range is acceptable even for a provided application. (An error of one microsecond for video signal synchronization would imply a time drift with a cycle of 10^7/(60 x 60 x 24) = 115.741 days.)

For a rational number with a finite fractional sequence, use a denominator of the form 10^(length of fractional sequence). For a rational number without a finite fractional sequence, a sequence that exceeds the precision that the dynamic range of the denominator allows, or an irrational number, use an appropriate ratio of integers that best represents the value.

## See also

[DXGI_DDI_MODE_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_mode_desc)