# ListView_GetFooterItem macro

## Syntax

```cpp
BOOL ListView_GetFooterItem(
  [in]      HWND         hwnd,
  [in]      UINT         iItem,
  [in, out] LVFOOTERITEM *pfi
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets information on a footer item for a specified list-view control. Use this macro or send the [LVM_GETFOOTERITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-getfooteritem) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iItem` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An index of the item.

### `pfi` [in, out]

Type: **[LVFOOTERITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvfooteritem)***

A pointer to a [LVFOOTERITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvfooteritem) structure to receive a value for the *state* and/or *pszText* members according to the value of the *mask* member. The caller is responsible for allocating this structure and setting its members to indicate to the receiver what information to return. For more information, see **LVFOOTERITEM**.