# _MONITORUI structure

## Description

The **MONITORUI** structure contains pointers to the functions within a port monitor UI DLL that the print spooler calls.

## Members

### `dwMonitorUISize`

Size, in bytes, of the **MONITORUI** structure.

### `pfnAddPortUI`

Pointer to the port monitor UI DLL [AddPortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addportui) function that adds a printer port, then obtains port configuration information from the user and sends it to the port monitor server DLL.

### `pfnConfigurePortUI`

Pointer to the port monitor UI DLL [ConfigurePortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-configureportui) function that obtains port configuration information from the user and sends it to the port monitor server DLL.

### `pfnDeletePortUI`

Pointer to the port monitor UI DLL [DeletePortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-deleteportui) function that deletes a printer port.

## Remarks

All structure members must be initialized by the port monitor UI DLL. The structure's address is passed to the print spooler as the return value for the [InitializePrintMonitorUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitorui) function.

## See also

[InitializePrintMonitorUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitorui)