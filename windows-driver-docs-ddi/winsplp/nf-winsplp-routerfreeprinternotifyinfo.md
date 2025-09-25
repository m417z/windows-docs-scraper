# RouterFreePrinterNotifyInfo function

## Description

The print spooler's `RouterFreePrinterNotifyInfo` function deallocates a specified PRINTER_NOTIFY_INFO structure and its associated PRINTER_NOTIFY_INFO_DATA structure array. (These structures are described in the Microsoft Windows SDK documentation.)

## Parameters

### `pInfo` [in, optional]

Caller-supplied pointer to a PRINTER_NOTIFY_INFO structure (described in the Windows SDK documentation).

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise the function returns **FALSE**.

## Remarks

A print provider's [RefreshPrinterChangeNotification](https://learn.microsoft.com/previous-versions/ff561930(v=vs.85)) function should call `RouterFreePrinterNotifyInfo` to deallocate structures previously allocated by [RouterAllocPrinterNotifyInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerallocprinternotifyinfo), but only if **RefreshPrinterChangeNotification** encounters an error. If **RefreshPrinterChangeNotification** succeeds, you should assume that the client application will deallocate the structures.

Besides deallocating the specified PRINTER_NOTIFY_INFO structure and its associated PRINTER_NOTIFY_INFO_DATA structure array, the function also deallocates buffer space pointed to by *pBuf* in any element of the PRINTER_NOTIFY_INFO_DATA structure array.

For additional information, see [Supporting Printer Change Notifications](https://learn.microsoft.com/windows-hardware/drivers/print/supporting-printer-change-notifications).

## See also

[RefreshPrinterChangeNotification](https://learn.microsoft.com/previous-versions/ff561930(v=vs.85))

[RouterAllocPrinterNotifyInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerallocprinternotifyinfo)