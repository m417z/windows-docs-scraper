## Description

Enables the blur effect on a specified window.

## Parameters

### `hWnd` [in]

The handle to the window on which the blur-behind data is applied.

### `pBlurBehind` [in]

A pointer to a [DWM_BLURBEHIND](https://learn.microsoft.com/windows/win32/api/dwmapi/ns-dwmapi-dwm_blurbehind) structure that provides blur-behind data.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

> [!NOTE]
> Beginning with Windows 8, calling this function doesn't result in the blur effect, due to a style change in the way windows are rendered.

Enable blur by setting the **fEnable** member of the [DWM_BLURBEHIND](https://learn.microsoft.com/windows/win32/api/dwmapi/ns-dwmapi-dwm_blurbehind) structure to **TRUE**. This results in subsequent compositions of the window blurring the content behind it. This function should be called immediately before a [BeginPaint](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-beginpaint) call to ensure prompt application of the effect.

The alpha values in the window are honored, and the rendering atop the blur will use these alpha values. It's your application's responsibility to ensure that the alpha values of all pixels in the window are correct. Some Windows Graphics Device Interface (GDI) operations don't preserve alpha values, so you should take care when presenting child windows because the alpha values they contribute are unpredictable.

The region specified within the [DWM_BLURBEHIND](https://learn.microsoft.com/windows/win32/api/dwmapi/ns-dwmapi-dwm_blurbehind) structure is owned by you as the caller. It's the caller's responsibility to free the region, and you can do so as soon as the function call is completed.

This function can be called only on top-level windows. An error occurs when this function is called on other window types.

This function must be called whenever Desktop Window Manager (DWM) composition is toggled. Handle the [WM_DWMCOMPOSITIONCHANGED](https://learn.microsoft.com/windows/win32/dwm/wm-dwmcompositionchanged) message for composition change notification.

## Examples

The following example demonstrates how to apply the blur behind the entire window.

```cpp
HRESULT EnableBlurBehind(HWND hwnd)
{
   HRESULT hr = S_OK;

   // Create and populate the Blur Behind structure
   DWM_BLURBEHIND bb = {0};

   // Enable Blur Behind and apply to the entire client area
   bb.dwFlags = DWM_BB_ENABLE;
   bb.fEnable = true;
   bb.hRgnBlur = NULL;

   // Apply Blur Behind
   hr = DwmEnableBlurBehindWindow(hwnd, &bb);
   if (SUCCEEDED(hr))
   {
      // ...
   }
   return hr;
}
```

## See also

[DWM Blur Behind Overview](https://learn.microsoft.com/windows/win32/dwm/blur-ovw)