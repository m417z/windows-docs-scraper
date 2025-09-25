# ListView_GetNumberOfWorkAreas macro

## Syntax

```cpp
BOOL ListView_GetNumberOfWorkAreas(
   HWND   hwnd,
   LPUINT pnWorkAreas
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value for this macro is not used.

## Description

Gets the number of working areas in a list-view control. You can use this macro or send the [LVM_GETNUMBEROFWORKAREAS](https://learn.microsoft.com/windows/desktop/Controls/lvm-getnumberofworkareas) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `pnWorkAreas`

Type: **LPUINT**

A pointer to a UINT value that receives the number of working areas in the list-view control. If zero is placed in this variable, then no working areas are currently set. This value cannot be **NULL**.

## See also

[Using List-View Controls](https://learn.microsoft.com/windows/desktop/Controls/using-list-view-controls)