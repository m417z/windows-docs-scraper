# PICTDESC structure

## Description

Contains parameters to create a picture object through the [OleCreatePictureIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepictureindirect) function.

## Members

### `cbSizeofstruct`

The size of the structure, in bytes.

### `picType`

Type of picture described by this structure, which can be any value from the [PICTYPE](https://learn.microsoft.com/windows/desktop/com/pictype-constants) enumeration. This selects the arm of the union that corresponds to one of the picture type structures below.

### `bmp`

Structure containing bitmap information if **picType** is **PICTYPE_BITMAP**.

### `bmp.hbitmap`

The **HBITMAP** handle identifying the bitmap assigned to the picture object.

### `bmp.hpal`

The **HPALETTE** handle identifying the color palette for the bitmap.

### `wmf`

Structure containing metafile information if **picType** is **PICTYPE_METAFILE**.

### `wmf.hmeta`

The **HMETAFILE** handle identifying the metafile assigned to the picture object.

### `wmf.xExt`

Horizontal extent of the metafile in TWIPS units.

### `wmf.yExt`

Vertical extent of the metafile in TWIPS units.

### `icon`

Identifies a structure containing icon information if **picType** is **PICTYPE_ICON**.

### `icon.hicon`

The **HICON** handle identifying the icon assigned to the picture object.

### `emf`

Structure containing enhanced metafile information if **picType** is **PICTYPE_ENHMETAFILE**.

### `emf.hemf`

The **HENHMETAFILE** handle identifying the enhanced metafile assigned to the picture object.

## See also

[OleCreatePictureIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepictureindirect)

[PICTYPE](https://learn.microsoft.com/windows/desktop/com/pictype-constants)