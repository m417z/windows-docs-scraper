# MFCreateVideoSampleFromSurface callback function

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Creates a media sample that manages a Direct3D surface.

## Parameters

### `pUnkSurface` [in]

A pointer to the **IUnknown** interface of the Direct3D surface. This parameter can be **NULL**.

### `ppSample` [out]

Receives a pointer to the sample's [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface.
The caller must release the interface.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The media sample created by this function exposes the following interfaces in addition to [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample):

* [IMFDesiredSample](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfdesiredsample)
* [IMFTrackedSample](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftrackedsample)

If *pUnkSurface* is non-**NULL**, the sample contains a single media buffer, which holds a pointer to the Direct3D surface. To get the Direct3D surface from the media buffer, call [IMFGetService::GetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfgetservice-getservice) on the buffer, using the service identifier MR_BUFFER_SERVICE. The media buffer does not implement [IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer), nor does it implement the [IMFMediaBuffer::Lock](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-lock) and [Unlock](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediabuffer-unlock) methods.

Alternatively, you can set *pUnkSurface* to **NULL**, and later add a DirectX surface buffer to the sample by calling [IMFSample::AddBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfsample-addbuffer). To create a DirectX surface buffer, call [MFCreateDXSurfaceBuffer](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatedxsurfacebuffer).

#### Examples

The following example is taken from the [EVRPresenter Sample](https://learn.microsoft.com/windows/desktop/medfound/evrpresenter-sample).

```cpp
//-----------------------------------------------------------------------------
// CreateD3DSample
//
// Creates a sample object (IMFSample) to hold a Direct3D swap chain.
//-----------------------------------------------------------------------------

HRESULT D3DPresentEngine::CreateD3DSample(
    IDirect3DSwapChain9 *pSwapChain,
    IMFSample **ppVideoSample
    )
{
    // Caller holds the object lock.

    D3DCOLOR clrBlack = D3DCOLOR_ARGB(0xFF, 0x00, 0x00, 0x00);

    IDirect3DSurface9* pSurface = NULL;
    IMFSample* pSample = NULL;

    // Get the back buffer surface.
    HRESULT hr = pSwapChain->GetBackBuffer(
        0, D3DBACKBUFFER_TYPE_MONO, &pSurface);
    if (FAILED(hr))
    {
        goto done;
    }

    // Fill it with black.
    hr = m_pDevice->ColorFill(pSurface, NULL, clrBlack);
    if (FAILED(hr))
    {
        goto done;
    }

    // Create the sample.
    hr = MFCreateVideoSampleFromSurface(pSurface, &pSample);
    if (FAILED(hr))
    {
        goto done;
    }

    // Return the pointer to the caller.
    *ppVideoSample = pSample;
    (*ppVideoSample)->AddRef();

done:
    SafeRelease(&pSurface);
    SafeRelease(&pSample);
    return hr;
}

```

## See also

[DirectX Surface Buffer](https://learn.microsoft.com/windows/desktop/medfound/directx-surface-buffer)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Samples](https://learn.microsoft.com/windows/desktop/medfound/media-samples)