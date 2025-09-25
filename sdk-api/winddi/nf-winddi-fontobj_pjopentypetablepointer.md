# FONTOBJ_pjOpenTypeTablePointer function

## Description

The **FONTOBJ_pjOpenTypeTablePointer** function returns a pointer to a view of an OpenType table.

## Parameters

### `pfo`

Pointer to the [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) that identifies the font whose OpenType table is being queried.

### `ulTag`

Identifies the font table whose pointer is to be returned.

### `pcjTable`

Pointer to the location in which GDI returns the size in bytes of the table being queried.

## Return value

**FONTOBJ_pjOpenTypeTablePointer** returns a pointer to a view of the OpenType table. A return value of **NULL** indicates that the requested table is not present in this font.

## Remarks

**FONTOBJ_pjOpenTypeTablePointer** can be called by printer drivers that can download OpenType fonts or parts of OpenType fonts to the printer.

The pointer to a table returned by **FONTOBJ_pjOpenTypeTablePointer** is guaranteed to be valid only during the scope of the [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout) call to which *pfo* is passed as a parameter.

## See also

[DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)