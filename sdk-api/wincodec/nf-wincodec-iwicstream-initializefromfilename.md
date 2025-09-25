# IWICStream::InitializeFromFilename

## Description

Initializes a stream from a particular file.

## Parameters

### `wzFileName` [in]

Type: **LPCWSTR**

The file used to initialize the stream.

### `dwDesiredAccess` [in]

Type: **DWORD**

The desired file access mode.

| Value | Meaning |
| --- | --- |
| **GENERIC_READ** | Read access. |
| **GENERIC_WRITE** | Write access. |

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [IWICStream](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicstream) interface methods do not enable you to provide a file sharing option.
To create a shared file stream for an image, use the [SHCreateStreamOnFileEx](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcreatestreamonfileex) function.
This stream can then be used to create an [IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder) using the [CreateDecoderFromStream](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicimagingfactory-createdecoderfromstream) method.

#### Examples

This example demonstrates the use of the **InitializeFromFilename** to create an image decoder.

```cpp
    IWICImagingFactory *pFactory = NULL;
    IWICStream *pStream = NULL;
    IWICBitmapDecoder *pDecoder = NULL;

    HRESULT hr = CoCreateInstance(
                    CLSID_WICImagingFactory,
                    NULL,
                    CLSCTX_INPROC_SERVER,
                    IID_PPV_ARGS(&pFactory));

    // Create the stream.
    if (SUCCEEDED(hr))
    {
        hr = pFactory->CreateStream(&pStream);
    }

    // Initialize the stream from a specific file.
    if (SUCCEEDED(hr))
    {
        hr = pStream->InitializeFromFilename(L"test.jpg", GENERIC_READ);
    }

    // Create a JPEG decoder.
    // Since the stream is created from the JPEG file, an explicit JPEG decoder
    // can be created using the generic IWICImagingFactory::CreateDecoder method.
    // However, use IWICImagingFactory::CreateDecoderFromStream method to auto
    // detect the stream and instantiate the appropriate codec.
    if (SUCCEEDED(hr))
    {
        hr = pFactory->CreateDecoder(
                GUID_ContainerFormatJpeg,   // Explicitly create a JPEG decoder.
                NULL,                       // No preferred vendor.
                &pDecoder);                 // Pointer to the decoder.
    }

    // Initialize the decoder
    if (SUCCEEDED(hr))
    {
        hr = pDecoder->Initialize(
                pStream,                            // The stream to use.
                WICDecodeMetadataCacheOnDemand);    // Decode metadata when needed.
    }

    // Process image frame.
    if (SUCCEEDED(hr))
    {
        UINT cFrames = 0;

        hr = pDecoder->GetFrameCount(&cFrames);

        if (SUCCEEDED(hr) && (cFrames > 0))
        {
            UINT width = 0, height = 0;
            IWICBitmapFrameDecode *pBitmapFrame = NULL;

            hr = pDecoder->GetFrame(0, &pBitmapFrame);

            if (SUCCEEDED(hr))
            {
                // Do something with the frame here.
            }

            if (pBitmapFrame)
            {
                pBitmapFrame->Release();
            }
        }
    }

    if (pStream)
    {
        pStream->Release();
    }

    if (pFactory)
    {
        pFactory->Release();
    }

    if (pDecoder)
    {
        pDecoder->Release();
    }
```