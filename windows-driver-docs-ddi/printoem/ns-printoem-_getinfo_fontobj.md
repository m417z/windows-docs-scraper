## Description

The **GETINFO_FONTOBJ** structure is used as input to the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

## Members

### `dwSize`

Specifies the size, in bytes, of the **GETINFO_FONTOBJ** structure. Supplied by the UNIFONTOBJ_GetInfo caller.

### `pFontObj`

Pointer to an empty [FONTOBJ](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-fontobj) structure. The structure is filled in by Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function. The pointer is supplied by the UNIFONTOBJ_GetInfo caller.

## Remarks

To obtain a font's **FONTOBJ** structure contents, a rendering plug-in can supply the address of a **GETINFO_FONTOBJ** structure when calling Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

## See also

[FONTOBJ](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-fontobj)

[UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo)