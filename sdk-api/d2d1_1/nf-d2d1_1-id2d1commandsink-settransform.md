# ID2D1CommandSink::SetTransform

## Description

Sets a new transform.

## Parameters

### `transform` [in]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)***

The transform to be set.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

The transform will be applied to the corresponding device context.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1RenderTarget::SetTransform](https://learn.microsoft.com/windows/desktop/Direct2D/id2d1rendertarget-settransform)