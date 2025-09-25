## Description

The print spooler's **PartialReplyPrinterChangeNotification** function allows a print provider to update the spooler's database of printer changes associated with a notification handle.

## Parameters

### `hPrinter`

Caller-supplied handle. This handle must have been previously received as the *hNotify* input to the print provider's [FindFirstPrinterChangeNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/nf-winspool-findfirstprinterchangenotification) function.

### `pDataSrc`

Caller-supplied pointer to a PRINTER_NOTIFY_INFO_DATA structure (described in the Microsoft Windows SDK documentation). Can be **NULL**. For more information, see the following Remarks section.

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise the function returns **FALSE**. The caller can obtain an error code by calling **GetLastError**.

## Remarks

For the specified notification handle, the spooler's **PartialReplyPrinterChangeNotification** function adds the contents of the specified PRINTER_NOTIFY_INFO_DATA structure to the array within the spooler's stored PRINTER_NOTIFY_INFO structure. (These structures are described in the Windows SDK documentation.)

Calling **PartialReplyPrinterChangeNotification** does not cause the spooler to notify the application that changes have occurred. If the print provider's [FindFirstPrinterChangeNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/nf-winspool-findfirstprinterchangenotification) function did not set the PRINTER_NOTIFY_STATUS_POLL flag, the provider must call [ReplyPrinterChangeNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-replyprinterchangenotification) to cause the application to be notified.

If *pInfoDataSrc* is **NULL**, all stored information associated with the specified handle is deleted from the spooler. The function accomplishes this deletion by freeing all buffers associated with *pBuf* members of PRINTER_NOTIFY_INFO_DATA structures belonging to the specified handle. The function then sets the PRINTER_NOTIFY_INFO_DISCARDED flag in the stored PRINTER_NOTIFY_INFO structure.

For additional information, see [Supporting Printer Change Notifications](https://learn.microsoft.com/windows-hardware/drivers/print/supporting-printer-change-notifications).

## See also

[FindFirstPrinterChangeNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/nf-winspool-findfirstprinterchangenotification)

[ReplyPrinterChangeNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-replyprinterchangenotification)