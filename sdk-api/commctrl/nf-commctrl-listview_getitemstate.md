# ListView_GetItemState macro

## Syntax

```cpp
UINT ListView_GetItemState(
   HWND hwndLV,
   int  i,
   UINT mask
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the current state for the specified item. The only valid bits in the return value are those that correspond to the bits set in the *mask* parameter.

## Description

Gets the state of a list-view item. You can use this macro or send the [LVM_GETITEMSTATE](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitemstate) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

The index of the list-view item.

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The state information to retrieve. This parameter can be a combination of the following values:

| Value | Meaning |
| --- | --- |
| **LVIS_CUT** | The item is marked for a cut-and-paste operation. |
| **LVIS_DROPHILITED** | The item is highlighted as a drag-and-drop target. |
| **LVIS_FOCUSED** | The item has the focus, so it is surrounded by a standard focus rectangle. Although more than one item may be selected, only one item can have the focus. |
| **LVIS_SELECTED** | The item is selected. The appearance of a selected item depends on whether it has the focus and also on the system colors used for selection. |
| **LVIS_OVERLAYMASK** | Use this mask to retrieve the item's overlay image index. |
| **LVIS_STATEIMAGEMASK** | Use this mask to retrieve the item's state image index. |

## Remarks

An item's state information includes a set of bit flags as well as image list indexes that indicate the item's state image and overlay image.

## See also

[ListView_SetItemState](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setitemstate)