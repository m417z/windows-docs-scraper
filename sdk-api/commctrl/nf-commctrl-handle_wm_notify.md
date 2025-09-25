# HANDLE_WM_NOTIFY macro

## Syntax

```cpp
void HANDLE_WM_NOTIFY(
   HWND     hwnd,
   WPARAM   wParam,
   LPARAM   lParam,
   function fn
);
```

## Description

Calls a function that processes the [WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify) message.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that received [WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify).

### `wParam`

Type: **[WPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The first parameter of [WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify).

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The second parameter of [WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify).

### `fn`

Type: **function**

The function that is to process [WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify).

## Remarks

The **HANDLE_WM_NOTIFY** macro is defined as follows.

``` syntax
#define HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn) \

    (fn)((hwnd), (int)(wParam), (NMHDR*)(lParam))
```

The macro can be used inside a dialog window procedure to simplify the calling of an application-defined function that requires an [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) parameter.