# DeletePortUI function

## Description

A port monitor UI DLL's **DeletePortUI** function deletes a printer port.

## Parameters

### `pszServer` [in, optional]

Caller-supplied pointer to a string representing a server name, or **NULL** if the printer is local. (The port monitor can ignore this parameter.)

### `hWnd` [in]

Caller-supplied handle of the window that should be used as the parent for dialog boxes. If **NULL**, no dialog boxes should be displayed.

### `pszPortName` [in]

Caller-supplied pointer to a string representing the name of the port to be deleted.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise it should return **FALSE**. If the operation is canceled by the user or is unsupported, the function should call SetLastError(ERROR_CANCELLED), then return **FALSE**.

## Remarks

Port monitor UI DLLs are required to define a **DeletePortUI** function and include the function's address in a [MONITORUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorui) structure.

The spooler calls **DeletePortUI** from within its **DeletePort** function. The arguments received by **DeletePortUI** are the arguments received by **DeletePort**. (The **DeletePort** function is described in the Microsoft Windows SDK documentation.)

The function should perform the following operations:

1. Call **OpenPrinter**, specifying a printer name with the following format:

   **\\***ServerName***\,XcvPort***PortName*

   where *ServerName* and *PortName* are the server and port names received as **DeletePortUI** function arguments.

   The call to **OpenPrinter** requires a PRINTER_DEFAULTS structure, which is described in the Windows SDK documentation. The structure's **DesiredAccess** member must be set to SERVER_ACCESS_ADMINISTER. Its **pDatatype** and **pDevMode** members can be **NULL**.

   This call causes the print monitor server DLL's [XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport) function to be called.
2. Call [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)), specifying the following input arguments:
   * The handle received from **OpenPrinter**
   * The port name received as a function argument
   * A data name string of "DeletePort"

   This call causes the server DLL's [XcvClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvcloseport) function to be called.
3. If user interaction is required, obtain information from the user by displaying a dialog box and then call [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)), specifying customized data name strings, to send the information to the server DLL. The **XcvData** call causes the server's [XcvDataPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvdataport) function to be called.
4. Call **ClosePrinter**, specifying the handle received from **OpenPrinter**. This causes the server DLL's [XcvClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvcloseport) function to be called.

## See also

[XcvClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvcloseport)

[XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85))

[XcvDataPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvdataport)

[XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport)