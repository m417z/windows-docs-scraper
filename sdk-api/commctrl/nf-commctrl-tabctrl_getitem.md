# TabCtrl_GetItem macro

## Syntax

```cpp
BOOL TabCtrl_GetItem(
   HWND     hwnd,
   int      iItem,
   LPTCITEM pitem
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Retrieves information about a tab in a tab control. You can use this macro or send the [TCM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-getitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `iItem`

Type: **int**

Index of the tab.

### `pitem`

Type: **LPTCITEM**

Pointer to a [TCITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tcitema) structure that specifies the information to retrieve and receives information about the tab. When the message is sent, the
**mask** member specifies which attributes to return. If the **mask** member specifies the TCIF_TEXT value, the
**pszText** member must contain the address of the buffer that receives the item text, and the **cchTextMax** member must specify the size of the buffer.

## Remarks

If the TCIF_TEXT flag is set in the
**mask** member of the [TCITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tcitema) structure, the control may change the **pszText** member of the structure to point to the new text instead of filling the buffer with the requested text. The control may set the **pszText** member to **NULL** to indicate that no text is associated with the item.