## Description

A Point and Print DLL's **SpoolerCopyFileEvent** function receives notifications of events associated with copying print queue-associated files to a print client, when the client connects to a print server.

## Parameters

### `pszPrinterName` [in]

Caller-supplied pointer to a string representing the printer name.

### `pszKey` [in]

Caller-supplied pointer to a string representing a subkey under the printer's **CopyFiles** registry key. This subkey identifies the component to which the Point and Print DLL belongs.

### `dwCopyFileEvent` [in]

Caller-supplied flag that identifies the event being reported. Valid flag values are contained in the following table.

| Flag | When Received | Where Received |
|---|---|---|
| COPYFILE_EVENT_ADD_PRINTER_CONNECTION | After a client application has called **AddPrinterConnection**. | Client copy of `SpoolerCopyFileEvent`. The calling context is the client application. |
| COPYFILE_EVENT_DELETE_PRINTER | After a call to **DeletePrinter** has been made. | Client copy of `SpoolerCopyFileEvent`. The calling context is the client's spooler. |
| COPYFILE_EVENT_DELETE_PRINTER_CONNECTION | After a client application has called **DeletePrinterConnection**. | Client copy of `SpoolerCopyFileEvent`. The calling context is the client application. |
| COPYFILE_EVENT_FILES_CHANGED | After the client has downloaded the files specified under the **pszKey** subkey of the printer's **CopyFiles** registry key. | Client copy of `SpoolerCopyFileEvent`. The calling context is the client's spooler. |
| COPYFILE_EVENT_SET_PRINTER_DATAEX | After a call to **SetPrinterDataEx** has been processed on the server. | Server copy of `SpoolerCopyFileEvent`. The calling context is the client application, by impersonation. |

## Return value

If the function encounters errors, the function should return **FALSE**. Otherwise, it should return **TRUE**.

## Remarks

All [Point and Print DLLs](https://learn.microsoft.com/windows-hardware/drivers/print/point-and-print-dlls) must export a **SpoolerCopyFileEvent** function, which is called by the print spooler. Its purpose is to allow a Point and Print DLL to be notified of events related to the downloading of print queue-associated files, from a print server to a client system, when an application on the client connects to the server. For a complete description of the steps involved in creating a Point and Print connection, see [Supporting Point and Print](https://learn.microsoft.com/windows-hardware/drivers/print/supporting-point-and-print).

A Point and Print DLL executes on both the server and the client. The **SpoolerCopyFileEvent** function can determine where it is executing by reading the contents of *dwCopyFileEvent*, which supplies a flag indicating the event. The function should process the event and return. If no processing is necessary, the function should just return **TRUE**.

If *dwCopyFileEvent* is COPYFILE_EVENT_ADD_PRINTER_CONNECTION or COPYFILE_EVENT_ADD_PRINTER_CONNECTION, the string supplied by *pszPrinterName* includes the server name.

## See also

[GenerateCopyFilePaths](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-generatecopyfilepaths)