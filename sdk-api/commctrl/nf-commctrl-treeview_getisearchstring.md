# TreeView_GetISearchString macro

## Syntax

```cpp
BOOL TreeView_GetISearchString(
   HWND   hwndTV,
   LPTSTR lpsz
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if the string is retrieved; **FALSE** otherwise.

## Description

Retrieves the incremental search string for a tree-view control. The tree-view control uses the incremental search string to select an item based on characters typed by the user. You can use this macro or send the [TVM_GETISEARCHSTRING](https://learn.microsoft.com/windows/desktop/Controls/tvm-getisearchstring) message explicitly.

## Parameters

### `hwndTV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `lpsz`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the buffer that receives the incremental search string.

## Remarks

**Security Warning:** Using this macro incorrectly might compromise the security of your program. You must allocate a large enough buffer to hold the string. First call the macro passing **NULL** in *lpsz*. This returns the number of characters, excluding **NULL**, that are required. Then call the macro a second time to retrieve the string. You should review [Security Considerations: Microsoft Windows Controls](https://learn.microsoft.com/windows/desktop/Controls/sec-comctls) before continuing.

If the tree-view control is not in incremental search mode, the return value is zero.