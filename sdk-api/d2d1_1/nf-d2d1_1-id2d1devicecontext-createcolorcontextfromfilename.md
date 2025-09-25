# ID2D1DeviceContext::CreateColorContextFromFilename

## Description

Creates a color context by loading it from the specified filename. The profile bytes are the contents of the file specified by *Filename*.

## Parameters

### `filename`

Type: **PCWSTR**

The path to the file containing the profile bytes to initialize the color context with.

### `colorContext` [out]

Type: **[ID2D1ColorContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1colorcontext)****

When this method returns, contains the address of a pointer to a new color context.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |

## Remarks

The new color context can be used in [D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_properties1) to initialize the color context of a created bitmap. The model field of the profile header is inspected to determine whether this profile is sRGB or scRGB and the color space is updated respectively. Otherwise the space is custom.

## See also

[D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_properties1)

[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)