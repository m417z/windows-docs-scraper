# ID2D1SourceTransform::SetRenderInfo

## Description

Sets the render information for the transform.

## Parameters

### `renderInfo` [in]

Type: **[ID2D1RenderInfo](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1renderinfo)***

The interface supplied to the transform to allow specifying the CPU based transform pass.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

Provides a render information interface to the source transform to allow it to specify state to the rendering system.

## See also

[ID2D1EffectImpl](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectimpl)

[ID2D1SourceTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1sourcetransform)