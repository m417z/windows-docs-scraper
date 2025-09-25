# IDXGIDevice4::OfferResources1

## Description

Allows the operating system to free the video memory of resources, including both discarding the content and de-committing the memory.

## Parameters

### `NumResources` [in]

Type: **UINT**

The number of resources in the *ppResources* argument array.

### `ppResources` [in]

Type: **IDXGIResource***

An array of pointers to [IDXGIResource](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiresource) interfaces for the resources to offer.

### `Priority` [in]

Type: **DXGI_OFFER_RESOURCE_PRIORITY**

A [DXGI_OFFER_RESOURCE_PRIORITY](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_offer_resource_priority)-typed value that indicates how valuable data is.

### `Flags` [in]

Type: **UINT**

Specifies the [DXGI_OFFER_RESOURCE_FLAGS](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/ne-dxgi1_5-dxgi_offer_resource_flags).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code, which can include E_INVALIDARG if a resource in the array, or the priority, is invalid.

## Remarks

**OfferResources1** (an extension of the original [IDXGIDevice2::OfferResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-offerresources) API) enables D3D based applications to allow de-committing of an allocation’s backing store to reduce system commit under low memory conditions.
A de-committed allocation cannot be reused, so opting in to the new DXGI_OFFER_RESOURCE_FLAG_ALLOW_DECOMMIT flag means the new reclaim results must be properly handled. Refer to the flag descriptions in [DXGI_RECLAIM_RESOURCE_RESULTS](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/ne-dxgi1_5-dxgi_reclaim_resource_results) and the Example below.

**OfferResources1** and [ReclaimResources1](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nf-dxgi1_5-idxgidevice4-reclaimresources1) may *not* be used interchangeably with [OfferResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-offerresources) and [ReclaimResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-reclaimresources).

The priority value that the *Priority* parameter specifies describes how valuable the caller considers the content to be. The operating system uses the priority value to discard resources in order of priority. The operating system discards a resource that is offered with low priority before it discards a resource that is offered with a higher priority.

If you call **OfferResources1** to offer a resource while the resource is bound to the pipeline, the resource is unbound. You cannot call **OfferResources1** on a resource that is mapped. After you offer a resource, the resource cannot be mapped or bound to the pipeline until you call the [ReclaimResources1](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nf-dxgi1_5-idxgidevice4-reclaimresources1) method to reclaim the resource. You cannot call **OfferResources1** to offer immutable resources.

To offer shared resources, call [OfferResources1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-offerresources) on only one of the sharing devices. To ensure exclusive access to the resources, you must use an [IDXGIKeyedMutex](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgikeyedmutex) object and then call **OfferResources1** only while you hold the mutex. In fact, you can't offer shared resources unless you use **IDXGIKeyedMutex** because offering shared resources without using **IDXGIKeyedMutex** isn't supported.

The user mode display driver might not immediately offer the resources that you specified in a call to **OfferResources1**. The driver can postpone offering them until the next call to [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present), [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1), or [ID3D11DeviceContext::Flush](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-flush).

#### Examples

A UWP based application is being suspended to the background and wishes to offer its graphics resources back to the system, in case another application wants them. The application will reclaim these resources when it gets resumed. The application also realizes that the total available system commit is small on this platform, and is willing to allow its resources to be removed from the system commit. If the reclaim process fails because the system is out of memory, the application handles the error condition.

``` syntax
struct Texture
{
    UINT32 Width;
    UINT32 Height;
    UINT32 Mips;
    ID3D11Texture2D* pResource;
};

void Application::OfferInterfaceResources(ID3D11Device* pD3D11Device)
{
    CComPtr<IDXGIDevice4> pDXGIDevice;
    ThrowIfFailed(pD3D11Device->QueryInterface(&pDXGIDevice));

    for(Texture& t : m_Textures)
    {
        CComPtr<IDXGIResource> pDXGIResource;
        ThrowIfFailed(t.pResource->QueryInterface(&pDXGIResource));
        ThrowIfFailed(pDXGIDevice->OfferResources1(1, &pDXGIResource, DXGI_OFFER_RESOURCE_PRIORITY_NORMAL,
											DXGI_OFFER_RESOURCE_FLAG_ALLOW_DECOMMIT));
    }
}

void Application::ReclaimInterfaceResources (ID3D11Device* pD3D11Device)
{
    CComPtr<IDXGIDevice4> pDXGIDevice;
    ThrowIfFailed(pD3D11Device->QueryInterface(&pDXGIDevice));

    for(Texture& t : m_Textures)
    {
        CComPtr<IDXGIResource> pDXGIResource;
        ThrowIfFailed(t.pResource->QueryInterface(&pDXGIResource));

        DXGI_RECLAIM_RESOURCE_RESULTS Result;
        ThrowIfFailed(pDXGIDevice->ReclaimResources1(1, &pDXGIResource, &Result));

        // If the surface lost its backing commitment, it must be recreated.

        if(Result == DXGI_RECLAIM_RESOURCE_RESULT_NOT_COMMITTED)
        {
            t.pResource->Release();
            t.pResource = CreateTexture(t.Width, t.Height, t.Mips);
        }

        // If the surface lost its content (either because it was discarded, or recreated
        // due to lost commitment), we must regenerate the content.

        if(Result != DXGI_RECLAIM_RESOURCE_RESULT_OK)
        {
            PopulateContent(t);
        }
    }
}

```

## See also

[DXGI_RECLAIM_RESOURCE_RESULTS](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/ne-dxgi1_5-dxgi_reclaim_resource_results)

[IDXGIDevice4](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nn-dxgi1_5-idxgidevice4)