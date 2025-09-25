# IWICFormatConverter::Initialize

## Description

Initializes the format converter.

## Parameters

### `pISource` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The input bitmap to convert

### `dstFormat` [in]

Type: **REFWICPixelFormatGUID**

The destination pixel format GUID.

### `dither` [in]

Type: **[WICBitmapDitherType](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapdithertype)**

The [WICBitmapDitherType](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapdithertype) used for conversion.

### `pIPalette` [in]

Type: **[IWICPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpalette)***

The palette to use for conversion.

### `alphaThresholdPercent` [in]

Type: **double**

The alpha threshold to use for conversion.

### `paletteTranslate` [in]

Type: **[WICBitmapPaletteType](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmappalettetype)**

The palette translation type to use for conversion.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you do not have a predefined palette, you must first create one. Use [InitializeFromBitmap](https://learn.microsoft.com/windows/win32/api/wincodec/nf-wincodec-iwicpalette-initializefrombitmap) to create the palette object, then pass it in along with your other parameters.

*dither*, *pIPalette*, *alphaThresholdPercent*, and *paletteTranslate* are used to mitigate color loss when converting to a reduced bit-depth format. For conversions that do not need these settings, the following parameters values should be used: *dither* set to **WICBitmapDitherTypeNone**, *pIPalette* set to **NULL**, *alphaThresholdPercent* set to **0.0f**, and *paletteTranslate* set to **WICBitmapPaletteTypeCustom**.

The basic algorithm involved when using an ordered dither requires a fixed palette, found in the [WICBitmapPaletteType](https://learn.microsoft.com/windows/win32/api/wincodec/ne-wincodec-wicbitmappalettetype) enumeration, in a specific order.

Often, the actual palette provided for the output may have a different ordering or some slight variation in the actual colors. This is the case when using the Microsoft Windows palette which has slight differences among versions of Windows.To provide for this, a palette and a palette translation are given to the format converter. The *pIPalette* is the actual destination palette to be used and the *paletteTranslate* is a fixed palette. Once the conversion is complete, the colors are mapped from the fixed palette to the actual colors in *pIPalette* using a nearest color matching algorithm.

 If colors in *pIPalette* do not closely match those in *paletteTranslate*, the mapping may produce undesirable results.

**WICBitmapDitherTypeOrdered4x4** can be useful in format conversions from 8-bit formats to 5- or 6-bit formats as there is no way to accurately convert color data.

**WICBitmapDitherTypeErrorDiffusion** selects the error diffusion algorithm and may be used with any palette. If an arbitrary palette is provided, **WICBitmapPaletteCustom** should be passed in as the *paletteTranslate*. Error diffusion often provides superior results compared to the ordered dithering algorithms especially when combined with the optimized palette generation functionality on the [IWICPalette](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicpalette).

 When converting a bitmap which has an alpha channel, such as a Portable Network Graphics (PNG), to 8bpp, the alpha channel is normally ignored. Any pixels which were transparent in the original bitmap show up as black in the final output because both transparent and black have pixel values of zero in the respective formats.

Some 8bpp content can contains an alpha color; for instance, the Graphics Interchange Format (GIF) format allows for a single palette entry to be used as a transparent color.
For this type of content, *alphaThresholdPercent* specifies what percentage of transparency should map to the transparent color. Because the alpha value is directly proportional to the opacity (not transparency) of a pixel, the *alphaThresholdPercent* indicates what level of opacity is mapped to the fully transparent color.

For instance, 9.8% implies that any pixel with an alpha value of less than 25 will be mapped to the transparent color. A value of 100% maps all pixels which are not fully opaque to the transparent color. Note that the palette should provide a transparent color. If it does not, the 'transparent' color will be the one closest to zero - often black.

#### Examples

The following example converts an image frame to a 32bppPBGRA format with no dithering or alpha threshold. Direct2D requires bitmap sources to be in the a 32bppPBGRA format for rendering. For a full sample demonstrating the use of the [IWICFormatConverter](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicformatconverter), see the [WIC Image Viewer Using Direct2D Sample](https://learn.microsoft.com/windows/win32/wic/-wic-sample-d2d-viewer).

```cpp
HRESULT hr = S_OK;

IWICBitmapDecoder *pIDecoder = NULL;
IWICBitmapFrameDecode *pIDecoderFrame  = NULL;
IWICFormatConverter *pIFormatConverter = NULL;

// Create the decoder.
hr = m_pIWICFactory->CreateDecoderFromFilename(
   L"turtle.jpg",                  // Image to be decoded
   NULL,                           // Do not prefer a particular vendor
   GENERIC_READ,                   // Desired read access to the file
   WICDecodeMetadataCacheOnDemand, // Cache metadata when needed
   &pIDecoder                      // Pointer to the decoder
   );

// Retrieve the first bitmap frame.
if (SUCCEEDED(hr))
{
   hr = pIDecoder->GetFrame(0, &pIDecoderFrame);
}

// Create the flip/rotator.
if (SUCCEEDED(hr))
{
   hr = m_pIWICFactory->CreateFormatConverter(&pIFormatConverter);
}

// Initialize the format converter.
if (SUCCEEDED(hr))
{
   hr = pIFormatConverter->Initialize(
       pIDecoderFrame,                  // Input source to convert
       GUID_WICPixelFormat32bppPBGRA,   // Destination pixel format
       WICBitmapDitherTypeNone,         // Specified dither pattern
       NULL,                            // Specify a particular palette
       0.f,                             // Alpha threshold
       WICBitmapPaletteTypeCustom       // Palette translation type
       );
}
//Create render target and D2D bitmap from IWICBitmapSource
if (SUCCEEDED(hr))
{
   hr = CreateDeviceResources(hWnd);
}

if (SUCCEEDED(hr))
{
   // Need to release the previous D2DBitmap if there is one
   SafeRelease(&m_pD2DBitmap);
   hr = m_pRT->CreateBitmapFromWicBitmap(pIFormatConverter, NULL, &m_pD2DBitmap);
}

SafeRelease(&pIFormatConverter);
SafeRelease(&pIDecoderFrame);
SafeRelease(&pIDecoder);

```