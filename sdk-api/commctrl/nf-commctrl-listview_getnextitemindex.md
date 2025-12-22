# ListView_GetNextItemIndex macro

## Syntax

```cpp
BOOL ListView_GetNextItemIndex(
  [in]      HWND        hwnd,
  [in, out] LVITEMINDEX *plvii,
            LPARAM      flags
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets the index of the item in a particular list-view control that has the specified properties and relationship to another specific item. Use this macro or send the [LVM_GETNEXTITEMINDEX](https://learn.microsoft.com/windows/desktop/controls/lvm-getnextitemindex) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `plvii` [in, out]

Type: **[LVITEMINDEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitemindex)***

A pointer to the [LVITEMINDEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitemindex) structure with which the item begins the search, or -1 to find the first item that matches the specified flags. The calling process is responsible for allocating this structure and setting its members.

### `flags`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The relationship to the item specified in parameter
*plvii*. This can be one or a combination of the following values:

| Value | Meaning |
| --- | --- |
| Searches by index. |  |
| LVNI_ALL | Searches for a subsequent item by index, the default value. |
| Searches by physical relationship to the index of the item where the search is to begin. |  |
| LVNI_ABOVE | Searches for an item that is above the specified item. |
| LVNI_BELOW | Searches for an item that is below the specified item. |
| LVNI_TOLEFT | Searches for an item to the left of the specified item. |
| LVNI_PREVIOUS | **Windows Vista and later:** Searches for the item that is previous to the specified item. The LVNI_PREVIOUS flag is not directional (LVNI_ABOVE will find the item positioned above, while LVNI_PREVIOUS will find the item ordered before.) The LVNI_PREVIOUS flag essentially reverses the logic of the search performed via the LVM_GETNEXTITEM or LVM_GETNEXTITEMINDEX messages. |
| LVNI_TORIGHT | Searches for an item to the right of the specified item. |
| LVNI_DIRECTIONMASK | **Windows Vista and later:** A directional flag mask with value as follows: LVNI_ABOVE \| LVNI_BELOW \| LVNI_TOLEFT \| LVNI_TORIGHT. |
| The state of the item to find can be specified with one or a combination of the following values: |  |
| LVNI_CUT | The item has the [LVIS_CUT](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) state flag set. |
| LVNI_DROPHILITED | The item has the [LVIS_DROPHILITED](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) state flag set |
| LVNI_FOCUSED | The item has the [LVIS_FOCUSED](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) state flag set. |
| LVNI_SELECTED | The item has the [LVIS_SELECTED](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) state flag set. |
| LVNI_STATEMASK | **Windows Vista and later:** A state flag mask with value as follows: LVNI_FOCUSED \| LVNI_SELECTED \| LVNI_CUT \| LVNI_DROPHILITED. |
| Searches by appearance of items or by group. |  |
| LVNI_VISIBLEORDER | **Windows Vista and later:** Search the visible order. |
| LVNI_VISIBLEONLY | **Windows Vista and later:** Search the visible items. |
| LVNI_SAMEGROUPONLY | **Windows Vista and later:** Search the current group. |
| If an item does not have all of the specified state flags set, the search continues with the next item. |  |

## Remarks

Note that the following flags, for use only with Windows Vista, are mutually exclusive of any other flags in use: LVNI_PREVIOUS, LVNI_VISIBLEONLY, LVNI_SAMEGROUPONLY, LVNI_VISIBLEORDER, LVNI_DIRECTIONMASK, and LVNI_STATEMASK.

## See also

[LVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-getnextitem)