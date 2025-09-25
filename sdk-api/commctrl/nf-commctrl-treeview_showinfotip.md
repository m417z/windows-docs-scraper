# TreeView_ShowInfoTip macro

## Syntax

```cpp
DWORD TreeView_ShowInfoTip(
   HWND  hwnd,
   HITEM hitem
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Return value is ignored.

## Description

Shows the infotip for a specified item in a tree-view control. Use this macro or send the [TVM_SHOWINFOTIP](https://learn.microsoft.com/windows/desktop/Controls/tvm-showinfotip) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HITEM**

Handle to the item.

## Remarks

Most applications do not use this macro. Infotips are shown automatically. For more information, see Using Tree-view Infotips in the [About Tree-View Controls](https://learn.microsoft.com/windows/desktop/Controls/tree-view-controls) overview.