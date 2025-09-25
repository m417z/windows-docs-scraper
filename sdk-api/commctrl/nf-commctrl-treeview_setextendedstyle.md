# TreeView_SetExtendedStyle macro

## Syntax

```cpp
HRESULT TreeView_SetExtendedStyle(
   HWND  hwnd,
   DWORD dw,
   UINT  mask
);
```

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If this macro succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Description

Sets the extended style for a specified TreeView control. Use this macro or send the [TVM_SETEXTENDEDSTYLE](https://learn.microsoft.com/windows/desktop/Controls/tvm-setextendedstyle) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the TreeView control.

### `dw`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value that indicates the extended style. For more information on styles, see [Tree-View Control Extended Styles](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-extended-styles).

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Mask used to select the styles to be set.