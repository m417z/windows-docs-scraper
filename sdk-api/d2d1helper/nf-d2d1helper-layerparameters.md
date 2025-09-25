# LayerParameters function

## Description

Creates a [D2D1_LAYER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_layer_parameters) structure.

## Parameters

### `contentBounds` [in, ref]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

The content bounds of the layer. Content outside these bounds is not guaranteed to render. The default value is [D2D1::InfiniteRect](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nf-d2d1helper-infiniterect).

### `geometricMask` [in, optional]

Type: **[ID2D1Geometry](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1geometry)***

A mask that specifies the area of the layer that is composited into the render target, or **NULL**. The default value is **NULL**.

### `maskAntialiasMode`

Type: **[D2D1_ANTIALIAS_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_antialias_mode)**

A value that specifies the antialiasing mode for the geometric mask. The default value is [D2D1_ANTIALIAS_MODE_PER_PRIMITIVE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_antialias_mode).

### `maskTransform`

Type: **[D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)**

A value that specifies the transform that is applied to the geometric mask when composing the layer. The default value is [D2D1::IdentityMatrix](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nf-d2d1helper-identitymatrix).

### `opacity`

Type: **FLOAT**

An opacity that is applied uniformly to all resources in the layer when compositing to the target. The default value is 1.0.

### `opacityBrush`

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

A brush that is used to alter the opacity of the layer. The brush
is mapped to the layer, and the alpha channel of each mapped brush pixel is multiplied by the corresponding layer pixel. The default value is **NULL**.

### `layerOptions`

Type: **[D2D1_LAYER_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_layer_options)**

A value that specifies whether the layer intends to render text with ClearType antialiasing. The default value is [D2D1_LAYER_OPTIONS_NONE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_layer_options).

## Return value

Type: **[D2D1_LAYER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_layer_parameters)**

A structure that contains the content bounds, mask information, opacity settings, and other options for a layer resource.

## See also

[D2D1_ANTIALIAS_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_antialias_mode)

[D2D1_LAYER_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_layer_options)

[D2D1_LAYER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_layer_parameters)

[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)

[Layers Overview](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-layers-overview)