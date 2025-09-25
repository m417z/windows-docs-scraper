# ListView_GetCallbackMask macro

## Syntax

```cpp
UINT ListView_GetCallbackMask(
   HWND hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the callback mask.

## Description

Gets the callback mask for a list-view control. You can use this macro or send the [LVM_GETCALLBACKMASK](https://learn.microsoft.com/windows/desktop/Controls/lvm-getcallbackmask) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

## See also

[LVM_SETCALLBACKMASK](https://learn.microsoft.com/windows/desktop/Controls/lvm-setcallbackmask)