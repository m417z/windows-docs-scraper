# ID2D1Device::SetMaximumTextureMemory

## Description

Sets the maximum amount of texture memory Direct2D accumulates before it purges the image caches and cached texture allocations.

## Parameters

### `maximumInBytes`

Type: **UINT64**

The new maximum texture memory in bytes.

## Remarks

**Note** Direct2D may exceed the maximum texture memory you set with this method for a single frame if necessary to render the frame.

## See also

[ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device)