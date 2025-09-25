# D2D1_HISTOGRAM_PROP enumeration

## Description

Identifiers for properties of the [Histogram effect](https://learn.microsoft.com/windows/desktop/Direct2D/histogram).

## Constants

### `D2D1_HISTOGRAM_PROP_NUM_BINS:0`

Specifies the number of bins used for the histogram. The range of intensity values that fall into a particular bucket depend on the number of specified buckets.

The type is UINT32.

The default is 256.

### `D2D1_HISTOGRAM_PROP_CHANNEL_SELECT:1`

Specifies the channel used to generate the histogram. This effect has a single data output corresponding to the specified channel.

The type is [D2D1_CHANNEL_SELECTOR](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_channel_selector).

The default is D2D1_CHANNEL_SELECTOR_R.

### `D2D1_HISTOGRAM_PROP_HISTOGRAM_OUTPUT:2`

The output array.

The type is FLOAT[].

### `D2D1_HISTOGRAM_PROP_FORCE_DWORD:0xffffffff`