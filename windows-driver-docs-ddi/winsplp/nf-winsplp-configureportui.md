# ConfigurePortUI function

## Description

A port monitor UI DLL's **ConfigurePortUI** function obtains port configuration information from the user and sends it to the port monitor server DLL.

## Parameters

### `pszServer` [in, optional]

Caller-supplied pointer to a string representing a server name, or **NULL** if the printer is local. (The port monitor can ignore this parameter.)

### `hWnd` [in]

Caller-supplied handle of the window that should be used as the parent for dialog boxes. If **NULL**, no dialog boxes should be displayed.

### `pszPortName` [in]

Caller-supplied pointer to a string representing the name of the port to be configured.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise it should return **FALSE**. If the operation is unsupported, or is canceled by the user (either by selecting CANCEL or by selecting OK without changing configuration parameters), the function should call SetLastError(ERROR_CANCELLED), then return **FALSE**.

## Syntax

```cpp
BOOL WINAPI pfnConfigurePortUI(
  _In_opt_ PCWSTR pszServer,
  _In_     HWND   hWnd,
  _In_     PCWSTR pszPortName
);
```

## Remarks

Port monitor UI DLLs are required to define a **ConfigurePortUI** function and include the function's address in a [MONITORUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorui) structure.

The client's spooler calls **ConfigurePortUI** from within its [ConfigurePort](https://learn.microsoft.com/previous-versions/ff546286(v=vs.85)) function (described in the Microsoft Windows SDK documentation). The arguments received by **ConfigurePortUI** are the arguments received by **ConfigurePort**.

The function should perform the following operations:

1. Call OpenPrinter, specifying a printer name with the following format:

   \\*ServerName*\,XcvPort*PortName*

   where *ServerName* and *PortName* are the server and port names received as **ConfigurePortUI** function arguments.

   The call to OpenPrinter requires a PRINTER_DEFAULTS structure, which is described in the Windows SDK documentation. The structure's **DesiredAccess** member must be set to SERVER_ACCESS_ADMINISTER. Its **pDatatype** and **pDevMode** members can be **NULL**.

   This call causes the print monitor server DLL's [XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport) function to be called.
2. Obtain port configuration parameters from the user by displaying a dialog box.
3. Call [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)) one or more times, specifying customized data name strings, to send each configuration parameter to the server DLL. Each **XcvData** call causes the server's [XcvDataPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvdataport) function to be called.
4. Call ClosePrinter, specifying the handle received from OpenPrinter. This causes the server DLL's [XcvClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvcloseport) function to be called.

## See also

[XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport)

[XcvClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvcloseport)

[XcvDataPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvdataport)

[XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85))