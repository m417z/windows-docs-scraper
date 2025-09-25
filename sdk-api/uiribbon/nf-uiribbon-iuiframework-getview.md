# IUIFramework::GetView

## Description

Retrieves the address of a pointer to an interface that represents a Windows Ribbon framework View, such as [IUIRibbon](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiribbon)
or [IUIContextualUI](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicontextualui).

## Parameters

### `viewId` [in]

Type: **UINT32**

The ID for the View.
A value of 0 for a [Ribbon](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-ribbon) or the [Command.Id](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-command-id) of a [ContextPopup](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-contextpopup).

### `riid` [in]

Type: **REFIID**

The interface ID for [IUIRibbon](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiribbon)
or [IUIContextualUI](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicontextualui).

### `ppv` [out]

Type: **void****

When this method returns, contains the address of a pointer to an [IUIRibbon](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiribbon)
or an [IUIContextualUI](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicontextualui) object.

## Return value

Type: **HRESULT**

Returns S_OK if successful; otherwise, an error value from the following list.

| Value | Description |
| --- | --- |
| E_INVALIDARG | *riid* is not a valid interface ID. |
| E_FAIL | The operation failed. |

## Remarks

Ribbon framework UI functionality is differentiated by Views, which are essentially built-in core frameworks,
such as the [Ribbon](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-ribbon) and [ContextPopup](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-contextpopup).

Rather than maintaining a pointer to an interface throughout the life of an application,
**IUIFramework::GetView** enables a host application to create a temporary interface pointer
and call methods as necessary.

**Note** The host application must call [IUnknown::Release](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-release) on the temporary interface pointer to avoid a memory leak.

For example, each time there is a change to the size of the ribbon, a host application calls
[GetHeight](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiribbon-getheight) to adjust the size of the host client area
appropriately.

#### Examples

The following example demonstrates how to use the **IUIFramework::GetView** method to retrieve a Ribbon View object, call the [GetHeight](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiribbon-getheight) method to retrieve the height of the ribbon, and calculate a display location for a [Context Popup](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-controls-contextpopup) control based on the height of the ribbon.

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

[IUIFramework](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiframework)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)