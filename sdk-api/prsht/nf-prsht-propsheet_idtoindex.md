# PropSheet_IdToIndex macro

## Syntax

```cpp
int PropSheet_IdToIndex(
   HWND hDlg,
   int  id
);
```

## Return value

Type: **int**

Returns the zero-based index of the property sheet page specified by *id* if successful. Otherwise, it returns -1.

## Description

Takes the resource identifier (ID) of a property sheet page and returns its zero-based index. You can use this macro or send the [PSM_IDTOINDEX](https://learn.microsoft.com/windows/desktop/controls/psm-idtoindex) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet window.

### `id`

Type: **int**

Resource ID of the page.

## See also

[PropSheet_IndexToId](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propsheet_indextoid)