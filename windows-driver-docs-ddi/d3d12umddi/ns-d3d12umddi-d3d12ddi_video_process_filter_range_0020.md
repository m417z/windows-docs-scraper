# D3D12DDI_VIDEO_PROCESS_FILTER_RANGE_0020 structure

## Description

Defines the range of supported values for an image filter.

## Members

### `Minimum`

The minimum value of the filter.

### `Maximum`

The maximum value of the filter.

### `Default`

The default value of the filter.

### `Multiplier`

A multiplier. Use this formula to translate the filter setting into the actual filter value: Actual Value = Set Value × Multiplier.

## Remarks

The multiplier enables the filter range to have a fractional step value.
For example, a hue filter might have an actual range of [–180.0 ... +180.0] with a step size of 0.25. The device would report the following range and multiplier:

* Minimum: –720
* Maximum: +720
* Multiplier: 0.25

In this case, a filter value of 2 would be interpreted by the device as 0.50, which is 2 × 0.25.

The device should use a multiplier that can be represented exactly as a base-2 fraction.