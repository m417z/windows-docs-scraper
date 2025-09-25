## Description

A port monitor server DLL's **XcvOpenPort** function opens a port for configuration operations.

## Parameters

### `pszObject`

Caller-supplied pointer to a string representing the name of the port. Can be **NULL**, and most monitors do not need this parameter.

### `GrantedAccess`

Caller-supplied ACCESS_MASK structure containing the access granted to the user during a print monitor UI DLL's call to the spooler's **OpenPrinter** function. See the following Remarks section.

### `phXcv`

Caller-supplied pointer to a location to receive a function-supplied port handle.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise it should return **FALSE**.

## Remarks

Port monitor server DLLs are required to define an **XcvOpenPort** function and include its address in a [MONITOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure.

The spooler's **OpenPrinter** function (described in the Microsoft Windows SDK documentation) calls **XcvOpenPort** if the specified printer name includes either of the strings "XcvPort" or "XcvMonitor". For more information, see [AddPortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addportui).

The **XcvOpenPort** function should open the port for configuration purposes. This operation might only consist of storing the input arguments for subsequent use within [XcvDataPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvdataport). The function should return a handle to the stored information in the location pointed to by *phXcv*. This handle is returned to the caller of **OpenPrinter**, and subsequently received as an input argument to **XcvDataPort**.

The function should save the granted access mask. Later, when the server DLL's **XcvDataPort** function is called, the granted access should be compared with SERVER_ACCESS_ADMINISTER and if the comparison fails, **XcvDataPort** should return ERROR_ACCESS_DENIED.

## See also

[InitializePrintMonitor2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitor2)

[XcvClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvcloseport)

[XcvDataPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvdataport)

[AddPortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addportui)