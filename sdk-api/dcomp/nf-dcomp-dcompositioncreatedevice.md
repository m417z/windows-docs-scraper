# DCompositionCreateDevice function

## Description

Creates a new device object that can be used to create other Microsoft DirectComposition objects.

## Parameters

### `dxgiDevice` [in]

Type: **[IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice)***

The DXGI device to use to create DirectComposition surface objects.

### `iid` [in]

Type: **REFIID**

The identifier of the interface to retrieve.

### `dcompositionDevice` [out]

Type: **void****

Receives an interface pointer to the newly created device object. The pointer is of the type specified by the *iid* parameter. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A device object serves as the factory for all other DirectComposition objects. It also controls transactional composition through the [IDCompositionDevice::Commit](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-commit) method.

The DXGI device specified by *dxgiDevice* is used to create all DirectComposition surface objects. In particular, the [IDCompositionSurface::BeginDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-begindraw) method returns an interface pointer to a DXGI surface that belongs to the device specified by the *dxgiDevice* parameter.

When creating the DXGI device, developers must specify the [D3D11_CREATE_DEVICE BGRA_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag) or [D3D10_CREATE_DEVICE_BGRA_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_create_device_flag) flag for Direct2D interoperability with Microsoft Direct3D resources.

The *iid* parameter must be `__uuidof(IDCompositionDevice)`, and the *dcompositionDevice* parameter receives a pointer to an [IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice) interface.

#### Examples

The following example shows how to create a device object as part of initialing DirectComposition objects.

```cpp
#include <dcomp.h>
#include <d3d11.h>

HRESULT InitializeDirectCompositionDevice(HWND hwndTarget,
        ID3D11Device **ppD3D11Device, IDCompositionDevice **ppDevice,
        IDCompositionTarget **ppCompTarget)
{
    HRESULT hr = S_OK;
    D3D_FEATURE_LEVEL featureLevelSupported;
    IDXGIDevice *pDXGIDevice = nullptr;

    // Verify that the arguments are valid.
    if (hwndTarget == NULL || ppD3D11Device == nullptr || ppDevice == nullptr ||
                            ppCompTarget == nullptr)
    {
        return E_INVALIDARG;
    }

    // Create the D3D device object. Note that the
    // D3D11_CREATE_DEVICE_BGRA_SUPPORT flag is needed for rendering
    // on surfaces using Direct2D.
    hr = D3D11CreateDevice(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL,
        D3D11_CREATE_DEVICE_BGRA_SUPPORT, // needed for rendering on surfaces using Direct2D
        NULL,
        0,
        D3D11_SDK_VERSION,
        ppD3D11Device,
        &featureLevelSupported,
        NULL);

    if (SUCCEEDED(hr))
    {
        // Create the DXGI device used to create bitmap surfaces.
        hr = (*ppD3D11Device)->QueryInterface(&pDXGIDevice);
    }

    if (SUCCEEDED(hr))
    {
        // Create the DirectComposition device object.
        hr = DCompositionCreateDevice(pDXGIDevice, __uuidof(IDCompositionDevice),
                reinterpret_cast<void **>(ppDevice));
    }

    if (SUCCEEDED(hr))
    {
        // Bind the DirectComposition device to the target window.
        hr = (*ppDevice)->CreateTargetForHwnd(hwndTarget, TRUE, ppCompTarget);
    }

    return hr;
}

```

## See also

[Functions](https://learn.microsoft.com/windows/desktop/directcomp/functions)