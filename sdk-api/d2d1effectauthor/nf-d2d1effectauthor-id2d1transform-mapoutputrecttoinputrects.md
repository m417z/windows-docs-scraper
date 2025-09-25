# ID2D1Transform::MapOutputRectToInputRects

## Description

Allows a transform to state how it would map a rectangle requested on its output to a set of sample rectangles on its input.

## Parameters

### `outputRect`

Type: **const [D2D1_RECT_L](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh847950(v=vs.85))***

The output rectangle from which the inputs must be mapped.

### `inputRects` [out]

Type: **[D2D1_RECT_L](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh847950(v=vs.85))***

The corresponding set of inputs. The inputs will directly correspond to the transform inputs.

### `inputRectsCount`

Type: **UINT32**

The number of inputs specified. [Direct2D](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-portal) guarantees that this is equal to the number of inputs specified on the transform.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

The transform implementation must ensure that any pixel shader or software callback implementation it provides honors this calculation.

The transform implementation must regard this method as purely functional. It can base the mapped input and output rectangles on its current state as specified by the encapsulating effect properties. However, it must not change its own state in response to this method being invoked. The [Direct2D](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-portal) renderer implementation reserves the right to call this method at any time and in any sequence.

## See also

[ID2D1EffectImpl](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectimpl)

[ID2D1Transform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transform)