# FONTOBJ_vGetInfo function

## Description

The **FONTOBJ_vGetInfo** function retrieves information about an associated font.

## Parameters

### `pfo`

Pointer to the [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure to be queried.

### `cjSize` [in]

Specifies the size in bytes of the buffer pointed to by *pfi*.

### `pfi`

Pointer to a buffer previously allocated by the driver. GDI writes a [FONTINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontinfo) structure to this buffer.

## See also

[FONTINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontinfo)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)