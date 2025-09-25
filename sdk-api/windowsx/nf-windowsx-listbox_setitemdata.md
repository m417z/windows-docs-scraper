# ListBox_SetItemData macro

## Syntax

```cpp
int ListBox_SetItemData(
   HWND   hwndCtl,
   int    index,
   LPARAM data
);
```

## Return value

Type: **int**

If an error occurs, the return value is LB_ERR.

## Description

Sets the application-defined value associated with the specified list box item. You can use this macro or send the [LB_SETITEMDATA](https://learn.microsoft.com/windows/desktop/Controls/lb-setitemdata) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item.

### `data`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The item data to set.

## Remarks

For more information, see [LB_SETITEMDATA](https://learn.microsoft.com/windows/desktop/Controls/lb-setitemdata).