# IDCompositionDesktopDevice::CreateTargetForHwnd

## Description

Creates a composition target object that is bound to the window that is represented by the specified window handle.

## Parameters

### `hwnd` [in]

The window to which the composition target object should be bound. This parameter must not be NULL.

### `topmost`

TRUE if the visual tree should be displayed on top of the children of the window specified by the hwnd parameter; otherwise, the visual tree is displayed behind the children.

### `target` [out]

The new composition target object. This parameter must not be NULL.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A DirectComposition visual tree must be bound to a window before anything can be displayed on screen. The window can be a top-level window or a child window. In either case, the window can be a layered window, but in all cases the window must belong to the calling process. If the window belongs to a different process, this method returns [DCOMPOSITION_ERROR_ACCESS_DENIED](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes).

When DirectComposition content is composed to the window, the content is always composed on top of whatever is drawn directly to that window through the device context returned by the [GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc) function, or by calls to DirectX Present methods. However, because window clipping rules apply to DirectComposition content, if the window has child windows, those child windows may clip the visual tree. The topmost parameter determines whether child windows clip the visual tree.

Conceptually, each window consists of four layers:

1. The contents drawn directly to the window handle (this is the bottommost layer).
2. An optional DirectComposition visual tree.
3. The contents of all child windows, if any.
4. Another optional DirectComposition visual tree (this is the topmost layer).

All four layers are clipped to the window’s visible region.

At most, only two composition targets can be created for each window in the system, one topmost and one not topmost. If a composition target is already bound to the specified window at the specified layer, this method fails. When a composition target object is destroyed, the layer it composed is available for use by a new composition target object.

## See also

[IDCompositionDesktopDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondesktopdevice)

[IDCompositionVisual2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual2)