# ListView_GetEditControl macro

## Syntax

```cpp
HWND ListView_GetEditControl(
   HWND hwndLV
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the edit control if successful, or **NULL** otherwise.

## Description

Gets the handle to the edit control being used to edit a list-view item's text. You can use this macro or send the [LVM_GETEDITCONTROL](https://learn.microsoft.com/windows/desktop/Controls/lvm-geteditcontrol) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

## Remarks

When label editing begins, an edit control is created, positioned, and initialized. Before it is displayed, the list-view control sends its parent window an [LVN_BEGINLABELEDIT](https://learn.microsoft.com/windows/desktop/Controls/lvn-beginlabeledit) notification code.

To customize label editing, implement a handler for [LVN_BEGINLABELEDIT](https://learn.microsoft.com/windows/desktop/Controls/lvn-beginlabeledit) and have it use **ListView_GetEditControl** to send an [LVM_GETEDITCONTROL](https://learn.microsoft.com/windows/desktop/Controls/lvm-geteditcontrol) message to the list-view control. If a label is being edited, the return value will be a handle to the edit control. Use this handle to customize the edit control by sending the usual
**EM_XXX** messages.

When the user completes or cancels editing, the edit control is destroyed and the handle is no longer valid. You can subclass the edit control, but you should not destroy it. To cancel editing, you can send the list-view control a [WM_CANCELMODE](https://learn.microsoft.com/windows/desktop/winmsg/wm-cancelmode) message.

The list-view item being edited is the currently focused item—that is, the item in the focused state. To find an item based on its state, use the [LVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-getnextitem) message.

## See also

[LVM_GETEDITCONTROL](https://learn.microsoft.com/windows/desktop/Controls/lvm-geteditcontrol)