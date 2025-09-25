# TABLECELLPARMS structure

## Description

Defines the attributes of cells in a table row. The definitions include the corresponding Rich Text Format (RTF) control words, which are defined in the Rich Text Format (RTF) Specification.

## Members

### `dxWidth`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The width of a cell (\cellx).

### `nVertAlign`

### `fMergeTop`

### `fMergePrev`

### `fVertical`

### `fMergeStart`

### `fMergeCont`

### `wShading`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Shading in .01% (\clshdng). This controls the amount of pattern foreground color (**crForePat**) and pattern background color (**crBackPat**) that is used to create the cell background color. If **wShading** is 0, the cell background is **crBackPat**. If it's 10000, the cell background is **crForePat**. Values of **wShading** in between are mixtures of the two pattern colors.

### `dxBrdrLeft`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Left border width, in twips (\clbrdrl\brdrwN).

### `dyBrdrTop`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Top border width (\clbrdrt\brdrwN).

### `dxBrdrRight`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Right border width (\clbrdrr\brdrwN).

### `dyBrdrBottom`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Bottom border width (\clbrdrb\brdrwN).

### `crBrdrLeft`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

Left border color (\clbrdrl\brdrcf).

### `crBrdrTop`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

Top border color (\clbrdrt\brdrcf).

### `crBrdrRight`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

Right border color (\clbrdrr\brdrcf).

### `crBrdrBottom`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

Bottom border color (\clbrdrb\brdrcf).

### `crBackPat`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

Background color (\clcbpat).

### `crForePat`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

Foreground color (\clcfpat).

### `fMergeCont:1`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Merge with the previous cell (\clmrg).

### `fMergePrev:1`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Merge with the cell above (\clvmrg).

### `fMergeStart:1`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Start set of horizontally merged cells (\clmgf).

### `fMergeTop:1`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Top cell for vertical merge (\clvmgf).

### `fVertical:1`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Display text top to bottom, right to left (\cltxtbrlv).

### `nVertAlign:2`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The vertical alignment of cells (\clvertalt (def), \clvertalc, \clvertalb). It can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The content appears at the top of a cell. |
| 1 | The content is centered in the cell. |
| 2 | The content appears at the bottom of a cell. |

## See also

[EM_INSERTTABLE](https://learn.microsoft.com/windows/desktop/Controls/em-inserttable)

[TABLEROWPARMS](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-tablerowparms)