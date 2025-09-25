# ListView_SetItemState macro

## Syntax

```cpp
void ListView_SetItemState(
   HWND hwndLV,
   int  i,
   UINT data,
   UINT mask
);
```

## Description

Changes the state of an item in a list-view control. You can use this macro or send the [LVM_SETITEMSTATE](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitemstate) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

The index of the list-view item. If this parameter is -1, then the state change is applied to all items.

### `data`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New state bits for the item. The *mask* parameter indicates the valid bits of the *data* parameter. The macro ignores bits in the *data* parameter if the corresponding bit is not set in the *mask* parameter. The low-order byte contains a set of bit flags that indicate the item's state. This byte can be a combination of the following values:

| Value | Meaning |
| --- | --- |
| **LVIS_CUT** | The item is marked for a cut-and-paste operation. |
| **LVIS_DROPHILITED** | The item is highlighted as a drag-and-drop target. |
| **LVIS_FOCUSED** | The item has the focus, so it is surrounded by a standard focus rectangle. Although more than one item may be selected, only one item can have the focus. |
| **LVIS_SELECTED** | The item is selected. The appearance of a selected item depends on whether it has the focus and also on the system colors used for selection. Items will only show as selected if the list-view control has focus or the [LVS_SHOWSELALWAYS](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style is used. |

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Bits of the *data* parameter that you want to set or clear. You can use **ListView_SetItemState** both to set and to clear bits. To set an item's overlay image index, set the [LVIS_OVERLAYMASK](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) bits. To set an item's state image index, set the [LVIS_STATEIMAGEMASK](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) bits.

## Remarks

An item's state value includes a set of bit flags that indicate the item's state. The state value can also include image list indexes that indicate the item's state image and overlay image.

The *mask* parameter specifies the state bits you want to modify, and the *data* parameter specifies the new value for those bits. To set a bit in the item's internal state, set it in both the *mask* and *data* parameters. To clear a bit in the item's internal state, set it in the *mask* parameter and clear it in the *data* parameter. To leave a bit unchanged in the item's internal state, clear it in the *mask* parameter.

Bits 8 through 11 of the *data* parameter specify the one-based index of an overlay image in the control's image lists. Both the full-sized icon image list and the small icon image list can have overlay images. The overlay image is superimposed over the item's icon image. If these bits are zero, the item has no overlay image. To isolate these bits, use the [LVIS_OVERLAYMASK](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) mask. To specify an overlay index, use the [INDEXTOOVERLAYMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask) macro.

Bits 12 through 15 of the *data* parameter specify the one-based index of an image in the control's state image list. The state image is displayed next to an item's icon to indicate an application-defined state. If these bits are zero, the item has no state image. To isolate these bits, use the [LVIS_STATEIMAGEMASK](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) mask. To specify a state image index, use the [INDEXTOSTATEIMAGEMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextostateimagemask) macro.

## See also

[ListView_GetItemState](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_getitemstate)