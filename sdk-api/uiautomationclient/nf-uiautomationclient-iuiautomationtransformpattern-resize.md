# IUIAutomationTransformPattern::Resize

## Description

Resizes the UI Automation element.

## Parameters

### `width` [in]

Type: **double**

The new width of the window, in pixels.

### `height` [in]

Type: **double**

The new height of the window, in pixels.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When called on a control that supports split panes, this method can have the side effect of resizing other contiguous panes.

An object cannot be moved, resized, or rotated such that its resulting screen location would be completely outside the coordinates of its container and inaccessible to the keyboard or mouse. For example, when a top-level window is moved completely off-screen or a child object is moved outside the boundaries of the container's viewport. In these cases the object is placed as close to the requested screen coordinates as possible with the top or left coordinates overridden to be within the container boundaries.

## See also

[CachedCanResize](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtransformpattern-get_cachedcanresize)

[CurrentCanResize](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtransformpattern-get_currentcanresize)

[IUIAutomationTransformPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtransformpattern)