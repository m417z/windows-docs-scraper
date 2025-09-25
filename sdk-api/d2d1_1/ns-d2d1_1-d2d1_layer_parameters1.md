# D2D1_LAYER_PARAMETERS1 structure

## Description

Contains the content bounds, mask information, opacity settings, and other options for a layer resource.

## Members

### `contentBounds`

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

The content bounds of the layer. Content outside these bounds is not guaranteed to render.

### `geometricMask`

Type: **[ID2D1Geometry](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1geometry)***

The geometric mask specifies the area of the layer that is composited into the render target.

### `maskAntialiasMode`

Type: **[D2D1_ANTIALIAS_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_antialias_mode)**

A value that specifies the antialiasing mode for the geometricMask.

### `maskTransform`

Type: **[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)**

A value that specifies the transform that is applied to the geometric mask when composing the layer.

### `opacity`

Type: **FLOAT**

An opacity value that is applied uniformly to all resources in the layer when compositing to the target.

### `opacityBrush`

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

A brush that is used to modify the opacity of the layer. The brush
is mapped to the layer, and the alpha channel of each mapped brush pixel is multiplied against the corresponding layer pixel.

### `layerOptions`

Type: **[D2D1_LAYER_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_layer_options1)**

Additional options for the layer creation.

## See also

[Layers Overview](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-layers-overview)