# TabCtrl_InsertItem macro

## Syntax

```cpp
int TabCtrl_InsertItem(
         HWND     hwnd,
         int      iItem,
   const LPTCITEM pitem
);
```

## Return value

Type: **int**

Returns the index of the new tab if successful, or -1 otherwise.

## Description

Inserts a new tab in a tab control. You can use this macro or send the [TCM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-insertitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `iItem`

Type: **int**

Index of the new tab.

### `pitem`

Type: **const LPTCITEM**

Pointer to a [TCITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tcitema) structure that specifies the attributes of the tab. The **dwState** and **dwStateMask** members of this structure are ignored by this message.