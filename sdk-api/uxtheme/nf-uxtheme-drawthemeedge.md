# DrawThemeEdge function

## Description

Draws one or more edges defined by the visual style of a rectangle.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part that contains the rectangle. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `pDestRect` [in]

Type: **LPCRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains, in logical coordinates, the rectangle.

### `uEdge` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**UINT** that specifies the type of inner and outer edges to draw. This parameter must be a combination of one inner-border flag and one outer-border flag, or one of the combination flags. The border flags are:

| Value | Meaning |
| --- | --- |
| BDR_RAISEDINNER | Raised inner edge |
| BDR_SUNKENINNER | Sunken inner edge |
| BDR_RAISEDOUTER | Raised outer edge |
| BDR_SUNKENOUTER | Sunken outer edge |
| EDGE_BUMP | Combination of BDR_RAISEDOUTER and BDR_SUNKENINNER |
| EDGE_ETCHED | Combination of BDR_SUNKENOUTER and BDR_RAISEDINNER |
| EDGE_RAISED | Combination of BDR_RAISEDOUTER and BDR_RAISEDINNER |
| EDGE_SUNKEN | Combination of BDR_SUNKENOUTER and BDR_SUNKENINNER |

### `uFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**UINT** that specifies the type of border to draw. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| BF_ADJUST | The rectangle pointed to by the *pDestRect* parameter is shrunk to exclude the edges that were drawn; otherwise the rectangle does not change. |
| BF_BOTTOM | Bottom of border rectangle. |
| BF_BOTTOMLEFT | Bottom and left side of border rectangle. |
| BF_BOTTOMRIGHT | Bottom and right side of border rectangle. |
| BF_DIAGONAL | Diagonal border. |
| BF_DIAGONAL_ENDBOTTOMLEFT | Diagonal border. The end point is the lower-left corner of the rectangle; the origin is the upper-right corner. |
| BF_DIAGONAL_ENDBOTTOMRIGHT | Diagonal border. The end point is the lower-right corner of the rectangle; the origin is the upper-left corner. |
| BF_DIAGONAL_ENDTOPLEFT | Diagonal border. The end point is the upper-left corner of the rectangle; the origin is the lower-right corner. |
| BF_DIAGONAL_ENDTOPRIGHT | Diagonal border. The end point is the upper-right corner of the rectangle; the origin is the lower-left corner. |
| BF_FLAT | Flat border. |
| BF_LEFT | Left side of border rectangle. |
| BF_MIDDLE | Interior of the rectangle is to be filled. |
| BF_MONO | One-dimensional border. |
| BF_RECT | Entire border rectangle. |
| BF_RIGHT | Right side of border rectangle. |
| BF_SOFT | Soft buttons instead of tiles. |
| BF_TOP | Top of border rectangle. |
| BF_TOPLEFT | Top and left side of border rectangle. |
| BF_TOPRIGHT | Top and right side of border rectangle. |

### `pContentRect` [out]

Type: **LPRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains, in logical coordinates, the rectangle that receives the interior rectangle, if *uFlags* is set to BF_ADJUST. This parameter may be set to **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)