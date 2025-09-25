# IUIRibbon::GetHeight

## Description

Retrieves the height of the ribbon.

## Parameters

### `cy` [out]

Type: **UINT32***

The height of the ribbon, in pixels.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The value returned for *cy* is based on a number of dependencies that
include, but are not limited to, the width of the host window and the layout template declared
in the Ribbon markup.

#### Examples

The following example demonstrates how to use the **IUIRibbon::GetHeight** method to retrieve the height of the ribbon to calculate a display location for a [Context Popup](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-controls-contextpopup) control.

```cpp
void GetDisplayLocation(POINT &pt, HWND hWnd)
{
  if (pt.x == -1 && pt.y == -1)
  {
    HRESULT hr = E_FAIL;

    // Display the menu in the upper-left corner of the client area, below the ribbon.
    IUIRibbon* pRibbon;
    hr = g_pFramework->GetView(0, IID_PPV_ARGS(&pRibbon));
    if (SUCCEEDED(hr))
    {
      UINT32 uRibbonHeight = 0;
      hr = pRibbon->GetHeight(&uRibbonHeight);
      if (SUCCEEDED(hr))
      {
        pt.x = 0;
        pt.y = uRibbonHeight;
        // Convert client coordinates of a specified point to screen coordinates.
        ClientToScreen(hWnd, &pt);
      }
      pRibbon->Release();
    }
    if (FAILED(hr))
    {
      // Default to just the upper-right corner of the entire screen.
      pt.x = 0;
      pt.y = 0;
    }
  }
}
```

## See also

[IUIRibbon](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiribbon)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)