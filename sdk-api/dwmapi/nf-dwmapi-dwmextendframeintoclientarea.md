# DwmExtendFrameIntoClientArea function

## Description

Extends the window frame into the client area.

## Parameters

### `hWnd` [in]

The handle to the window in which the frame will be extended into the client area.

### `pMarInset` [in]

A pointer to a [MARGINS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-margins) structure that describes the margins to use when extending the frame into the client area.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function must be called whenever Desktop Window Manager (DWM) composition is toggled. Handle the [WM_DWMCOMPOSITIONCHANGED](https://learn.microsoft.com/windows/desktop/dwm/wm-dwmcompositionchanged) message for composition change notification.

Use negative margin values to create the "sheet of glass" effect where the client area is rendered as a solid surface with no window border.

#### Examples

The following sample demonstrates how to extend the bottom margin, creating a large bottom frame.

```cpp

HRESULT ExtendIntoClientBottom(HWND hwnd)
{
   // Set margins, extending the bottom margin
   MARGINS margins = {0,0,0,25};
   HRESULT hr = S_OK;

   // Extend frame on the bottom of client area
   hr = DwmExtendFrameIntoClientArea(hwnd,&margins);
   if (SUCCEEDED(hr))
   {
      // ...
   }
   return hr;
}
```

The following sample demonstrates the "sheet of glass" effect where the client area is rendered without a window border.

```cpp

HRESULT ExtendIntoClientAll(HWND hwnd)
{
   // Negative margins have special meaning to DwmExtendFrameIntoClientArea.
   // Negative margins create the "sheet of glass" effect, where the client area
   // is rendered as a solid surface with no window border.
   MARGINS margins = {-1};
   HRESULT hr = S_OK;

   // Extend the frame across the entire window.
   hr = DwmExtendFrameIntoClientArea(hwnd,&margins);
   if (SUCCEEDED(hr))
   {
      // ...
   }
   return hr;
}
```

## See also

[DWM Blur Behind Overview](https://learn.microsoft.com/windows/desktop/dwm/blur-ovw)