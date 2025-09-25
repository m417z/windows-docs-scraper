# ENUMRECTS structure

## Description

The ENUMRECTS structure is used by the [CLIPOBJ_cEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-clipobj_cenumstart) function to provide information about rectangles in a clip region for the [CLIPOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-clipobj_benum) function.

## Members

### `c`

Specifies the number of RECTL structures in the **arcl** array.

### `arcl`

Is an array of [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structures that specify the coordinates of rectangles in the clip region.