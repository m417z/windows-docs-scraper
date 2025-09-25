# D3D12DDI_VIDEO_SCALE_SUPPORT_FLAGS_0022 enumeration

## Description

The **D3D12DDI_VIDEO_SCALE_SUPPORT_FLAGS_0022** enumeration contains the options for video scale support.

## Constants

### `D3D12DDI_VIDEO_SCALE_SUPPORT_FLAG_0022_NONE:0x0`

All possible output size width/height combinations that exist between the Max size and Min size for the extent, inclusive, are supported.

### `D3D12DDI_VIDEO_SCALE_SUPPORT_FLAG_0022_POW2_ONLY:0x1`

The scaler supports only output sizes at a pow2 scale factors within the range. The x and y scale factors must be the same for both dimensions when this flag is set.

The following is an example that iterates over the supported output sizes for one dimension when this flag is set:

```c
bool OutputSizeSupported(UINT Size, UINT Max, UINT Min)
{
    UINT CurrentSize = Max;
    while (CurrentSize >= Min)
    {
        if (CurrentSize == Size)
        {
            return true;
        }

        CurrentSize = (CurrentSize + 1) / 2;
    }

    return false;
}
```

### `D3D12DDI_VIDEO_SCALE_SUPPORT_FLAG_0022_EVEN_DIMENSIONS_ONLY:0x2`

The scaler supports only output sizes that have even output dimensions.

## See also

[**D3D12DDI_VIDEO_SCALE_SUPPORT_0032**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_scale_support_0032)