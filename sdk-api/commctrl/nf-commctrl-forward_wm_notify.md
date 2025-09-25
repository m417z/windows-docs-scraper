# FORWARD_WM_NOTIFY macro

## Syntax

```cpp
VOID FORWARD_WM_NOTIFY(
   HWND     hwnd,
   int      idFrom,
   NMHDR    *pnmhdr,
   function fn
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a value whose meaning depends on the *fn* parameter.

## Description

Sends or posts the [WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify) message.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that receives the [WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify) message.

### `idFrom`

Type: **int**

The identifier of the control sending the message.

### `pnmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)***

A pointer to an [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains the notification code and additional information. For some notification codes, this parameter points to a larger structure that has the **NMHDR** structure as its first member.

### `fn`

Type: **function**

The function that sends or posts the [WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify) message. This parameter can be either the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) or [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea) function.

## Remarks

The **FORWARD_WM_NOTIFY** macro is defined as follows.

``` syntax
#define FORWARD_WM_NOTIFY(hwnd, idFrom, pnmhdr, fn) \

    (void)(fn)((hwnd), WM_NOTIFY, (WPARAM)(int)(id), \
    (LPARAM)(NMHDR*)(pnmhdr))
```