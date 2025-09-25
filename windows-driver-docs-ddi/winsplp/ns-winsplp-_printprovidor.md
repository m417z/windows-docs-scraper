## Description

> [!WARNING]
> Starting with Windows 10, the APIs which support third-party print providers are deprecated. Microsoft does not recommend any investment into third-party print providers. Additionally, on Windows 8 and newer products where the v4 print driver model is available, third-party print providers may not create or manage queues which use v4 print drivers.

The PRINTPROVIDOR structure is used as a parameter to a print provider's [InitializePrintProvidor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintprovidor) function. All structure member values are supplied by the provider.

## Members

### `fpOpenPrinter`

(Required.) Pointer to the provider's [OpenPrinter](https://learn.microsoft.com/windows/win32/printdocs/openprinter) function. However, at the provider level, this function must supply one of the DWORD return values listed in the following table.

| Return value | Definition |
| --- | --- |
| ROUTER_SUCCESS | The provider supports the specified printer and has opened it. |
| ROUTER_STOP_ROUTING | The provider supports the specified printer, but an error occurred and the printer could not be opened. It is assumed that no other provider can support the printer. The function must call [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror). |
| ROUTER_UNKNOWN | The provider does not support the specified printer. The function must call [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) and specify ERROR_INVALID_NAME. |

