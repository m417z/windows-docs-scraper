# LVINSERTMARK structure

## Description

Used to describe insertion points.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the **LVINSERTMARK** structure.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag that specifies where the insertion point should appear. Use the following:

| Value | Meaning |
| --- | --- |
| **LVIM_AFTER** | The insertion point appears after the item specified if the LVIM_AFTER flag is set; otherwise it appears before the specified item. |

### `iItem`

Type: **int**

Item next to which the insertion point appears. If this member contains -1, there is no insertion point.

### `dwReserved`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**