# ID2D1DeviceContext::CreateColorContext

## Description

Creates a color context.

## Parameters

### `space`

Type: **[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)**

The space of color context to create.

### `profile` [in, optional]

Type: **const BYTE***

A buffer containing the ICC profile bytes used to initialize the color context when *space* is [D2D1_COLOR_SPACE_CUSTOM](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space). For other types, the parameter is ignored and should be set to **NULL**.

### `profileSize`

Type: **UINT32**

The size in bytes of *Profile*.

### `colorContext` [out]

Type: **[ID2D1ColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1colorcontext)****

When this method returns, contains the address of a pointer to a new color context object.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |

## Remarks

The new color context can be used in [D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_properties1) to initialize the color context of a created bitmap.

When *space* is [D2D1_COLOR_SPACE_CUSTOM](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space), *profile* and *profileSize* must be specified. Otherwise, these parameters should be set to **NULL** and zero respectively. When the space is D2D1_COLOR_SPACE_CUSTOM, the model field of the profile header is inspected to determine if this profile is sRGB or scRGB and the color space is updated respectively. Otherwise the space remains custom.

## See also

[D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_properties1)

[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)

[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)