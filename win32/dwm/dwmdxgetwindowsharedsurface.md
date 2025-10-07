# DwmDxGetWindowSharedSurface function

Retrieves the DirectX shared surface backing a given window. This surface can be written to in order to update the contents of the window.

## Parameters

`hwnd`

An [**HWND**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types) specifying the window to be updated.

`luidAdapter`

The [**LUID**](https://learn.microsoft.com/previous-versions/bb401655(v%3dmsdn.10)) of the adapter where the surface should be located.

`hmonitorAssociation`

Reserved.

`dwFlags`

This parameter can be one of the following values, or a bitwise OR combination of multiple values where appropriate.

| Value | Meaning |
|-|-|
| **DWM\_REDIRECTION\_FLAG\_WAIT**

0 | Causes the function to block until a vertical synchronization (VSync) has passed since the last time the function was called successfully. | | **DWM\_REDIRECTION\_FLAG\_SUPPORT\_PRESENT\_TO\_GDI\_SURFACE**

0x10 | Indicates that the calling application is capable of presenting to a GDI shared surface. | `pfmtWindow` On input, the desired format of the surface. On output, the actual format of the returned surface. `phDxSurface` On output, the shared handle to the surface. `puiUpdateId` On output, the ID of the update. ## Return value This function can return one of these values. | Return code | Description | |-|-| | **S\_OK** | The call succeeded, and you should update the surface, being sure to pass the update ID to [D3DKMTRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtrender) (in the **PresentHistoryToken** member of the **D3DKMT\_RENDER** structure when the update is submitted, and then [**DwmDxUpdateWindowSharedSurface**](https://learn.microsoft.com/windows/win32/dwm/dwmdxupdatewindowsharedsurface) should be called with the same update ID. Note that **DwmDxUpdateWindowSharedSurface** should be called regardless of whether the surface was actually updated or not. | | **DWM\_S\_GDI\_REDIRECTION\_SURFACE** | The call succeeded, and you should update the surface by calling [D3DKMTPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtpresent), and setting **PresentHistoryToken** member's **Model** to **D3DKMT\_PM\_REDIRECTED\_BLT**, and providing the update ID in the **Blt** member of the union. This value is only returned if **DWM\_REDIRECTION\_FLAG\_SUPPORT\_PRESENT\_TO\_GDI\_SURFACE** was specified in *dwFlags*. | | **DWM\_E\_ADAPTER\_NOT\_FOUND** | The value of *luidAdapter* is not valid. | | **DWM\_E\_COMPOSITIONDISABLED** | DWM is not currently enabled, and the application will need to present another way. | ## Remarks This API is intended for implementing a graphics driver or runtime. An application may not call this method. This documentation is only valid for Windows 7, and this API is not guaranteed to exist nor behave in a similar manner on other versions of Windows. This function is not present in any header or static-link library, and it is located at ordinal 100 in dwmapi.dll. ## Requirements | Requirement | Value | |-|-| | Minimum supported client | Windows 7 \[desktop apps only\] | | Minimum supported server | None supported | | End of client support | Windows 7 | | Header | N/A | | DLL | Dwmapi.dll |