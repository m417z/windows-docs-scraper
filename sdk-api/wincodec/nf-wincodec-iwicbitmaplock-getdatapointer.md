# IWICBitmapLock::GetDataPointer

## Description

Gets the pointer to the top left pixel in the locked rectangle.

## Parameters

### `pcbBufferSize` [out]

Type: **UINT***

A pointer that receives the size of the buffer.

### `ppbData` [out]

Type: **BYTE****

A pointer that receives a pointer to the top left pixel in the locked rectangle.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The pointer provided by this method should not be used outside of the lifetime of the lock itself.

**GetDataPointer** is not available in multi-threaded apartment applications.

#### Examples

In the following example, the data pointed to by the [IWICBitmapLock](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmaplock) is zeroed.

```cpp

    IWICImagingFactory *pFactory = NULL;
    IWICBitmap *pBitmap = NULL;

    UINT uiWidth = 640;
    UINT uiHeight = 480;
    WICPixelFormatGUID formatGUID = GUID_WICPixelFormat32bppARGB;

    WICRect rcLock = { 0, 0, uiWidth, uiHeight };
    IWICBitmapLock *pLock = NULL;

    HRESULT hr = CoCreateInstance(
        CLSID_WICImagingFactory,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IWICImagingFactory,
        (LPVOID*)&pFactory
        );

    if (SUCCEEDED(hr))
    {
        hr = pFactory->CreateBitmap(uiWidth, uiHeight, formatGUID, WICBitmapCacheOnDemand, &pBitmap);
    }

    if (SUCCEEDED(hr))
    {
        hr = pBitmap->Lock(&rcLock, WICBitmapLockWrite, &pLock);

        if (SUCCEEDED(hr))
        {
            UINT cbBufferSize = 0;
            UINT cbStride = 0;
            BYTE *pv = NULL;

            // Retrieve the stride.
            hr = pLock->GetStride(&cbStride);

            if (SUCCEEDED(hr))
            {
                hr = pLock->GetDataPointer(&cbBufferSize, &pv);
            }
            if (SUCCEEDED(hr))
            {
                // Access the bitmap memory starting at pv, where
                // each row begins cbStride bytes after the start
                // of the preceding row.
            }

            // Release the bitmap lock.
            pLock->Release();
        }
    }

    if (pBitmap)
    {
        pBitmap->Release();
    }

    if (pFactory)
    {
        pFactory->Release();
    }

    return hr;

```