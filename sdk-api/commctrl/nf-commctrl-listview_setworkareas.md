# ListView_SetWorkAreas macro

## Syntax

```cpp
void ListView_SetWorkAreas(
   HWND   hwnd,
   INT    nWorkAreas,
   LPRECT prc
);
```

## Description

Sets the working areas within a list-view control. You can use this macro or send the [LVM_SETWORKAREAS](https://learn.microsoft.com/windows/desktop/Controls/lvm-setworkareas) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

### `nWorkAreas`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structures in the array at *prc*. The maximum number of working areas allowed is defined by the **LV_MAX_WORKAREAS** value.

### `prc`

Type: **LPRECT**

A pointer to an array of [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structures that contain the new working areas of the list-view control. Values in these structures are in client coordinates. If this parameter is **NULL**, the working area will be set to the client area of the control. *nWorkAreas* specifies the number of structures in this array.

## See also

[Using List-View Controls](https://learn.microsoft.com/windows/desktop/Controls/using-list-view-controls)