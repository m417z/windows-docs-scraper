# KS_COMPRESSION structure

## Description

The KS_COMPRESSION structure defines the compression of frames on an output pin.

## Members

### `RatioNumerator`

Specifies the numerator of the compression/expansion ratio.

### `RatioDenominator`

Specifies the denominator of the compression/expansion ratio.

### `RatioConstantMargin`

Specifies a scalar constant to apply to the compression ratio. Set this to zero for no compression.

## Remarks

For compression, specify a fraction less than 1. For decompression, specify a fraction greater than 1. For example, a compressor might specify 1:3. A decompressor could specify 3:1.