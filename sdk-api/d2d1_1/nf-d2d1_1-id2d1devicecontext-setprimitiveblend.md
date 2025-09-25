# ID2D1DeviceContext::SetPrimitiveBlend

## Description

Changes the primitive blend mode that is used for all rendering operations in the device context.

## Parameters

### `primitiveBlend`

Type: **[D2D1_PRIMITIVE_BLEND](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_primitive_blend)**

The primitive blend to use.

## Remarks

The primitive blend will apply to all of the primitive drawn on the context, unless this is overridden with the *compositeMode* parameter on the [DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawimage(id2d1effect_constd2d1_point_2f_constd2d1_rect_f_d2d1_interpolation_mode_d2d1_composite_mode)) API.

The primitive blend applies to the interior of any primitives drawn on the context. In the case of [DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawimage(id2d1effect_constd2d1_point_2f_constd2d1_rect_f_d2d1_interpolation_mode_d2d1_composite_mode)), this will be implied by the image rectangle, offset and world transform.

If the primitive blend is anything other than **D2D1_PRIMITIVE_BLEND_SOURCE_OVER** then ClearType rendering will be turned off. If the application explicitly forces ClearType rendering in these modes, the drawing context will be placed in an error state. D2DERR_WRONG_STATE will be returned from either [EndDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) or [Flush](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-flush).

## See also

[D2D1_PRIMITIVE_BLEND](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_primitive_blend)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)