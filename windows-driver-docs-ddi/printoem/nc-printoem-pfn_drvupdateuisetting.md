## Description

The **DrvUpdateUISetting** function is obsolete.

 Windows 2000 and later UI plug-ins should use [IPrintOemDriverUI::DrvUpdateUISetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvupdateuisetting) or [IPrintCoreUI2::DrvUpdateUISetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-drvupdateuisetting).

This function pointer prototype defines the type of the **DrvUpdateUISetting** member of the [OEMUIPROCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiprocs) structure.

## Parameters

### `pdriverobj`

Defines the **PVOID** parameter *pdriverobj*.

### `pOptItem`

Defines the **PVOID** parameter *pOptItem*.

### `dwPreviousSelection`

Defines the **DWORD** parameter *dwPreviousSelection*.

### `dwMode`

Defines the **DWORD** parameter *dwMode*.

## Return value

Returns a **BOOL** value.