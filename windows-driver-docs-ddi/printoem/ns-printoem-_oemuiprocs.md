## Description

The **OEMUIPROCS** structure is obsolete.

The **OEMUIPROCS** structure contains the address of the [DrvGetDriverSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfn_drvgetdriversetting) and [DrvUpdateUISetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfn_drvupdateuisetting) functions that are exported by Microsoft printer drivers.

## Members

### `DrvGetDriverSetting`

Pointer to the printer driver's **DrvGetDriverSetting** function. (To obtain this function's address in kernel mode, see [DRVPROCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_drvprocs).

### `DrvUpdateUISetting`

Pointer to the printer driver's **DrvUpdateUISetting** function.

## Remarks

[DrvGetDriverSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfn_drvgetdriversetting) and [DrvUpdateUISetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfn_drvupdateuisetting) have been superseded by COM-based interfaces.

The **OEMUIPROCS** structure's address is contained in an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.