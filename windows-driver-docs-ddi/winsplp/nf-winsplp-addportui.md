## Description

A port monitor UI DLL's **AddPortUI** function adds a printer port, then obtains port configuration information from the user and sends it to the port monitor server DLL.

## Parameters

### `pszServer` [in, optional]

Caller-supplied pointer to a string representing a server name, or **NULL** if the printer is local.

### `hWnd` [in]

Caller-supplied handle of the window that should be used as the parent for dialog boxes. If **NULL**, no dialog boxes should be displayed.

### `pszMonitorNameIn`

Caller-supplied pointer to a string representing the name of the monitor. Can be **NULL**.

### `ppszPortNameOut` [out, optional]

Caller-supplied pointer to a location to receive a port name string. Can be **NULL**, in which case a name is not returned.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise SetLastError should be called to specify an error code, and the function should return **FALSE**. If the operation is canceled by the user or is unsupported, the function should call SetLastError(ERROR_CANCELLED), then return **FALSE**.

## Remarks

Port monitor UI DLLs are required to define an **AddPortUI** function and include the function's address in a [MONITORUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorui) structure.

The spooler calls **AddPortUI** from within its AddPort function. The first three arguments received by **AddPortUI** are the arguments received by AddPort. (The AddPort function is described in the Microsoft Windows SDK documentation.)

The function should perform the following operations:

1. Call OpenPrinter, specifying a printer name with the following format:

 \\\\*ServerName*\\,XcvMonitor*MonitorName*

 where *ServerName* and *MonitorName* are the server and monitor names received as **AddPortUI** function arguments.

 The call to OpenPrinter requires a PRINTER_DEFAULTS structure, which is described in the Windows SDK documentation. The structure's **DesiredAccess** member must be set to SERVER_ACCESS_ADMINISTER. Its **pDatatype** and **pDevMode** members can be **NULL**.

 This call causes the print monitor server DLL's [XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport) function to be called.

1. Obtain a port name from the user by displaying a dialog box.

1. Call [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)), specifying the following input arguments:

    - The handle received from OpenPrinter

    - The port name received from the user

    - A customized data name string, such as "PortExists"

 This call causes the server DLL's [XcvDataPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvdataport) function to be called. The **XcvDataPort** function should return a value that indicates whether the specified port name has already been used. If it has, the UI DLL should request another name from the user and call [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)) again.

1. After a valid new port name has been received, call [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)) again, this time specifying the following input arguments

    - The handle received from OpenPrinter

    - The validated port name received from the user

    - A data name string of "AddPort"

 This call causes the server DLL's [XcvDataPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvdataport) function to be called again.

1. Obtain port configuration parameters from the user by displaying a dialog box.

1. Call [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)) one or more times, specifying customized data name strings, to send each configuration parameter to the server DLL. Each **XcvData** call causes the server's [XcvDataPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvdataport) function to be called.

1. Call ClosePrinter, specifying the handle received from OpenPrinter. This causes the server DLL's [XcvClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvcloseport) function to be called.

## See also

[MONITORUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorui)

[XcvClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvcloseport)

[XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85))

[XcvDataPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvdataport)

[XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport)