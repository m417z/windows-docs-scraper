# PropSheet_IndexToId macro

## Syntax

```cpp
int PropSheet_IndexToId(
   HWND hDlg,
   int  i
);
```

## Return value

Type: **int**

Returns the resource ID of the property sheet page specified by *i* if successful. Otherwise, it returns zero.

## Description

Takes the index of a property sheet page and returns its resource identifier (ID). You can use this macro or send the [PSM_INDEXTOID](https://learn.microsoft.com/windows/desktop/Controls/psm-indextoid) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `i`

Type: **int**

Zero-based index of the page.

## See also

[PSM_INDEXTOID](https://learn.microsoft.com/windows/desktop/Controls/psm-indextoid)