The router calls each provider until one of them returns ROUTER_SUCCESS or ROUTER_STOP_ROUTING. If the provider returns ROUTER_SUCCESS, it must also return a unique handle. For more information, see [Introduction to Print Providers](https://learn.microsoft.com/windows-hardware/drivers/print/introduction-to-print-providers).) The router first attempts to call the provider's **OpenPrinterEx** function. If that function is not supported, the router calls [OpenPrinter](https://learn.microsoft.com/windows/win32/printdocs/openprinter).

### `fpSetJob`

(Required.) Pointer to the provider's [SetJob](https://learn.microsoft.com/windows/win32/printdocs/setjob) function.

### `fpGetJob`

(Required.) Pointer to the provider's [GetJob](https://learn.microsoft.com/windows/win32/printdocs/getjob) function.

### `fpEnumJobs`

(Required.) Pointer to the provider's [EnumJobs](https://learn.microsoft.com/windows/win32/printdocs/enumjobs) function.

### `fpAddPrinter`

(Optional. Can be NULL.) Pointer to the provider's [AddPrinter](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function.

### `fpDeletePrinter`

(Optional. Can be NULL.) Pointer to the provider's [DeletePrinter](https://learn.microsoft.com/windows/win32/printdocs/deleteprinter) function.

### `fpSetPrinter`

(Required.) Pointer to the provider's [SetPrinter](https://learn.microsoft.com/windows/win32/printdocs/setprinter) function.

### `fpGetPrinter`

(Required.) Pointer to the provider's [GetPrinter](https://learn.microsoft.com/windows/win32/printdocs/getprinter) function. If you are [writing a network print provider](https://learn.microsoft.com/windows-hardware/drivers/print/writing-a-network-print-provider) and **GetPrinter** is returning a [PRINTER_INFO_2](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure, the function should supply only the **cJobs** and **Status** structure members. The [local print provider](https://learn.microsoft.com/windows-hardware/drivers/print/local-print-provider)) supplies the rest of the structure members.

### `fpEnumPrinters`

(Required.) Pointer to the provider's [EnumPrinters](https://learn.microsoft.com/windows/win32/printdocs/enumprinters) function.

### `fpAddPrinterDriver`

(Optional. Can be NULL.) Pointer to the provider's [AddPrinterDriver](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver) function. If the provider does not support the specified driver or server, it should specify ERROR_INVALID_NAME to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning **FALSE**.

### `fpEnumPrinterDrivers`

(Optional. Can be NULL.) Pointer to the provider's [EnumPrinterDrivers](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers) function. If the provider does not support the specified server, it should specify ERROR_INVALID_NAME to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning **FALSE**.

### `fpGetPrinterDriver`

(Optional. Can be NULL.) Pointer to the provider's [GetPrinterDriver](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriver) function. The router first attempts to call the provider's **GetPrinterDriverEx** function. If that function is not supported, the router calls **GetPrinterDriver**.

### `fpGetPrinterDriverDirectory`

(Optional. Can be NULL.) Pointer to the provider's [GetPrinterDriverDirectory](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriverdirectory) function. If the provider does not support the specified server, it should specify ERROR_INVALID_NAME to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning **FALSE**.

### `fpDeletePrinterDriver`

(Optional. Can be NULL.) Pointer to the provider's [DeletePrinterDriver](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterdriver) function. If the provider does not support the specified server, it should specify ERROR_INVALID_NAME to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning **FALSE**.

### `fpAddPrintProcessor`

(Optional. Can be NULL.) Pointer to the provider's [AddPrintProcessor](https://learn.microsoft.com/windows/win32/printdocs/addprintprocessor) function.

### `fpEnumPrintProcessors`

(Optional. Can be NULL.) Pointer to the provider's [EnumPrintProcessors](https://learn.microsoft.com/windows/win32/printdocs/enumprintprocessors) function.

### `fpGetPrintProcessorDirectory`

(Optional. Can be NULL.) Pointer to the provider's [GetPrintProcessorDirectory](https://learn.microsoft.com/windows/win32/printdocs/getprintprocessordirectory) function.

### `fpDeletePrintProcessor`

(Optional. Can be NULL.) Pointer to the provider's [DeletePrintProcessor](https://learn.microsoft.com/windows/win32/printdocs/deleteprintprocessor) function.

### `fpEnumPrintProcessorDatatypes`

(Optional. Can be NULL.) Pointer to the provider's [EnumPrintProcessorDatatypes](https://learn.microsoft.com/windows/win32/printdocs/enumprintprocessordatatypes) function.

### `fpStartDocPrinter`

(Required.) Pointer to the provider's [StartDocPrinter](https://learn.microsoft.com/windows/win32/printdocs/startdocprinter) function.

### `fpStartPagePrinter`

(Optional. Can be NULL.) Pointer to the provider's [StartPagePrinter](https://learn.microsoft.com/windows/win32/printdocs/startpageprinter) function.

### `fpWritePrinter`

(Required.) Pointer to the provider's [WritePrinter](https://learn.microsoft.com/windows/win32/printdocs/writeprinter) function.

### `fpEndPagePrinter`

(Optional. Can be NULL.) Pointer to the provider's [EndPagePrinter](https://learn.microsoft.com/windows/win32/printdocs/endpageprinter)function.

### `fpAbortPrinter`

(Required.) Pointer to the provider's [AbortPrinter](https://learn.microsoft.com/windows/win32/printdocs/abortprinter) function.

### `fpReadPrinter`

(Optional. Can be NULL.) Pointer to the provider's [ReadPrinter](https://learn.microsoft.com/windows/win32/printdocs/readprinter) function.

### `fpEndDocPrinter`

(Required.) Pointer to the provider's [EndDocPrinter](https://learn.microsoft.com/windows/win32/printdocs/enddocprinter) function.

### `fpAddJob`

(Required.) Pointer to the provider's [AddJob](https://learn.microsoft.com/windows/win32/printdocs/addjob) function.

### `fpScheduleJob`

(Required.) Pointer to the provider's [ScheduleJob](https://learn.microsoft.com/windows/win32/printdocs/schedulejob) function.

### `fpGetPrinterData`

(Optional. Can be NULL.) Pointer to the provider's [GetPrinterData](https://learn.microsoft.com/windows/win32/printdocs/getprinterdata) function.

### `fpSetPrinterData`

(Optional. Can be NULL.) Pointer to the provider's [SetPrinterData](https://learn.microsoft.com/windows/win32/printdocs/setprinterdata) function.

### `fpWaitForPrinterChange`

Obsolete. Must be NULL.

### `fpClosePrinter`

(Required.) Pointer to the provider's [ClosePrinter](https://learn.microsoft.com/windows/win32/printdocs/closeprinter) function. If a printer change notification object has been created, then the router calls the provider's FindClosePrinterChangeNotification function before calling ClosePrinter.

### `fpAddForm`

(Optional. Can be NULL.) Pointer to the provider's [AddForm](https://learn.microsoft.com/windows/win32/printdocs/addform) function.

### `fpDeleteForm`

(Optional. Can be NULL.) Pointer to the provider's [DeleteForm](https://learn.microsoft.com/windows/win32/printdocs/deleteform) function.

### `fpGetForm`

(Optional. Can be NULL.) Pointer to the provider's [GetForm](https://learn.microsoft.com/windows/win32/printdocs/getform) function.

### `fpSetForm`

(Optional. Can be NULL.) Pointer to the provider's [SetForm](https://learn.microsoft.com/windows/win32/printdocs/setform) function.

### `fpEnumForms`

(Optional. Can be NULL.) Pointer to the provider's [EnumForms](https://learn.microsoft.com/windows/win32/printdocs/enumforms) function.

### `fpEnumMonitors`

(Optional. Can be NULL.) Pointer to the provider's [EnumMonitors](https://learn.microsoft.com/windows/win32/printdocs/enummonitors) function, which is described in the Windows SDK documentation. However, at the provider level this function must supply one of the DWORD return values listed in the following table.

| Return value | Definition |
| --- | --- |
| ROUTER_SUCCESS | The provider has enumerated the monitors on the specified server. |
| ROUTER_STOP_ROUTING | The provider has enumerated the monitors on the specified server, and the router should not call other providers. |
| ROUTER_UNKNOWN | The provider does not support the specified server. |

### `fpEnumPorts`

| Return value | Definition |
| --- | --- |
| ROUTER_SUCCESS | The provider has enumerated the ports on the specified server. |
| ROUTER_STOP_ROUTING | The provider has enumerated the ports on the specified server, and the router should not call other providers. |
| ROUTER_UNKNOWN | The provider does not support the specified server. |

### `fpAddPort`

(Optional. Can be NULL.) Pointer to the provider's [AddPort](https://learn.microsoft.com/windows/win32/printdocs/addport) function. If the provider does not support the specified port, it must supply ERROR_NOT_SUPPORTED to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning **FALSE**.

### `fpConfigurePort`

(Required.) Pointer to the provider's [ConfigurePort](https://learn.microsoft.com/windows/win32/printdocs/configureport) function. If the function supplies ERROR_NOT_SUPPORTED, ERROR_INVALID_NAME, or ERROR_UNKNOWN_PORT to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror), the router will attempt to call another provider.

### `fpDeletePort`

(Required.) Pointer to the provider's [DeletePort](https://learn.microsoft.com/windows/win32/printdocs/deleteport) function. If the provider does not support the specified port, it must supply ERROR_NOT_SUPPORTED to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning **FALSE**.

### `fpCreatePrinterIC`

For internal use only. Must be NULL.

### `fpPlayGdiScriptOnPrinterIC`

For internal use only. Must be NULL.

### `fpDeletePrinterIC`

For internal use only. Must be NULL.

### `fpAddPrinterConnection`

(Optional. Can be NULL.) Pointer to the provider's [AddPrinterConnection](https://learn.microsoft.com/windows/win32/printdocs/addprinterconnection) function.

### `fpDeletePrinterConnection`

(Optional. Can be NULL.) Pointer to the provider's [DeletePrinterConnection](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterconnection) function.

### `fpPrinterMessageBox`

Not used. Must be NULL.

### `fpAddMonitor`

(Optional. Can be NULL.) Pointer to the provider's [AddMonitor](https://learn.microsoft.com/windows/win32/printdocs/addmonitor) function. If the provider does not support the specified monitor, it must supply ERROR_INVALID_NAME to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning **FALSE**.

### `fpDeleteMonitor`

(Optional. Can be NULL.) Pointer to the provider's [DeleteMonitor](https://learn.microsoft.com/windows/win32/printdocs/addmonitor) function. If the provider does not support the specified monitor, it must supply ERROR_INVALID_NAME to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning **FALSE**.

### `fpResetPrinter`

(Optional. Can be NULL.) Pointer to the provider's [ResetPrinter](https://learn.microsoft.com/windows/win32/printdocs/resetprinter) function.

### `fpGetPrinterDriverEx`

(Optional. Can be NULL.) Pointer to the provider's **GetPrinterDriverEx** function. If **GetPrinterDriverEx** is not supported, the router attempts to call [GetPrinterDriver](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriver).

### `fpFindFirstPrinterChangeNotification`

(Optional. Can be NULL.) Pointer to the provider's [FindFirstPrinterChangeNotification](https://learn.microsoft.com/windows/win32/printdocs/findfirstprinterchangenotification) function.

### `fpFindClosePrinterChangeNotification`

(Optional. Can be NULL.) Pointer to the provider's [FindClosePrinterChangeNotification](https://learn.microsoft.com/windows/win32/printdocs/findcloseprinterchangenotification) function.

### `fpAddPortEx`

(Optional. Can be NULL.) Pointer to the provider's **AddPortEx** function. If the provider does not support the specified port, it must supply ERROR_NOT_SUPPORTED to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning **FALSE**.

### `fpShutDown`

For internal use only. Must be NULL.

### `fpRefreshPrinterChangeNotification`

(Optional. Can be NULL.) Pointer to the provider's [RefreshPrinterChangeNotification](https://learn.microsoft.com/previous-versions/ff561930(v=vs.85)) function.

### `fpOpenPrinterEx`

For internal use only. Must be NULL.

### `fpAddPrinterEx`

For internal use only. Must be NULL.

### `fpSetPort`

(Optional. Can be NULL.) Pointer to the provider's [SetPort](https://learn.microsoft.com/windows/win32/printdocs/setport) function. If the function supplies ERROR_NOT_SUPPORTED, ERROR_INVALID_NAME, or ERROR_UNKNOWN_PORT to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror), the router will attempt to call another provider.

### `fpEnumPrinterData`

(Optional. Can be NULL.) Pointer to the provider's [EnumPrinterData](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdata) function.

### `fpDeletePrinterData`

(Optional. Can be NULL.) Pointer to the provider's [DeletePrinterData](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterdata) function.

### `fpClusterSplOpen`

For internal use only. Must be NULL.

### `fpClusterSplClose`

For internal use only. Must be NULL.

### `fpClusterSplIsAlive`

For internal use only. Must be NULL.

### `fpSetPrinterDataEx`

(Optional. Can be NULL.) Pointer to the provider's [SetPrinterDataEx](https://learn.microsoft.com/windows/win32/printdocs/setprinterdataex) function.

### `fpGetPrinterDataEx`

(Optional. Can be NULL.) Pointer to the provider's [GetPrinterDataEx](https://learn.microsoft.com/windows/win32/printdocs/getprinterdataex) function.

### `fpEnumPrinterDataEx`

(Optional. Can be NULL.) Pointer to the provider's [EnumPrinterDataEx](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdataex) function.

### `fpEnumPrinterKey`

(Optional. Can be NULL.) Pointer to the provider's [EnumPrinterKey](https://learn.microsoft.com/windows/win32/printdocs/enumprinterkey) function.

### `fpDeletePrinterDataEx`

(Optional. Can be NULL.) Pointer to the provider's [DeletePrinterDataEx](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterdataex) function.

### `fpDeletePrinterKey`

(Optional. Can be NULL.) Pointer to the provider's [DeletePrinterKey](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterkey) function.

### `fpSeekPrinter`

For internal use only. Must be NULL.

### `fpDeletePrinterDriverEx`

(Optional. Can be NULL.) Pointer to the provider's [DeletePrinterDriverEx](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterdriverex) function. If the provider does not support the specified server, it should specify ERROR_INVALID_NAME to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning **FALSE**.

### `fpAddPerMachineConnection`

For internal use only. Must be NULL.

### `fpDeletePerMachineConnection`

For internal use only. Must be NULL.

### `fpEnumPerMachineConnections`

For internal use only. Must be NULL.

### `fpXcvData`

(Optional. Can be NULL.) Pointer to the provider's [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)) function.

### `fpAddPrinterDriverEx`

(Optional. Can be NULL.) Pointer to the provider's [AddPrinterDriverEx](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex) function. If the provider does not support the specified server, it should specify ERROR_INVALID_NAME to [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) before returning **FALSE**.

### `fpSplReadPrinter`

For internal use only. Must be NULL.

### `fpDriverUnloadComplete`

For internal use only. Must be NULL.

### `fpGetSpoolFileInfo`

For internal use only. Must be NULL.

### `fpCommitSpoolData`

For internal use only. Must be NULL.

### `fpCloseSpoolFileHandle`

For internal use only. Must be NULL.

### `fpFlushPrinter`

For internal use only. Must be NULL.

### `fpSendRecvBidiData`

(Optional. Can be NULL.) Pointer to the provider's [SendRecvBidiData](https://learn.microsoft.com/previous-versions//ff562068(v=vs.85)) function. If this parameter is NULL, it means that the provider does not support bidi communication.

### `fpAddPrinterConnection2`

For internal use only. Must be NULL.

### `fpGetPrintClassObject`

For internal use only. Must be NULL.

### `fpReportJobProcessingProgress`

For internal use only. Must be NULL.

### `fpEnumAndLogProvidorObjects`

For internal use only. Must be NULL.

### `fpInternalGetPrinterDriver`

For internal use only. Must be NULL.

### `fpFindCompatibleDriver`

For internal use only. Must be NULL.

### `fpGetJobNamedPropertyValue`

For internal use only. Must be NULL.

### `fpSetJobNamedProperty`

For internal use only. Must be NULL.

### `fpDeleteJobNamedProperty`

For internal use only. Must be NULL.

### `fpEnumJobNamedProperties`

For internal use only. Must be NULL.

### `fpPowerEvent`

For internal use only. Must be NULL.

### `fpGetUserPropertyBag`

For internal use only. Must be NULL.

### `fpCanShutdown`

For internal use only. Must be NULL.

### `fpLogJobInfoForBranchOffice`

For internal use only. Must be NULL.

### `fpRegeneratePrintDeviceCapabilities`

For internal use only. Must be NULL.

### `fpInstallPrinterDriverPackageFromConnection`

For internal use only. Must be NULL.

### `fpPrintSupportOperation`

For internal use only. Must be NULL.

### `fpIppCreateJobOnPrinter`

For internal use only. Must be NULL.

### `fpIppGetJobAttributes`

For internal use only. Must be NULL.

### `fpIppSetJobAttributes`

For internal use only. Must be NULL.

### `fpIppGetPrinterAttributes`

For internal use only. Must be NULL.

### `fpIppSetPrinterAttributes`

For internal use only. Must be NULL.

### `fpIppCreateJobOnPrinterWithAttributes`

For internal use only. Must be NULL.

## Remarks

Function pointers are listed in the order they are specified within the PRINTPROVIDOR structure. To see function descriptions grouped by related capabilities, see [Functions Defined by Print Providers](https://learn.microsoft.com/windows-hardware/drivers/print/functions-defined-by-print-providers).

## See also

[FindFirstPrinterChangeNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/nf-winspool-findfirstprinterchangenotification)

[InitializePrintProvidor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintprovidor)

[RefreshPrinterChangeNotification](https://learn.microsoft.com/previous-versions/ff561930(v=vs.85))

[SendRecvBidiData](https://learn.microsoft.com/previous-versions//ff562068(v=vs.85))

[XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85))