# TABLEROWPARMS structure

## Description

Defines the attributes of rows in a table. The definitions include the corresponding Rich Text Format (RTF) control words, which are defined in the Rich Text Format (RTF) Specification.

## Members

### `cbRow`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The count of bytes in this structure.

### `cbCell`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The count of bytes in [TABLECELLPARMS](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-tablecellparms).

### `cCell`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The count of cells in a row, up to the maximum specified by MAX_TABLE_CELLS.

### `cRow`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The count of rows.

### `dxCellMargin`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the left and right margins in a cell (\trgaph).

### `dxIndent`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The amount of left indentation, or right indentation if the **fRTL** member is **TRUE** (similar to \trleft).

### `dyHeight`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The height of a row (\trrh).

### `nAlignment`

### `fRTL`

### `fKeep`

### `fKeepFollow`

### `fWrap`

### `fIdentCells`

### `cpStartRow`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The character position that indicates where to insert table. A value of –1 indicates the character position of the selection.

### `bTableLevel`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The table nesting level ([EM_GETTABLEPARMS](https://learn.microsoft.com/windows/desktop/Controls/em-gettableparms) only).

### `iCell`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the cell to insert or delete ([EM_SETTABLEPARMS](https://learn.microsoft.com/windows/desktop/Controls/em-settableparms) only).

### `fIdentCells:1`

Type: **DWORD**

 Indent cells.

### `fKeep:1`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Keep rows together (\trkeep).

### `fKeepFollow:1`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Keep the row on the same page as the following row (\trkeepfollow).

### `fRTL:1`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Display cells in right-to-left order (\rtlrow).

### `fWrap:1`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Wrap text to the right or left, depending on **bAlignment**(see \tdfrmtxtLeftN and \tdfrmtxtRightN).

### `nAlignment:3`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Row alignment \trql, trqr, \trqc)

| Value | Meaning |
| --- | --- |
| **PFA_CENTER** | The rows are centered. |
| **PFA_LEFT** | The rows are aligned with the left margin. |
| **PFA_RIGHT** | The rows are aligned with the right margin. |

## See also

[EM_INSERTTABLE](https://learn.microsoft.com/windows/desktop/Controls/em-inserttable)

[TABLECELLPARMS](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-tablecellparms)