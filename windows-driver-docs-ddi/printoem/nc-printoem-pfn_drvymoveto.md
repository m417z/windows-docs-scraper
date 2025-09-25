## Description

The **DrvYMoveTo** function is obsolete.

Windows 2000 and later Unidrv plug-ins should use [IPrintOemDriverUni::DrvYMoveTo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvymoveto).

This function pointer prototype defines the type of the **DrvYMoveTo** member of the [DRVPROCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_drvprocs) structure.

## Parameters

### `pdevobj`

Defines the **PDEVOBJ** parameter *pdevobj*.

### `y`

Defines the **INT** parameter *y*.

### `dwFlags`

Defines the **DWORD** parameter *dwFlags*.

## Return value

Returns an **INT** value.