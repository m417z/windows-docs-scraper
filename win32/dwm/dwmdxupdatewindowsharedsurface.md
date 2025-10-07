# DwmDxUpdateWindowSharedSurface function

Notifies the DWM of an incoming update to a window shared surface.

## Parameters

`hwnd`

An [**HWND**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types) specifying the window being updated.

`uiUpdateId`

The update ID retrieved from [**DwmDxGetWindowSharedSurface**](https://learn.microsoft.com/windows/win32/dwm/dwmdxgetwindowsharedsurface).

`dwFlags`

Reserved.

`hmonitorAssociation`

Reserved.

`prc`

The rect of the window being updated, in window coordinate space. A NULL rectangle indicates that no region was updated.

## Return value

**S\_OK** if successful, otherwise a FAILED **HRESULT.**

## Remarks

This API is intended for implementing a graphics driver or runtime. An application may not call this method. This documentation is only valid for Windows 7, and this API is not guaranteed to exist nor behave in a similar manner on other versions of Windows. This function is not present in any header or static-link library, and it is located at ordinal 101 in dwmapi.dll.

This method should only ever be called after [**DwmDxGetWindowSharedSurface**](https://learn.microsoft.com/windows/win32/dwm/dwmdxgetwindowsharedsurface) returns **S\_OK**, and must be called in that scenario, regardless of whether the surface is updated or not.

## Requirements

| Requirement | Value |
|-|-|
| Minimum supported client | Windows 7 \[desktop apps only\] |
| Minimum supported server | None supported |
| End of client support | Windows 7 |
| Header | N/A |
| DLL | Dwmapi.dll |