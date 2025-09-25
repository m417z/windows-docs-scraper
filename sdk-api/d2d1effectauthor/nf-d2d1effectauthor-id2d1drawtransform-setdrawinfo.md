# ID2D1DrawTransform::SetDrawInfo

## Description

 Provides the GPU render info interface to the transform implementation.

## Parameters

### `drawInfo` [in]

Type: **[ID2D1DrawInfo](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1drawinfo)***

The interface supplied back to the calling method to allow it to specify the GPU based transform pass.

## Return value

Type: **HRESULT**

Any HRESULT value can be returned when implementing this method. A failure will be returned from the corresponding [ID2D1DeviceContext::EndDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) call.

## Remarks

The transform can maintain a reference to this interface for its lifetime. If any properties change on the transform, it can apply these changes to the corresponding *drawInfo* interface.

This is also used to determine that the corresponding nodes in the graph are dirty.

## See also

[ID2D1DrawTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1drawtransform)