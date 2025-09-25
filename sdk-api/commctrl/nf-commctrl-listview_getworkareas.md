# ListView_GetWorkAreas macro

## Syntax

```cpp
void ListView_GetWorkAreas(
   HWND   hwnd,
   INT    nWorkAreas,
   LPRECT prc
);
```

## Description

Gets the working areas from a list-view control. You can use this macro, or send the [LVM_GETWORKAREAS](https://learn.microsoft.com/windows/desktop/Controls/lvm-getworkareas) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `nWorkAreas`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structures in the array at *prc*.

### `prc`

Type: **LPRECT**

A pointer to an array of [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structures that receive the working areas of the list-view control. Values in these structures are in client coordinates. *nWorkAreas* specifies the number of structures in this array.

## See also

[Using List-View Controls](https://learn.microsoft.com/windows/desktop/Controls/using-list-view-controls)