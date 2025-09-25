# ITransformProvider::Rotate

## Description

Rotates the control.

## Parameters

### `degrees` [in]

Type: **double**

The number of degrees to rotate the control.
A positive number rotates clockwise; a negative number rotates counterclockwise.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An object cannot be moved, resized, or rotated such that its resulting screen location
would be completely outside the coordinates of its container and inaccessible to keyboard
or mouse. For example, a top-level window moved completely off-screen or a child object
moved outside the boundaries of the container's viewport. In these cases the object is
placed as close to the requested screen coordinates as possible with the top or left
coordinates overridden to be within the container boundaries.

## See also

[ITransformProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itransformprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)