## Description

The **DrvWriteAbortBuf** function is obsolete.

Windows 2000 and later Unidrv render plug-ins should use [IPrintOemDriverUni::DrvWriteAbortBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvwriteabortbuf).

This function pointer prototype defines the type of the **DrvWriteAbortBuf** member of the [DRVPROCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_drvprocs) structure.

## Parameters

### `pdevobj`

Defines the **PDEVOBJ** parameter *pdevobj*.

### `pBuffer`

Defines the **PVOID** parameter *pBuffer*.

### `cbSize`

Defines the **DWORD** parameter *cbSize*.

### `dwWait`

Defines the **DWORD** parameter *dwWait*.

## Return value

Returns a **DWORD** value.