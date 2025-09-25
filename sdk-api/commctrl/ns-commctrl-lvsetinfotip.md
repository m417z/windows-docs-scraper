# LVSETINFOTIP structure

## Description

Provides information about tooltip text that is to be set.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the **LVSETINFOTIP** structure.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag that specifies how the text should be set. Set to zero.

### `pszText`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a Unicode string that contains the tooltip text.

### `iItem`

Type: **int**

Value of type **int** that contains the
zero-based index of the item to which this structure refers.

### `iSubItem`

Type: **int**

Value of type **int** that contains the one-based index of the subitem to which this structure refers.