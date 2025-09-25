# ListView_SetCallbackMask macro

## Syntax

```cpp
BOOL ListView_SetCallbackMask(
   HWND hwnd,
   UINT mask
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Changes the callback mask for a list-view control. You can use this macro or send the [LVM_SETCALLBACKMASK](https://learn.microsoft.com/windows/desktop/Controls/lvm-setcallbackmask) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value of the callback mask. The bits of the mask indicate the item states or images for which the application stores the current state data. This value can be any combination of the following constants:

| Value | Meaning |
| --- | --- |
| **LVIS_CUT** | The item is marked for a cut-and-paste operation. |
| **LVIS_DROPHILITED** | The item is highlighted as a drag-and-drop target. |
| **LVIS_FOCUSED** | The item has the focus. |
| **LVIS_SELECTED** | The item is selected. |
| **LVIS_OVERLAYMASK** | The application stores the image list index of the current overlay image for each item. |
| **LVIS_STATEIMAGEMASK** | The application stores the image list index of the current state image for each item. |

## Remarks

The *callback mask* of a list-view control is a set of bit flags that specify the item states for which the application, rather than the control, stores the current data. The callback mask applies to all of the control's items, unlike the callback item designation, which applies to a specific item. The callback mask is zero by default, meaning that the list-view control stores all item state information. After creating a list-view control and initializing its items, you can use the **ListView_SetCallbackMask** macro or [LVM_SETCALLBACKMASK](https://learn.microsoft.com/windows/desktop/Controls/lvm-setcallbackmask) message to change the callback mask. To retrieve the current callback mask, send the [LVM_GETCALLBACKMASK](https://learn.microsoft.com/windows/desktop/Controls/lvm-getcallbackmask) message.

For more information about overlay images and state images, see [List-View Image Lists](https://learn.microsoft.com/windows/desktop/Controls/list-view-controls-overview).

For more information on list-view callbacks, see [Callback Items and the Callback Mask](https://learn.microsoft.com/windows/desktop/Controls/list-view-controls-overview)

## See also

[LVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-getdispinfo)