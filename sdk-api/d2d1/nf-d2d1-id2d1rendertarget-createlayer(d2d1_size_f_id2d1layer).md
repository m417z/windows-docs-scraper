## Description

Creates a layer resource that can be used with this render target and its compatible render targets. The new layer has the specified initial size.

## Parameters

### `size`

Type: [in] **[D2D1_SIZE_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-size-f)**

If (0, 0) is specified, no backing store is created behind the layer resource. The layer resource is allocated to the minimum size when [PushLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushlayer(constd2d1_layer_parameters__id2d1layer)) is called.

### `layer`

Type: [out] **[ID2D1Layer](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1layer)****

When the method returns, contains a pointer to a pointer to the new layer. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

Regardless of whether a size is initially specified, the layer automatically resizes as needed.

## Examples

For an example on how to use [CreateLayer](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-createlayer(constd2d1_size_f_id2d1layer).md), see the [How to Clip a Region with a Layer](https://learn.microsoft.com/windows/win32/Direct2D/how-to-clip-with-layers) topic.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)

[Layers Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-layers-overview)