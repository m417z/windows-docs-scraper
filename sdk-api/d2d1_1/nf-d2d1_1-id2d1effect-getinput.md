# ID2D1Effect::GetInput

## Description

Gets the given input image by index.

## Parameters

### `index`

Type: **UINT32**

The index of the image to retrieve.

### `input` [out, optional]

Type: **[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)****

When this method returns, contains the address of a pointer to the image that is identified by *Index*.

## Remarks

If the input index is out of range, the returned image will be **NULL**.

## See also

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1DeviceContext::DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawimage(id2d1effect_constd2d1_point_2f_constd2d1_rect_f_d2d1_interpolation_mode_d2d1_composite_mode))

[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)

[ID2D1Effect::GetOutput](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1effect-getoutput)

[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)