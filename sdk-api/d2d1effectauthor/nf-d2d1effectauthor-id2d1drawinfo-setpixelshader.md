# ID2D1DrawInfo::SetPixelShader

## Description

Set the shader instructions for this transform.

## Parameters

### `shaderId` [in]

Type: **REFGUID**

The resource id for the shader.

### `pixelOptions`

Type: **[D2D1_PIXEL_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_pixel_options)**

Additional information provided to the renderer to indicate the operations the pixel shader does.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

 If this call fails, the corresponding [ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect) instance is placed into an error state and will fail to Draw, it will place the context into an error state which can be retrieved through the [ID2D1DeviceContext::EndDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) call.

Specifying *pixelOptions* other than D2D1_PIXEL_OPTIONS_NONE can enable the renderer to perform certain optimizations such as combining various parts of the effect graph together. If this information does not accurately describe the shader, indeterminate rendering artifacts can result.

## See also

[ID2D1DrawInfo](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1drawinfo)