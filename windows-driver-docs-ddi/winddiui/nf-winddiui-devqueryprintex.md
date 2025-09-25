# DevQueryPrintEx function

## Description

A printer interface DLL's **DevQueryPrintEx** function determines if a specified print job is compatible with the printer's current configuration and can therefore be printed.

## Parameters

### `pDQPInfo` [in, out]

Caller-supplied pointer to a [DEVQUERYPRINT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_devqueryprint_info) structure.

## Return value

If the print job can be printed, the function should return **TRUE**; otherwise, it should return **FALSE**.

## Remarks

Printer interface DLLs must define a **DevQueryPrintEx** function. The function is called by the print spooler if the **Hold Mismatched Documents** option is checked on the **Advanced** page of the printer's property sheet. If the function returns **TRUE**, the spooler queues the print job for printing. Otherwise, the job is held, under the assumption that the printer will eventually be reconfigured so the job can print.

The received [DEVQUERYPRINT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_devqueryprint_info) structure points to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure describing the printer characteristics required by the print job. The **DevQueryPrintEx** function should first verify that the size and version members of the received DEVMODEW structure are compatible with the driver. Then it should determine if the supplied DEVMODEW contents are compatible with the current printer configuration.

If the job can be printed, the function should just return **TRUE**. If the job should be held until later, the function should return **FALSE** after supplying a displayable text string (in the buffer pointed to by the DEVQUERYPRINT_INFO structure's **pszErrorStr** member) describing the reason the job cannot be printed.

Displayable text strings should be defined as string resources in a resource file.