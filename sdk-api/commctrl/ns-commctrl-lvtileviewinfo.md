# LVTILEVIEWINFO structure

## Description

Provides information about a list-view control when it is displayed in tile view.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the **LVTILEVIEWINFO** structure.

### `dwMask`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Mask that determines which members are valid. This member may be one of the following values.

| Value | Meaning |
| --- | --- |
| LVTVIM_TILESIZE | **sizeTile** is valid. |
| LVTVIM_COLUMNS | **cLines** is valid. |
| LVTVIM_LABELMARGIN | **rcLabelMargin** is valid. |

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that determines how the tiles are sized in tile view. This member may be one of the following values.

| Value | Meaning |
| --- | --- |
| LVTVIF_AUTOSIZE | Size the tiles automatically. |
| **LVTVIF_EXTENDED** | This flag is not supported and should not be used. |
| LVTVIF_FIXEDWIDTH | Apply a fixed width to the tiles. |
| LVTVIF_FIXEDHEIGHT | Apply a fixed height to the tiles. |
| LVTVIF_FIXEDSIZE | Apply a fixed height and width to the tiles. |

### `sizeTile`

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)**

Size of an individual tile. Values for dimensions not specified as fixed in **dwFlags** are ignored.

### `cLines`

Type: **int**

Maximum number of text lines in each item label, not counting the title.

### `rcLabelMargin`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) that contains coordinates of the label margin.

## Remarks

By default, the dimensions of tiles are determined automatically. To apply a fixed size, supply the correct value or values in **sizeTile** and set the appropriate flag in **dwFlags**. Allow enough vertical space for all lines of the label to be displayed. If a line does not fit in the allowed horizontal space, it is terminated with an ellipsis.

## See also

**Conceptual**

[ListView_GetTileViewInfo](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_gettileviewinfo)

[ListView_SetTileViewInfo](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_settileviewinfo)

**Reference**

[Using List-View Controls](https://learn.microsoft.com/windows/desktop/Controls/using-list-view-controls)