# ID2D1Transform::MapInputRectsToOutputRect

## Description

Performs the inverse mapping to [MapOutputRectToInputRects](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1transform-mapoutputrecttoinputrects).

## Parameters

### `inputRects` [in]

Type: **const [D2D1_RECT_L](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh847950(v=vs.85))***

An array of input rectangles to be mapped to the output rectangle. The *inputRects* parameter is always equal to the input bounds.

### `inputOpaqueSubRects` [in]

Type: **const [D2D1_RECT_L](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh847950(v=vs.85))***

An array of input rectangles to be mapped to the opaque output rectangle.

### `inputRectCount`

Type: **UINT32**

The number of inputs specified. The implementation guarantees that this is equal to the number of inputs specified on the transform.

### `outputRect`

Type: **[D2D1_RECT_L](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh847950(v=vs.85))***

The output rectangle that maps to the corresponding input rectangle.

### `outputOpaqueSubRect`

Type: **[D2D1_RECT_L](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh847950(v=vs.85))***

The output rectangle that maps to the corresponding opaque input rectangle.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

The transform implementation must ensure that any pixel shader or software callback implementation it provides honors this calculation.

Unlike the [MapOutputRectToInputRects](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1transform-mapoutputrecttoinputrects) and [MapInvalidRect](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1transform-mapinvalidrect) functions, this method is explicitly called by the renderer at a determined place in its rendering algorithm. The transform implementation may change its state based on the input rectangles and use this information to control its rendering information. This method is always called before the **MapInvalidRect** and **MapOutputRectToInputRects** methods of the transform.

## See also

[ID2D1EffectImpl](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectimpl)

[ID2D1Transform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transform)