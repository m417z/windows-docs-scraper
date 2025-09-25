# ID2D1Effect::SetInput

## Description

Sets the given input image by index.

## Parameters

### `index`

Type: **UINT32**

The index of the image to set.

### `input` [in, optional]

Type: **[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)***

The input image to set.

### `invalidate`

Type: **BOOL**

Whether to invalidate the graph at the location of the effect input

## Remarks

If the input index is out of range, the input image is ignored.

## See also

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)

[ID2D1Effect::GetOutput](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1effect-getoutput)

[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)