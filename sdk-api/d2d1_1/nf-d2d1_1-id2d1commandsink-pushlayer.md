# ID2D1CommandSink::PushLayer

## Description

Pushes a layer onto the clip and layer stack.

## Parameters

### `layerParameters1` [in]

Type: **const [D2D1_LAYER_PARAMETERS1](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_layer_parameters)***

The parameters that define the layer.

### `layer` [in]

Type: **[ID2D1Layer](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1layer)***

The layer resource that receives subsequent drawing operations.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1RenderTarget::PushAxisAlignedClip](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-pushaxisalignedclip(constd2d1_rect_f_d2d1_antialias_mode))