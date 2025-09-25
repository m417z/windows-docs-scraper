# ID2D1DeviceContext::CreateImageBrush(ID2D1Image,const D2D1_IMAGE_BRUSH_PROPERTIES &,ID2D1ImageBrush)

## Description

Creates an image brush. The input image can be any type of image, including a bitmap, effect, or a command list.

## Parameters

### `image` [in]

Type: **[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)***

The image to be used as a source for the image brush.

### `imageBrushProperties` [in, ref]

Type: **const [D2D1_IMAGE_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_image_brush_properties)**

The properties specific to an image brush.

### `imageBrush` [out]

Type: **[ID2D1ImageBrush](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1imagebrush)****

When this method returns, contains the address of a pointer to the input rectangles.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |

## Remarks

The image brush can be used to fill an arbitrary geometry, an opacity mask or text.

This sample illustrates drawing a rectangle with an image brush.

```cpp
HRESULT
CreatePatternBrush(
     __in ID2D1DeviceContext *pDeviceContext,
     __deref_out ID2D1ImageBrush **ppImageBrush
     )
{
    HRESULT hr = S_OK;
    ID2D1Image *pOldTarget = NULL;
    pDeviceContext->GetTarget(&pOldTarget);

    ID2D1CommandList *pCommandList = NULL;
    hr = pDeviceContext->CreateCommandList(&pCommandList);

    if (SUCCEEDED(hr))
    {
        pDeviceContext->SetTarget(pCommandList);
        hr = RenderPatternToCommandList(pDeviceContext);
    }

    pDeviceContext->SetTarget(pOldTarget);

    ID2D1ImageBrush *pImageBrush = NULL;

    if (SUCCEEDED(hr))
    {
         hr = pDeviceContext->CreateImageBrush(
            pCommandList,
            D2D1::ImageBrushProperties(
                D2D1::RectF(198, 298, 370, 470),
                D2D1_EXTEND_MODE_WRAP,
                D2D1_EXTEND_MODE_WRAP,
                D2D1_INTERPOLATION_MODE_LINEAR
                ),
            &pImageBrush
            );
    }

    // Fill a rectangle with the image brush.
    if (SUCCEEDED(hr))
    {
        pDeviceContext->FillRectangle(
            D2D1::RectF(0, 0, 100, 100), pImageBrush);
    }

    SafeRelease(&pImageBrush);
    SafeRelease(&pCommandList);
    SafeRelease(&pOldTarget);
    return hr;
}
```

## See also

[D2D1_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_brush_properties)

[D2D1_IMAGE_BRUSH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_image_brush_properties)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1DeviceContext::CreateCommandList](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createcommandlist)

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1RenderTarget::DrawGeometry](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-drawgeometry)

[ID2D1RenderTarget::FillGeometry](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-fillgeometry)