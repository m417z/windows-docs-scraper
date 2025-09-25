# ID2D1DeviceContext::PushLayer(const D2D1_LAYER_PARAMETERS1 &,ID2D1Layer)

## Description

Push a layer onto the clip and layer stack of the device context.

## Parameters

### `layerParameters` [in]

Type: **const [D2D1_LAYER_PARAMETERS1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_layer_parameters1)***

The parameters that defines the layer.

### `layer` [in, optional]

Type: **[ID2D1Layer](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1layer)***

The layer resource to push on the device context that receives subsequent drawing operations.

**Note** If a layer is not specified, Direct2D manages the layer resource automatically.

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)