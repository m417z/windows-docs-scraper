# ID2D1Transform::MapInvalidRect

## Description

Sets the input rectangles for this rendering pass into the transform.

## Parameters

### `inputIndex`

Type: **UINT32**

The index of the input rectangle.

### `invalidInputRect`

Type: **[D2D1_RECT_L](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh847950(v=vs.85))**

The invalid input rectangle.

### `invalidOutputRect` [out]

Type: **[D2D1_RECT_L](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh847950(v=vs.85))***

The output rectangle to which the input rectangle must be mapped.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

The transform implementation must regard **MapInvalidRect** as purely functional. The transform implementation can base the mapped input rectangle on the transform implementation's current state as specified by the encapsulating effect properties. But the transform implementation can't change its own state in response to a call to **MapInvalidRect**. Direct2D can call this method at any time and in any sequence following a call to the [MapInputRectsToOutputRect](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1transform-mapinputrectstooutputrect) method.

## See also

[ID2D1EffectImpl](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectimpl)

[ID2D1Transform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transform)