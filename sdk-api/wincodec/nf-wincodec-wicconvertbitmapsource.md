## Description

Obtains a [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) in the desired pixel format from a given **IWICBitmapSource**.

## Parameters

### `dstFormat` [in]

Type: **[REFWICPixelFormatGUID](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-native-pixel-formats)**

The pixel format to convert to.

### `pISrc` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)***

The source bitmap.

### `ppIDst` [out]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)****

A pointer to the **null**-initialized destination bitmap pointer.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the *pISrc* bitmap is already in the desired format, then *pISrc* is copied to the destination bitmap pointer and a reference is added. If it is not in the desired format however, **WICConvertBitmapSource** will instantiate a *dstFormat* format converter and initialize it with *pISrc*.

## Examples

The following example converts an [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) to a **GUID_WICPixelFormat128bppPRGBAFloat** pixel format.

```cpp
   IWICImagingFactory *pFactory = NULL;
   IWICBitmapDecoder *pDecoder = NULL;
   IWICBitmapFrameDecode *pBitmapFrameDecode = NULL;
   IWICBitmapSource *pConverter = NULL;

   UINT uiFrameCount = 0;
   UINT uiWidth = 0, uiHeight = 0;
   WICPixelFormatGUID pixelFormat;

   // Create the image factory.
   HRESULT hr = CoCreateInstance(CLSID_WICImagingFactory,
                    NULL,
                    CLSCTX_INPROC_SERVER,
                    IID_IWICImagingFactory,
                    (LPVOID*) &pFactory);

   // Create a decoder from the file.
   if (SUCCEEDED(hr))
   {
      hr = pFactory->CreateDecoderFromFilename(L"test.jpg",
                         NULL,
                         GENERIC_READ,
                         WICDecodeMetadataCacheOnDemand,
                         &pDecoder);
   }

   // Get the frame count.
   if (SUCCEEDED(hr))
   {
      hr = pDecoder->GetFrameCount(&uiFrameCount);
   }

   if (SUCCEEDED(hr) && (uiFrameCount > 0))
   {
      IWICBitmapSource *pSource = NULL;

      hr = pDecoder->GetFrame(0, &pBitmapFrameDecode);

      if (SUCCEEDED(hr))
      {
         pSource = pBitmapFrameDecode;
         pSource->AddRef();

         hr = pSource->GetSize(&uiWidth, &uiHeight);
      }

      if (SUCCEEDED(hr))
      {
         hr = pSource->GetPixelFormat(&pixelFormat);
      }

      if (SUCCEEDED(hr))
      {
         if (!IsEqualGUID(pixelFormat, GUID_WICPixelFormat128bppPRGBAFloat))
         {

            hr = WICConvertBitmapSource(GUID_WICPixelFormat128bppPRGBAFloat, pSource, &pConverter);

            if (SUCCEEDED(hr))
            {
               pSource->Release();     // the converter has a reference to the source
               pSource = NULL;         // so we don't need it anymore.
               pSource = pConverter;   // let's treat the 128bppPABGR converter as the source
            }
         }

         if (piConverter)
         {
            UINT cbStride = uiWidth * sizeof(float) * 4;
            UINT cbBufferSize = cbStride;

            float *pixels = new float[cbBufferSize / sizeof(float)];

            if (pixels)
            {
               WICRect rc;
               rc.X = 0;
               rc.Y = 0;
               rc.Width = uiWidth;
               rc.Height = 1;

               for (UINT i = 0; SUCCEEDED(hr) && i < uiHeight; i++)
               {
                  hr = pSource->CopyPixels(&rc,
                                    cbStride,
                                    cbBufferSize,
                                    reinterpret_cast<BYTE*>(pixels));

                  // Do something with the scanline here...

                  rc.Y++;
               }

               delete[] pixels;
            }
            else
            {
               hr = E_OUTOFMEMORY;
            }

            pConverter->Release();
         }
      }
   }

   if (pBitmapFrameDecode)
   {
      pBitmapFrameDecode->Release();
   }

   if (pDecoder)
   {
      pDecoder->Release();
   }

   if (pFactory)
   {
      pFactory->Release();
   }

   return hr;
```