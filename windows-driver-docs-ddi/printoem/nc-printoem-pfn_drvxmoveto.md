## Description

The **DrvXMoveTo** function is obsolete.

 Windows 2000 and later Unidrv plug-ins should use [IPrintOemDriverUni::DrvXMoveTo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvxmoveto).

This function pointer prototype defines the type of the **DrvXMoveTo** member of the [DRVPROCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_drvprocs) structure.

## Parameters

### `pdevobj`

Defines the **PDEVOBJ** parameter *pdevobj*.

### `x`

Defines the **INT** parameter *x*.

### `dwFlags`

Defines the **DWORD** parameter *dwFlags*.

## Return value

Returns an **INT** value.