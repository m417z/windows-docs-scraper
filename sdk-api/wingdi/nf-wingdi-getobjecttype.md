# GetObjectType function

## Description

The **GetObjectType** retrieves the type of the specified object.

## Parameters

### `h` [in]

A handle to the graphics object.

## Return value

If the function succeeds, the return value identifies the object. This value can be one of the following.

| Value | Meaning |
| --- | --- |
| OBJ_BITMAP | Bitmap |
| OBJ_BRUSH | Brush |
| OBJ_COLORSPACE | Color space |
| OBJ_DC | Device context |
| OBJ_ENHMETADC | Enhanced metafile DC |
| OBJ_ENHMETAFILE | Enhanced metafile |
| OBJ_EXTPEN | Extended pen |
| OBJ_FONT | Font |
| OBJ_MEMDC | Memory DC |
| OBJ_METAFILE | Metafile |
| OBJ_METADC | Metafile DC |
| OBJ_PAL | Palette |
| OBJ_PEN | Pen |
| OBJ_REGION | Region |

If the function fails, the return value is zero.

## See also

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)