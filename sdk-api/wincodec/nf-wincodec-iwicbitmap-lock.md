# IWICBitmap::Lock

## Description

Provides access to a rectangular area of the bitmap.

## Parameters

### `prcLock` [in]

Type: **const [WICRect](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicrect)***

The rectangle to be accessed.

### `flags` [in]

Type: **DWORD**

The access mode you wish to obtain for the lock. This is a bitwise combination of [WICBitmapLockFlags](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmaplockflags) for read, write, or read and write access.

| Value | Meaning |
| --- | --- |
| **WICBitmapLockRead** | The read access lock. |
| **WICBitmapLockWrite** | The write access lock. |

### `ppILock` [out]

Type: **[IWICBitmapLock](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmaplock)****

A pointer that receives the locked memory location.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Locks are exclusive for writing but can be shared for reading. You cannot call [CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels) while the [IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap) is locked for writing. Doing so will return an error, since locks are exclusive.

#### Examples

In the following example, an [IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap) is created and the image data is cleared using an [IWICBitmapLock](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmaplock).

```cpp

    IWICImagingFactory *pFactory = NULL;
    IWICBitmap *pBitmap = NULL;

    UINT uiWidth = 640;
    UINT uiHeight = 480;
    WICPixelFormatGUID formatGUID = GUID_WICPixelFormat32bppBGRA;

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

            hr = pLock->GetStride(&cbStride);

            if (SUCCEEDED(hr))
            {
                hr = pLock->GetDataPointer(&cbBufferSize, &pv);
            }

            // Clear the image data
            ZeroMemory(pv, cbBufferSize);

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