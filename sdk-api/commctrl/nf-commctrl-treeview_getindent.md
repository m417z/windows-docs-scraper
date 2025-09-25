# TreeView_GetIndent macro

## Syntax

```cpp
UINT TreeView_GetIndent(
   HWND hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the amount of indentation.

## Description

Retrieves the amount, in pixels, that child items are indented relative to their parent items. You can use this macro or send the [TVM_GETINDENT](https://learn.microsoft.com/windows/desktop/Controls/tvm-getindent) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.