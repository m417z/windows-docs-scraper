# IUIAutomationTransformPattern::Rotate

## Description

Rotates the UI Automation element.

## Parameters

### `degrees` [in]

Type: **double**

The number of degrees to rotate the element. A positive number rotates clockwise; a negative number rotates counterclockwise.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An object cannot be moved, resized, or rotated such that its resulting screen location would be completely outside the coordinates of its container and inaccessible to the keyboard or mouse. For example, when a top-level window is moved completely off-screen or a child object is moved outside the boundaries of the container's viewport, the object is placed as close to the requested screen coordinates as possible with the top or left coordinates overridden to be within the container boundaries.