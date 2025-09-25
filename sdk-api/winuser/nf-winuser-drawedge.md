# DrawEdge function

## Description

The **DrawEdge** function draws one or more edges of rectangle.

## Parameters

### `hdc` [in]

A handle to the device context.

### `qrc` [in, out]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the logical coordinates of the rectangle.

### `edge` [in]

The type of inner and outer edges to draw. This parameter must be a combination of one inner-border flag and one outer-border flag. The inner-border flags are as follows.

| Value | Meaning |
| --- | --- |
| **BDR_RAISEDINNER** | Raised inner edge. |
| **BDR_SUNKENINNER** | Sunken inner edge. |

The outer-border flags are as follows.

| Value | Meaning |
| --- | --- |
| **BDR_RAISEDOUTER** | Raised outer edge. |
| **BDR_SUNKENOUTER** | Sunken outer edge. |

Alternatively, the *edge* parameter can specify one of the following flags.

| Value | Meaning |
| --- | --- |
| **EDGE_BUMP** | Combination of BDR_RAISEDOUTER and BDR_SUNKENINNER. |
| **EDGE_ETCHED** | Combination of BDR_SUNKENOUTER and BDR_RAISEDINNER. |
| **EDGE_RAISED** | Combination of BDR_RAISEDOUTER and BDR_RAISEDINNER. |
| **EDGE_SUNKEN** | Combination of BDR_SUNKENOUTER and BDR_SUNKENINNER. |

### `grfFlags` [in]

The type of border. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **BF_ADJUST** | If this flag is passed, shrink the rectangle pointed to by the *qrc* parameter to exclude the edges that were drawn.<br><br>If this flag is not passed, then do not change the rectangle pointed to by the *qrc* parameter. |
| **BF_BOTTOM** | Bottom of border rectangle. |
| **BF_BOTTOMLEFT** | Bottom and left side of border rectangle. |
| **BF_BOTTOMRIGHT** | Bottom and right side of border rectangle. |
| **BF_DIAGONAL** | Diagonal border. |
| **BF_DIAGONAL_ENDBOTTOMLEFT** | Diagonal border. The end point is the lower-left corner of the rectangle; the origin is top-right corner. |
| **BF_DIAGONAL_ENDBOTTOMRIGHT** | Diagonal border. The end point is the lower-right corner of the rectangle; the origin is top-left corner. |
| **BF_DIAGONAL_ENDTOPLEFT** | Diagonal border. The end point is the top-left corner of the rectangle; the origin is lower-right corner. |
| **BF_DIAGONAL_ENDTOPRIGHT** | Diagonal border. The end point is the top-right corner of the rectangle; the origin is lower-left corner. |
| **BF_FLAT** | Flat border. |
| **BF_LEFT** | Left side of border rectangle. |
| **BF_MIDDLE** | Interior of rectangle to be filled. |
| **BF_MONO** | One-dimensional border. |
| **BF_RECT** | Entire border rectangle. |
| **BF_RIGHT** | Right side of border rectangle. |
| **BF_SOFT** | Soft buttons instead of tiles. |
| **BF_TOP** | Top of border rectangle. |
| **BF_TOPLEFT** | Top and left side of border rectangle. |
| **BF_TOPRIGHT** | Top and right side of border rectangle. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)