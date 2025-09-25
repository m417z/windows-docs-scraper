# GetCurrentObject function

## Description

The **GetCurrentObject** function retrieves a handle to an object of the specified type that has been selected into the specified device context (DC).

## Parameters

### `hdc` [in]

A handle to the DC.

### `type` [in]

The object type to be queried. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **OBJ_BITMAP** | Returns the current selected bitmap. |
| **OBJ_BRUSH** | Returns the current selected brush. |
| **OBJ_COLORSPACE** | Returns the current color space. |
| **OBJ_FONT** | Returns the current selected font. |
| **OBJ_PAL** | Returns the current selected palette. |
| **OBJ_PEN** | Returns the current selected pen. |

## Return value

If the function succeeds, the return value is a handle to the specified object.

If the function fails, the return value is **NULL**.

## Remarks

An application can use the **GetCurrentObject** and [GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject) functions to retrieve descriptions of the graphic objects currently selected into the specified DC.

#### Examples

For an example, see [Retrieving Graphic-Object Attributes and Selecting New Graphic Objects](https://learn.microsoft.com/windows/desktop/gdi/retrieving-graphic-object-attributes-and-selecting-new-graphic-objects).

## See also

[CreateColorSpace](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcolorspacea)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)