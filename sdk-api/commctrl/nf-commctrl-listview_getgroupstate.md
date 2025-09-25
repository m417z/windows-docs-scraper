# ListView_GetGroupState macro

## Syntax

```cpp
UINT ListView_GetGroupState(
  [in] HWND hwnd,
  [in] UINT dwGroupId,
  [in] UINT dwMask
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the combination of state values that are set. For example, if *dwMask* is LVGS_COLLAPSED and the value returned is zero, the LVGS_COLLAPSED state is not set. Zero is returned if the group is not found.

## Description

Gets the state for a specified group. Use this macro or send the [LVM_GETGROUPSTATE](https://learn.microsoft.com/windows/desktop/Controls/lvm-getgroupstate) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `dwGroupId` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the group by **iGroupId** (see [LVGROUP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvgroup) structure).

### `dwMask` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the state values to retrieve. This is a combination of the flags listed for the **state** member of [LVGROUP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvgroup).