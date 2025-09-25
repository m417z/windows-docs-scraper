# ID2D1Effect::SetInputEffect

## Description

Sets the given input effect by index.

This method gets the output of the given effect and then passes the output image to the [SetInput](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1effect-setinput) method.

## Parameters

### `index`

The index of the input to set.

### `inputEffect` [in, optional]

The input effect to set.

### `invalidate`

Whether to invalidate the graph at the location of the effect input

## See also

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)

[ID2D1Effect::GetOutput](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1effect-getoutput)

[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)