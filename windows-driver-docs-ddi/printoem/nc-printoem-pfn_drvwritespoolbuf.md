## Description

The **DrvWriteSpoolBuf** function pointed to by this function pointer is obsolete.

 Windows 2000 and later render plug-ins should use [IPrintOemDriverUni::DrvWriteSpoolBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvwritespoolbuf) (Unidrv plug-ins), [IPrintOemDriverPS::DrvWriteSpoolBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverps-drvwritespoolbuf) (Pscript plug-ins), or [IPrintCorePS2::DrvWriteSpoolBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreps2-drvwritespoolbuf) (Pscript plug-ins).

This function pointer prototype defines the **DrvWriteSpoolBuf** member of the [DRVPROCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_drvprocs) structure.

## Parameters

### `pdevobj`

Defines the **PDEVOBJ** parameter *pdevobj*.

### `pBuffer`

Defines the **PVOID** parameter *pBuffer*.

### `cbSize`

Defines the **DWORD** parameter *cbSize*.

## Return value

Returns a **DWORD** value.