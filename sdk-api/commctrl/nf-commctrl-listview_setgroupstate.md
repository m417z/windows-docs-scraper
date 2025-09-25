# ListView_SetGroupState macro

## Syntax

```cpp
LRESULT ListView_SetGroupState(
  [in] HWND hwnd,
  [in] UINT dwGroupId,
  [in] UINT dwMask,
  [in] UINT dwState
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the ID of the group (**iGroupId**) if successful, or -1 otherwise.

## Description

Sets the state for a specified group.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `dwGroupId` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the group by **iGroupId** (see [LVGROUP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvgroup) structure).

### `dwMask` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the state values to set or clear. This is a combination of the flags listed for the **state** member of [LVGROUP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvgroup).

### `dwState` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the state values to set. States that are not included here but are included in *dwMask* are cleared.

## Remarks

**Note** To use this macro, you must provide a manifest specifying Comctl32.dll version 6.0. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

You can also set the group state by using [ListView_SetGroupInfo](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setgroupinfo).