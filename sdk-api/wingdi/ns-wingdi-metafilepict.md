# METAFILEPICT structure

## Description

Defines the metafile picture format used for exchanging metafile data through the clipboard.

## Members

### `mm`

Type: **LONG**

The mapping mode in which the picture is drawn.

### `xExt`

Type: **LONG**

The size of the metafile picture for all modes except the **MM_ISOTROPIC** and **MM_ANISOTROPIC** modes. (For more information about these modes, see the **yExt** member.) The x-extent specifies the width of the rectangle within which the picture is drawn. The coordinates are in units that correspond to the mapping mode.

### `yExt`

Type: **LONG**

The size of the metafile picture for all modes except the **MM_ISOTROPIC** and **MM_ANISOTROPIC** modes. The y-extent specifies the height of the rectangle within which the picture is drawn. The coordinates are in units that correspond to the mapping mode. For **MM_ISOTROPIC** and **MM_ANISOTROPIC** modes, which can be scaled, the **xExt** and **yExt** members contain an optional suggested size in **MM_HIMETRIC** units. For **MM_ANISOTROPIC** pictures, **xExt** and **yExt** can be zero when no suggested size is supplied. For **MM_ISOTROPIC** pictures, an aspect ratio must be supplied even when no suggested size is given. (If a suggested size is given, the aspect ratio is implied by the size.) To give an aspect ratio without implying a suggested size, set **xExt** and **yExt** to negative values whose ratio is the appropriate aspect ratio. The magnitude of the negative **xExt** and **yExt** values is ignored; only the ratio is used.

### `hMF`

Type: **HMETAFILE**

A handle to a memory metafile.

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

**Reference**

[SetClipboardData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboarddata)