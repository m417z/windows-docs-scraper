## Description

Creates a wrapper object that represents the rasterization of a layered window, and that can be associated with a visual for composition.

## Parameters

### `hwnd`

Type: [in] **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle of the layered window for which to create a wrapper. A layered window is created by specifying **WS_EX_LAYERED** when creating the window with the [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function or by setting **WS_EX_LAYERED** via [SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga) after the window has been created.

### `surface`

Type: [out] **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

The new composition surface object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

You can use the *surface* pointer in calls to the [IDCompositionVisual::SetContent](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-setcontent) method to set the content of one or more visuals. After setting the content, the visuals compose the contents of the specified layered window as long as the window is layered. If the window is unlayered, the window content disappears from the output of the composition tree. If the window is later re-layered, the window content reappears as long as it is still associated with a visual.

If the window is resized, the affected visuals are re-composed.

The contents of the window are not cached beyond the life of the window. That is, if the window is destroyed, the affected visuals stop composing the window.

If the window is moved off-screen or resized to zero, the system stops composing the content of visuals. You should use the [DwmSetWindowAttribute](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetwindowattribute) function with the **DWMWA_CLOAK** flag to "cloak" the layered child window when you need to hide the original window while allowing the system to continue to compose the content of the visuals. For more information, see [How to animate the bitmap of a layered child window](https://learn.microsoft.com/windows/desktop/directcomp/how-to--animate-the-bitmap-of-a-layered-child-window) and [DirectComposition layered child window sample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/DirectCompositionLayeredChildWindow).

## Examples

The following code snippet creates a wrapper object that represents the rasterization of a layered window.

```cpp
HRESULT hr = S_OK;
IDCompositionVisual *pVisual = nullptr;
IUnknown *pSurface = nullptr;

// Create a visual. g_pDevice is the IDCompositionDevice pointer of a
// device object created earlier.
hr = g_pDevice->CreateVisual(&pVisual);

if (SUCCEEDED(hr))
{
    // Create a surface that contains the image of the layered child
    // window identified by the g_hwndChild window handle (HWND).
    hr = g_pDevice->CreateSurfaceFromHwnd(g_hwndChild, &pSurface);
}

if (SUCCEEDED(hr))
{
    // Set the content of the Control child visual.
    hr = pVisual->SetContent(pSurface);
}
```

## See also

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)

[IDCompositionDevice::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createsurface)

[IDCompositionDevice::CreateSurfaceFromHandle](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createsurfacefromhandle)