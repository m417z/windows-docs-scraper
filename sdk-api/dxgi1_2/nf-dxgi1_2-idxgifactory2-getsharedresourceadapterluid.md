# IDXGIFactory2::GetSharedResourceAdapterLuid

## Description

Identifies the adapter on which a shared resource object was created.

## Parameters

### `hResource` [in]

A handle to a shared resource object. The [IDXGIResource1::CreateSharedHandle](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiresource1-createsharedhandle) method returns this handle.

### `pLuid` [out]

A pointer to a variable that receives a locally unique identifier ([LUID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549708(v=vs.85))) value that identifies the adapter. **LUID** is defined in Dxgi.h. An **LUID** is a 64-bit value that is guaranteed to be unique only on the operating system on which it was generated. The uniqueness of an **LUID** is guaranteed only until the operating system is restarted.

## Return value

**GetSharedResourceAdapterLuid** returns:

* S_OK if it identified the adapter.
* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if *hResource* is invalid.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **GetSharedResourceAdapterLuid** fails with E_NOTIMPL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

You cannot share resources across adapters. Therefore, you cannot open a shared resource on an adapter other than the adapter on which the resource was created. Call **GetSharedResourceAdapterLuid** before you open a shared resource to ensure that the resource was created on the appropriate adapter. To open a shared resource, call the [ID3D11Device1::OpenSharedResource1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-opensharedresource1) or [ID3D11Device1::OpenSharedResourceByName](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-opensharedresourcebyname) method.

#### Examples

``` syntax
HANDLE handle;
IDXGIFactory2* pFactory;

LUID luid;
pFactory->GetSharedResourceAdapterLuid (handle, &luid);

UINT index = 0;
IDXGIAdapter* pAdapter = NULL;
while (SUCCEEDED(pFactory->EnumAdapters(index, &pAdapter)))
{
    DXGI_ADAPTER_DESC desc;
    pAdapter->GetDesc(&desc);
    if (desc.AdapterLuid == luid)
    {
       // Identified a matching adapter.
       break;
    }
    pAdapter->Release();
    pAdapter = NULL;
    index++;
}
// At this point, if pAdapter is non-null, you identified an adapter that
// can open the shared resource.

```

## See also

[IDXGIFactory2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgifactory2)