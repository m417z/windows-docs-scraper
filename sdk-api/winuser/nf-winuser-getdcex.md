# GetDCEx function

## Description

The **GetDCEx** function retrieves a handle to a device context (DC) for the client area of a specified window or for the entire screen. You can use the returned handle in subsequent GDI functions to draw in the DC. The device context is an opaque data structure, whose values are used internally by GDI.

This function is an extension to the [GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc) function, which gives an application more control over how and whether clipping occurs in the client area.

## Parameters

### `hWnd` [in]

A handle to the window whose DC is to be retrieved. If this value is **NULL**, **GetDCEx** retrieves the DC for the entire screen.

### `hrgnClip` [in]

A clipping region that may be combined with the visible region of the DC. If the value of *flags* is DCX_INTERSECTRGN or DCX_EXCLUDERGN, then the operating system assumes ownership of the region and will automatically delete it when it is no longer needed. In this case, the application should not use or delete the region after a successful call to **GetDCEx**.

### `flags` [in]

Specifies how the DC is created. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **DCX_WINDOW** | Returns a DC that corresponds to the window rectangle rather than the client rectangle. |
| **DCX_CACHE** | Returns a DC from the cache, rather than the OWNDC or CLASSDC window. Essentially overrides CS_OWNDC and CS_CLASSDC. |
| **DCX_PARENTCLIP** | Uses the visible region of the parent window. The parent's WS_CLIPCHILDREN and CS_PARENTDC style bits are ignored. The origin is set to the upper-left corner of the window identified by *hWnd*. |
| **DCX_CLIPSIBLINGS** | Excludes the visible regions of all sibling windows above the window identified by *hWnd*. |
| **DCX_CLIPCHILDREN** | Excludes the visible regions of all child windows below the window identified by *hWnd*. |
| **DCX_NORESETATTRS** | This flag is ignored. |
| **DCX_LOCKWINDOWUPDATE** | Allows drawing even if there is a [LockWindowUpdate](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lockwindowupdate) call in effect that would otherwise exclude this window. Used for drawing during tracking. |
| **DCX_EXCLUDERGN** | The clipping region identified by *hrgnClip* is excluded from the visible region of the returned DC. |
| **DCX_INTERSECTRGN** | The clipping region identified by *hrgnClip* is intersected with the visible region of the returned DC. |
| **DCX_INTERSECTUPDATE** | Reserved; do not use. |
| **DCX_VALIDATE** | Reserved; do not use. |

## Return value

If the function succeeds, the return value is the handle to the DC for the specified window.

If the function fails, the return value is **NULL**. An invalid value for the *hWnd* parameter will cause the function to fail.

## Remarks

Unless the display DC belongs to a window class, the [ReleaseDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-releasedc) function must be called to release the DC after painting. Also, **ReleaseDC** must be called from the same thread that called **GetDCEx**. The number of DCs is limited only by available memory.

The function returns a handle to a DC that belongs to the window's class if CS_CLASSDC, CS_OWNDC or CS_PARENTDC was specified as a style in the [WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa) structure when the class was registered.

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[GetWindowDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowdc)

[ReleaseDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-releasedc)

[WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa)