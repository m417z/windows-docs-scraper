## Description

This **DrvGetStandardVariable** function is obsolete.

Windows 2000 and later printer drivers should use [IPrintOemDriverUni::DrvGetStandardVariable](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvgetstandardvariable).

This function pointer prototype defines the type of the **BGetStandardVariable** member of the [DRVPROCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_drvprocs) structure.

## Parameters

### `pdevobj`

Defines the **PDEVOBJ** parameter *pdevobj*.

### `dwIndex`

Defines the **DWORD** parameter *dwIndex*.

### `pBuffer`

Defines the **PVOID** parameter *pBuffer*.

### `cbSize`

Defines the **DWORD** parameter *cbSize*.

### `pcbNeeded`

Defines the **PDWORD** parameter *pcbNeeded*.

## Return value

Returns a **BOOL** value.