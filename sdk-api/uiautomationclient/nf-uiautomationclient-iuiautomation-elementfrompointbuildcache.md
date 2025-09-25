# IUIAutomation::ElementFromPointBuildCache

## Description

Retrieves the UI Automation element at the specified point on the desktop, prefetches the requested properties and control patterns, and stores the prefetched items in the cache.

## Parameters

### `pt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The desktop coordinates of the UI Automation element.

### `cacheRequest` [in]

Type: **[IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest)***

A pointer to the cache request, which specifies the properties and control patterns to store in the cache.

### `element` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives a pointer to the UI Automation element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[IUIAutomation::ElementFromPoint](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-elementfrompoint)