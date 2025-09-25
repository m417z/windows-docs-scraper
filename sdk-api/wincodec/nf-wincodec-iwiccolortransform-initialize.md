# IWICColorTransform::Initialize

## Description

Initializes an [IWICColorTransform](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolortransform) with a [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) and transforms it from one [IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext) to another.

## Parameters

### `pIBitmapSource` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The bitmap source used to initialize the color transform.

### `pIContextSource` [in]

Type: **[IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext)***

The color context source.

### `pIContextDest` [in]

Type: **[IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext)***

The color context destination.

### `pixelFmtDest` [in]

Type: **REFWICPixelFormatGUID**

The GUID of the desired pixel format.

This parameter is limited to a subset of the native WIC pixel formats, see Remarks for a list.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The currently supported formats for the *pIContextSource* and *pixelFmtDest* parameters are:

* GUID_WICPixelFormat8bppGray
* GUID_WICPixelFormat16bppGray
* GUID_WICPixelFormat16bppBGR555
* GUID_WICPixelFormat16bppBGR565
* GUID_WICPixelFormat24bppBGR
* GUID_WICPixelFormat24bppRGB
* GUID_WICPixelFormat32bppBGR
* GUID_WICPixelFormat32bppBGRA
* GUID_WICPixelFormat32bppPBGRA
* GUID_WICPixelFormat32bppPRGBA (Windows 8 and later)
* GUID_WICPixelFormat32bppRGBA
* GUID_WICPixelFormat32bppBGR101010
* GUID_WICPixelFormat32bppCMYK
* GUID_WICPixelFormat48bppBGR
* GUID_WICPixelFormat64bppBGRA (Windows 8 and later)
* GUID_WICPixelFormat64bppPBGRA (Windows 8 and later)
* GUID_WICPixelFormat64bppPRGBA (Windows 8 and later)
* GUID_WICPixelFormat64bppRGBA (Windows 8 and later)

In order to get correct behavior from a color transform, the input and output pixel formats must be compatible with the source and destination color profiles. For example, an sRGB destination color profile will produce incorrect results when used with a CMYK destination pixel format.

#### Examples

The following example performs a color transform from one [IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext) to another.

```cpp

    IWICImagingFactory *pFactory = NULL;
    IWICBitmapDecoder *pDecoder = NULL;
    IWICBitmapFrameDecode *pBitmapFrame = NULL;
    IWICColorContext *pContextSrc = NULL;
    IWICColorContext *pContextDst = NULL;
    IWICColorTransform *pColorTransform = NULL;

    UINT uiFrameCount = 0;

    HRESULT hr = CoCreateInstance(
                    CLSID_WICImagingFactory,
                    NULL, CLSCTX_INPROC_SERVER,
                    IID_IWICImagingFactory,
                    (LPVOID*) &pFactory);

    if (SUCCEEDED(hr))
    {
        hr = pFactory->CreateDecoderFromFilename(
                           L"test.jpg",
                           NULL,
                           GENERIC_READ,
                           WICDecodeMetadataCacheOnDemand,
                           &pDecoder);
    }

    if (SUCCEEDED(hr))
    {
        hr = pDecoder->GetFrameCount(&uiFrameCount);
    }

    if (SUCCEEDED(hr) && (uiFrameCount > 0))
    {
        hr = pDecoder->GetFrame(0, &piBitmapFrame);
    }

    if (SUCCEEDED(hr))
    {
        hr = pFactory->CreateColorContext(&pContextSrc);
    }

    if (SUCCEEDED(hr))
    {
        hr = pContextSrc->InitializeFromFilename(
                              L"c:\\windows\\system32\\spool\\drivers\\color\\kodak_dc.icm");
    }

    if (SUCCEEDED(hr))
    {
        hr = pFactory->CreateColorContext(&pContextDst);
    }

    if (SUCCEEDED(hr))
    {
        hr = pContextDst->InitializeFromFilename(
                              L"c:\\windows\\system32\\spool\\drivers\\color\\sRGB Color Space Profile.icm");
    }

    hr = E_FAIL;

    if (SUCCEEDED(hr))
    {
        // Transform from src icm to the destination icm.
        hr = pColorTransform->Initialize( pBitmapFrame,
                                          pContextSrc,
                                          pContextDst,
                                          GUID_WICPixelFormat32bppBGRA);
    }

    if (SUCCEEDED(hr))
    {
        UINT uiWidth = 0, uiHeight = 0;
        UINT cbStride = 0;
        UINT cbBufferSize = 0;
        BYTE *pbBuffer = NULL;

        hr = pColorTransform->GetSize(&uiWidth, &uiHeight);

        if (SUCCEEDED(hr))
        {
            WICRect rc = { 0 };
            rc.X = 0;
            rc.Y = 0;
            rc.Width = uiWidth;
            rc.Height = 1; // scanline

            for (UINT i = 0; SUCCEEDED(hr) && (i < uiHeight); i++)
            {
                hr = pColorTransform->CopyPixels(&rc, cbStride, cbBufferSize - (rc.Y * cbStride), pbBuffer);
                pbBuffer += cbStride;
                rc.Y += 1;
            }
        }
    }

    if (pFactory)
    {
        pFactory->Release();
    }

    if (pDecoder)
    {
        pDecoder->Release();
    }

    if (pBitmapFrame)
    {
        pBitmapFrame->Release();
    }

    if (pContextSrc)
    {
        pContextSrc->Release();
    }

    if (pContextDst)
    {
        pContextDst->Release();
    }

    if (pColorTransform)
    {
        pColorTransform->Release();
    }

    return hr;

```