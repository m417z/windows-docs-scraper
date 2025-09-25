# TreeView_SetBorder macro

## Syntax

```cpp
int TreeView_SetBorder(
   HWND  hwnd,
   DWORD dwFlags,
   SHORT xBorder,
   SHORT yBorder
);
```

## Return value

Type: **int**

Returns a **int** value that contains the previous border size, in pixels. The **LOWORD** contains the previous size of the horizontal border, and the **HIWORD** contains the previous size of the vertical border.

## Description

[Intended for internal use; not recommended for use in applications. This macro may not be supported in future versions of Windows.]

Sets the size of the border for the items in a tree-view control. You can use this macro or send the [TVM_SETBORDER](https://learn.microsoft.com/windows/desktop/Controls/tvm-setborder) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Action flags. This parameter can be one or more of the following values:

| Value | Meaning |
| --- | --- |
| **TVSBF_XBORDER** | Applies the specified border size to the left side of the items in the tree-view control. |
| **TVSBF_YBORDER** | Applies the specified border size to the top of the items in the tree-view control. |

### `xBorder`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the left border, in pixels.

### `yBorder`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the top border, in pixels.

## Remarks

The item border is set just for spacing purposes. A successful setting triggers a recalculation of the scroll bars.

## See also

[TVM_SETBORDER](https://learn.microsoft.com/windows/desktop/Controls/tvm-setborder)