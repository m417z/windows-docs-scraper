## Description

The **DrvGetDriverSetting** function is obsolete.

 Windows 2000 and later printer drivers should use [IPrintOemDriverUI::DrvGetDriverSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvgetdriversetting), [IPrintCoreUI2::DrvGetDriverSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-drvgetdriversetting) (UI plug-ins), [IPrintOemDriverUni::DrvGetDriverSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvgetdriversetting) (Unidrv plug-ins) or [IPrintOemDriverPS::DrvGetDriverSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverps-drvgetdriversetting) (Pscript plug-ins)

This function pointer type defines the type of the **DrvGetDriverSetting** member of the [OEMUIPROCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiprocs) and [DRVPROCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_drvprocs) structures.

## Parameters

### `pdriverobj`

Defines the **PVOID** parameter *pdriverobj*.

### `Feature`

Defines the **PCSTR** parameter *Feature*.

### `pOutput`

Defines the **PVOID** parameter *pOutput*.

### `cbSize`

Defines the **DWORD** parameter *cbSize*.

### `pcbNeeded` [out, optional]

Defines the **PDWORD** parameter *pcbNeeded*.

### `pdwOptionsReturned` [out, optional]

Defines the **PDWORD** parameter *pdwOptionsReturned*.

## Return value

Returns a **BOOL** value.