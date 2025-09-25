# ListView_GetInsertMarkRect macro

## Syntax

```cpp
int ListView_GetInsertMarkRect(
   HWND   hwnd,
   LPRECT rc
);
```

## Return value

Type: **int**

Returns one of the following values:

| Return code | Description |
|---|---|
| 0 | No insertion point found. |
| 1 | Insertion point found. |

## Description

Gets the rectangle that bounds the insertion point. You can use this macro or send the [LVM_GETINSERTMARKRECT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getinsertmarkrect) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `rc`

Type: **LPRECT**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

## Remarks

To use **ListView_GetInsertMarkRect**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).