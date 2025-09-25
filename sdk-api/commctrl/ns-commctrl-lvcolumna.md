# LVCOLUMNA structure

## Description

Contains information about a column in report view. This structure is used both for creating and manipulating columns. This structure supersedes the LV_COLUMN structure.

## Members

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Variable specifying which members contain valid information. This member can be zero, or one or more of the following values:

| Value | Meaning |
| --- | --- |
| **LVCF_FMT** | The **fmt** member is valid. |
| **LVCF_WIDTH** | The **cx** member is valid. |
| **LVCF_TEXT** | The **pszText** member is valid. |
| **LVCF_SUBITEM** | The **iSubItem** member is valid. |
| **LVCF_IMAGE** | [Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **iImage** member is valid. |
| **LVCF_ORDER** | [Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **iOrder** member is valid. |
| **LVCF_MINWIDTH** | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.**The **cxMin** member is valid. |
| **LVCF_DEFAULTWIDTH** | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.**The **cxDefault** member is valid. |
| **LVCF_IDEALWIDTH** | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.**The **cxIdeal** member is valid. |

### `fmt`

Type: **int**

Alignment of the column header and the subitem text in the column. The alignment of the leftmost column is always LVCFMT_LEFT; it cannot be changed. This member can be a combination of the following values. Note that not all combinations are valid.

| Value | Meaning |
| --- | --- |
| **LVCFMT_LEFT** | Text is left-aligned. |
| **LVCFMT_RIGHT** | Text is right-aligned. |
| **LVCFMT_CENTER** | Text is centered. |
| **LVCFMT_JUSTIFYMASK** | A bitmask used to select those bits of **fmt** that control field justification. To check the format of a column, use a logical "and" to combine LCFMT_JUSTIFYMASK with **fmt**. You can then use a switch statement to determine whether the LVCFMT_LEFT, LVCFMT_RIGHT, or LVCFMT_CENTER bits are set. |
| **LVCFMT_IMAGE** | [Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The item displays an image from an image list. |
| **LVCFMT_BITMAP_ON_RIGHT** | [Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The bitmap appears to the right of text. This does not affect an image from an image list assigned to the header item. |
| **LVCFMT_COL_HAS_IMAGES** | [Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The header item contains an image in the image list. |
| **LVCFMT_FIXED_WIDTH** | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.** Can't resize the column; same as HDF_FIXEDWIDTH. |
| **LVCFMT_NO_DPI_SCALE** | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.** If not set, CCM_DPISCALE will govern scaling up fixed width. |
| **LVCFMT_FIXED_RATIO** | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.** Width will augment with the row height. |
| **LVCFMT_SPLITBUTTON** | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.** Column is a split button (same as HDF_SPLITBUTTON). The header of the column displays a split button (same as HDF_SPLITBUTTON). |

### `cx`

Type: **int**

Width of the column, in pixels.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If column information is being set, this member is the address of a null-terminated string that contains the column header text. If the structure is receiving information about a column, this member specifies the address of the buffer that receives the column header text.

### `cchTextMax`

Type: **int**

Size in **TCHAR**s of the buffer pointed to by the **pszText** member. If the structure is not receiving information about a column, this member is ignored.

### `iSubItem`

Type: **int**

Index of subitem associated with the column.

### `iImage`

Type: **int**

[Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Zero-based index of an image within the image list. The specified image will appear within the column.

### `iOrder`

Type: **int**

[Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Zero-based column offset. Column offset is in left-to-right order. For example, zero indicates the leftmost column.

### `cxMin`

Type: **int**

**Windows Vista**. Minimum width of the column in pixels.

### `cxDefault`

Type: **int**

**Windows Vista**. Application-defined value typically used to store the default width of the column. This member is ignored by the list-view control.

### `cxIdeal`

Type: **int**

**Windows Vista**. Read-only. The ideal width of the column in pixels, as the column may currently be autosized to a lesser width.

## Remarks

If a column is added to a list-view control with index 0 (the leftmost column), it is always LVCFMT_LEFT. Setting other flags on column 0 does not override that alignment. Therefore if you keep inserting columns with index 0, the text in all columns are left-aligned. If you want the first column to be right-aligned or centered you can make a dummy column, then insert one or more columns with index 1 or higher and specify the alignment you require. Finally delete the dummy column.

> [!NOTE]
> The commctrl.h header defines LVCOLUMN as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LVM_DELETECOLUMN](https://learn.microsoft.com/windows/desktop/Controls/lvm-deletecolumn)

[LVM_GETCOLUMN](https://learn.microsoft.com/windows/desktop/Controls/lvm-getcolumn)

[LVM_INSERTCOLUMN](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertcolumn)

[LVM_SETCOLUMN](https://learn.microsoft.com/windows/desktop/Controls/lvm-setcolumn)

**Reference**