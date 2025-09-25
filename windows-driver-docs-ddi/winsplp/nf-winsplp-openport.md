## Description

A port monitor's **OpenPort** function opens a printer port.

## Parameters

### `pName`

Caller-supplied pointer to a string containing the name of the port to be opened.

### `pHandle`

Caller-supplied pointer to a location to receive a port handle.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise it should return **FALSE**.

## Remarks

Port monitor server DLLs are required to define an **OpenPort** function and include the function's address in a [MONITOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure.

The **OpenPort** function is called, either by a language monitor or by the print spooler, when a print queue is being connected to a port. The **OpenPort** function's primary purpose is to return a port handle that the caller can use as an input argument for subsequent calls to the port monitor's [StartDocPort](https://learn.microsoft.com/previous-versions/ff562710(v=vs.85)), [WritePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-writeport), [ReadPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-readport), [EndDocPort](https://learn.microsoft.com/previous-versions/ff548742(v=vs.85)), and [GetPrinterDataFromPort](https://learn.microsoft.com/previous-versions/ff550506(v=vs.85)) functions.

Besides returning a port handle, the **OpenPort** function can perform initialization operations that need to be taken care of before read or write operations are performed. For example, if the port supports modifiable time-out values, the **OpenPort** function should set these values.

Calls to **OpenPort** are not print job-specific. Between each call to a port monitor's **OpenPort** and [ClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-closeport) functions, there can be multiple calls to its **StartDocPort** and **EndDocPort** functions.

You can assume that after the print spooler has called **OpenPort** with a particular port name, it will not call **OpenPort** again with the same port name before calling **ClosePort**.

Print monitor functions that accept a port handle as input do not also accept a monitor handle. Therefore, the **OpenPort** function must store the received monitor handle in a location that can be referenced by the port handle. This allows the functions that accept a port handle to reference the monitor handle.

## See also

[GetPrinterDataFromPort](https://learn.microsoft.com/previous-versions/ff550506(v=vs.85))

[SetPortTimeOuts](https://learn.microsoft.com/previous-versions/ff562630(v=vs.85))

[ClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-closeport)

[StartDocPort](https://learn.microsoft.com/previous-versions/ff562710(v=vs.85))

[OpenPortEx](https://learn.microsoft.com/previous-versions/ff559596(v=vs.85))

[InitializePrintMonitor2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitor2)

[WritePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-writeport)

[EndDocPort](https://learn.microsoft.com/previous-versions/ff548742(v=vs.85))

[ReadPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-readport)