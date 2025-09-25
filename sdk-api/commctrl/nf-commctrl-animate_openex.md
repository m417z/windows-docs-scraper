# Animate_OpenEx macro

## Syntax

```cpp
BOOL Animate_OpenEx(
   HWND      hwnd,
   HINSTANCE hInst,
   LPTSTR    szName
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Opens an AVI clip from a resource in a specified module and displays its first frame in an animation control. You can use this macro or send the [ACM_OPEN](https://learn.microsoft.com/windows/desktop/Controls/acm-open) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the animation control.

### `hInst`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An instance handle to the module from which the resource should be loaded. If this value is **NULL**, the resource is loaded from the module that created the animation control.

### `szName`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a buffer that contains the path of the AVI file or the name of an AVI resource. Alternatively, this parameter can consist of the AVI resource identifier in the [LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85)) and zero in the [HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85)). To create this value, use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. The control loads the AVI resource from the module specified by *hInst*. The AVI file or resource specified by *szName* must not contain audio.

If this parameter is **NULL**, the system closes the AVI file that was previously opened for the specified animation control, if any.

## Remarks

You can only open silent AVI clips. [ACM_OPEN](https://learn.microsoft.com/windows/desktop/Controls/acm-open) and [Animate_Open](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-animate_open) will fail if *szName* specifies an AVI clip that contains sound.

You can use [Animate_Close](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-animate_close) to close an AVI file or AVI resource that was previously opened for the specified animation control.