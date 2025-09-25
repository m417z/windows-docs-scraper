# CreatePenIndirect function

## Description

The **CreatePenIndirect** function creates a logical cosmetic pen that has the style, width, and color specified in a structure.

## Parameters

### `plpen` [in]

Pointer to a [LOGPEN](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpen) structure that specifies the pen's style, width, and color.

## Return value

If the function succeeds, the return value is a handle that identifies a logical cosmetic pen.

If the function fails, the return value is **NULL**.

## Remarks

After an application creates a logical pen, it can select that pen into a device context by calling the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function. After a pen is selected into a device context, it can be used to draw lines and curves.

When you no longer need the pen, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

## See also

[CreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpen)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)

[LOGPEN](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpen)

[Pen Functions](https://learn.microsoft.com/windows/desktop/gdi/pen-functions)

[Pens Overview](https://learn.microsoft.com/windows/desktop/gdi/pens)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)