# AnimateWindow function

## Description

Enables you to produce special effects when showing or hiding windows. There are four types of animation: roll, slide, collapse or expand, and alpha-blended fade.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window to animate. The calling thread must own this window.

### `dwTime` [in]

Type: **DWORD**

The time it takes to play the animation, in milliseconds. Typically, an animation takes 200 milliseconds to play.

### `dwFlags` [in]

Type: **DWORD**

The type of animation. This parameter can be one or more of the following values. Note that, by default, these flags take effect when showing a window. To take effect when hiding a window, use **AW_HIDE** and a logical OR operator with the appropriate flags.

| Value | Meaning |
| --- | --- |
| **AW_ACTIVATE**<br><br>0x00020000 | Activates the window. Do not use this value with **AW_HIDE**. |
| **AW_BLEND**<br><br>0x00080000 | Uses a fade effect. This flag can be used only if *hwnd* is a top-level window. |
| **AW_CENTER**<br><br>0x00000010 | Makes the window appear to collapse inward if **AW_HIDE** is used or expand outward if the **AW_HIDE** is not used. The various direction flags have no effect. |
| **AW_HIDE**<br><br>0x00010000 | Hides the window. By default, the window is shown. |
| **AW_HOR_POSITIVE**<br><br>0x00000001 | Animates the window from left to right. This flag can be used with roll or slide animation. It is ignored when used with **AW_CENTER** or **AW_BLEND**. |
| **AW_HOR_NEGATIVE**<br><br>0x00000002 | Animates the window from right to left. This flag can be used with roll or slide animation. It is ignored when used with **AW_CENTER** or **AW_BLEND**. |
| **AW_SLIDE**<br><br>0x00040000 | Uses slide animation. By default, roll animation is used. This flag is ignored when used with **AW_CENTER**. |
| **AW_VER_POSITIVE**<br><br>0x00000004 | Animates the window from top to bottom. This flag can be used with roll or slide animation. It is ignored when used with **AW_CENTER** or **AW_BLEND**. |
| **AW_VER_NEGATIVE**<br><br>0x00000008 | Animates the window from bottom to top. This flag can be used with roll or slide animation. It is ignored when used with **AW_CENTER** or **AW_BLEND**. |

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. The function will fail in the following situations:

* If the window is already visible and you are trying to show the window.
* If the window is already hidden and you are trying to hide the window.
* If there is no direction specified for the slide or roll animation.
* When trying to animate a child window with **AW_BLEND**.
* If the thread does not own the window. Note that, in this case, **AnimateWindow** fails but [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_SUCCESS**.

To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

To show or hide a window without special effects, use [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow).

When using slide or roll animation, you must specify the direction. It can be either **AW_HOR_POSITIVE**, **AW_HOR_NEGATIVE**, AW_VER_POSITIVE, or AW_VER_NEGATIVE.

You can combine **AW_HOR_POSITIVE** or **AW_HOR_NEGATIVE** with **AW_VER_POSITIVE** or **AW_VER_NEGATIVE** to animate a window diagonally.

The window procedures for the window and its child windows should handle any [WM_PRINT](https://learn.microsoft.com/windows/desktop/gdi/wm-print) or [WM_PRINTCLIENT](https://learn.microsoft.com/windows/desktop/gdi/wm-printclient) messages. Dialog boxes, controls, and common controls already handle **WM_PRINTCLIENT**. The default window procedure already handles **WM_PRINT**.

If a child window is displayed partially clipped, when it is animated it will have holes where it is clipped.

**AnimateWindow** supports RTL windows.

Avoid animating a window that has a drop shadow because it produces visually distracting, jerky animations.

## See also

**Conceptual**

**Other Resources**

**Reference**

[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow)

[WM_PRINT](https://learn.microsoft.com/windows/desktop/gdi/wm-print)

[WM_PRINTCLIENT](https://learn.microsoft.com/windows/desktop/gdi/wm-printclient)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)