# D3D12DDI_VIDEO_PROCESS_LUMA_KEY_0020 structure

## Description

Specifies values for luma keying.

## Members

### `Enable`

Whether luma keying is enabled.

### `Lower`

The lower bound for the luma key. The valid range is [0 ... 1]. If the **Enable** member is false, this value is ignored.

### `Upper`

The upper bound for the luma key. The valid range is [0 ... 1]. If the **Enable** member is false, this value is ignored.

## Remarks

The values of **Lower** and **Upper** are the lower and upper bounds of the luma key. For a format that has *n* bits per channel, these values are converted to luma values as follows:

```cpp
value = f * ((1 << n) - 1)
```

Any pixel whose luma value falls within the upper and lower bounds, inclusive, is treated as transparent. For example, if the pixel format uses 8-bit luma, the upper bound is calculated as follows:

```cpp
BYTE Y = BYTE(max (min (1.0, Upper), 0.0) * 255.0)
```

Note that the value is clamped to the range [0 ... 1] before multiplying by 255.