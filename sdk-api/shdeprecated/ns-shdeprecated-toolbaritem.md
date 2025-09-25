# TOOLBARITEM structure

## Description

Deprecated. Data used in [IBrowserService2::_GetToolbarItem](https://learn.microsoft.com/windows/win32/api/shdeprecated/nf-shdeprecated-ibrowserservice2-_gettoolbaritem), [IBrowserService2::v_MayGetNextToolbarFocus](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice2-v_maygetnexttoolbarfocus), and [IBrowserService2::_SetFocus](https://learn.microsoft.com/windows/win32/api/shdeprecated/nf-shdeprecated-ibrowserservice2-_setfocus) to define a toolbar item.

## Members

### `ptbar`

Type: **[IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow)***

The [IDockingWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idockingwindow) of the item's particular toolbar.

### `rcBorderTool`

Type: **[BORDERWIDTHS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc136564(v=vs.85))**

A [BORDERWIDTHS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc136564(v=vs.85)) structure that contains the dimensions of the item, including its borders.

### `pwszItem`

Type: **LPWSTR**

A pointer to a buffer that contains the name of the toolbar item as a Unicode string.

### `fShow`

Type: **BOOL**

**TRUE** if the toolbar item is currently visible; otherwise, **FALSE**.

### `hMon`

Type: **HMONITOR**

The handle of the monitor on which the toolbar item appears.