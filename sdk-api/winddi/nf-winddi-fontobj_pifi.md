# FONTOBJ_pifi function

## Description

The **FONTOBJ_pifi** function retrieves the pointer to the [IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics) structure associated with a specified font.

## Parameters

### `pfo`

Pointer to the [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure for which the associated IFIMETRICS structure is to be retrieved.

## Return value

The return value is a pointer to the IFIMETRICS structure associated with the specified font if the function is successful. Otherwise, it is **NULL**.

## See also

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)

[IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics)