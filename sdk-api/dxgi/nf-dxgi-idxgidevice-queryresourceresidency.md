# IDXGIDevice::QueryResourceResidency

## Description

Gets the residency status of an array of resources.

## Parameters

### `ppResources` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

An array of [IDXGIResource](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiresource) interfaces.

### `pResidencyStatus` [out]

Type: **[DXGI_RESIDENCY](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_residency)***

An array of [DXGI_RESIDENCY](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_residency) flags. Each element describes the residency status for corresponding element in
the *ppResources* argument array.

### `NumResources`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of resources in the *ppResources* argument array and *pResidencyStatus* argument array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns [DXGI_ERROR_DEVICE_REMOVED](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error), E_INVALIDARG, or
E_POINTER (see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values) and WinError.h for more information).

## Remarks

The information returned by the *pResidencyStatus* argument array describes the residency status at the time that the **QueryResourceResidency** method was called.

**Note** The residency status will constantly change.

If you call the **QueryResourceResidency** method during a device removed state, the *pResidencyStatus* argument will return the [DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_residency) flag.

**Note** This method should not be called every frame as it incurs a non-trivial amount of overhead.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice)