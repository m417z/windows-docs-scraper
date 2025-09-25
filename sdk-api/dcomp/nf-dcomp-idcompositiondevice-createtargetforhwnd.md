# IDCompositionDevice::CreateTargetForHwnd

## Description

Creates a composition target object that is bound to the window that is represented by the specified window handle ([HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)).

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The window to which the composition target object should be bound. This parameter must not be NULL.

### `topmost` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

TRUE if the visual tree should be displayed on top of the children of the window specified by the *hwnd* parameter; otherwise, the visual tree is displayed behind the children.

### `target` [out]

Type: **[IDCompositionTarget](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontarget)****

The new composition target object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A Microsoft DirectComposition visual tree must be bound to a window before anything can be displayed on screen. The window can be a top-level window or a child window. In either case, the window can be a layered window, but in all cases the window must belong to the calling process. If the window belongs to a different process, this method returns [DCOMPOSITION_ERROR_ACCESS_DENIED](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes).

When DirectComposition content is composed to the window, the content is always composed on top of whatever is drawn directly to that window through the device context ([HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)) returned by the [GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc) function, or by calls to Microsoft DirectX [Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present) methods. However, because window clipping rules apply to DirectComposition content, if the window has child windows, those child windows may clip the visual tree. The *topmost* parameter determines whether child windows clip the visual tree.

 Conceptually, each window consists of four layers:

1. The contents drawn directly to the window handle (this is the bottommost layer).
2. An optional DirectComposition visual tree.
3. The contents of all child windows, if any.
4. Another optional DirectComposition visual tree (this is the topmost layer).

All four layers are clipped to the window's visible region.

At most, only two composition targets can be created for each window in the system, one topmost and one not topmost. If a composition target is already bound to the specified window at the specified layer, this method fails. When a composition target object is destroyed, the layer it composed is available for use by a new composition target object.

#### Examples

The following example creates and initializes a device object, and then binds the device object to a composition target window.

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

[Composition Target Window](https://learn.microsoft.com/windows/desktop/directcomp/basic-concepts)

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)

[IDCompositionTarget](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontarget)

[IDCompositionTarget::SetRoot](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiontarget-setroot)

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)