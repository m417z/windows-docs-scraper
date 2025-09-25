# ListView_Arrange macro

## Syntax

```cpp
BOOL ListView_Arrange(
   HWND hwndLV,
   UINT code
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful; otherwise, **FALSE**.

## Description

Arranges items in icon view. You can use this macro or send the [LVM_ARRANGE](https://learn.microsoft.com/windows/desktop/Controls/lvm-arrange) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `code`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One of the following values that specifies alignment:

| Value | Meaning |
| --- | --- |
| **LVA_ALIGNLEFT** | Not implemented. Apply the [LVS_ALIGNLEFT](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style instead. |
| **LVA_ALIGNTOP** | Not implemented. Apply the [LVS_ALIGNTOP](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style instead. |
| **LVA_DEFAULT** | Aligns items according to the list-view control's current alignment styles (the default value). |
| **LVA_SNAPTOGRID** | Snaps all icons to the nearest grid position. |