# RouterAllocPrinterNotifyInfo function

## Description

The print spooler's `RouterAllocPrinterNotifyInfo` function allocates a PRINTER_NOTIFY_INFO structure and an array of PRINTER_NOTIFY_INFO_DATA structures. (These structures are described in the Microsoft Windows SDK documentation.)

## Parameters

### `cPrinterNotifyInfoData`

Caller-supplied number specifying size of the PRINTER_NOTIFY_INFO_DATA structure array to be allocated.

## Return value

The function returns a pointer to the allocated PRINTER_NOTIFY_INFO structure.

## Remarks

Print providers should call `RouterAllocPrinterNotifyInfo` to allocate the PRINTER_NOTIFY_INFO structure and the PRINTER_NOTIFY_INFO_DATA structure array that the provider's [RefreshPrinterChangeNotification](https://learn.microsoft.com/previous-versions/ff561930(v=vs.85)) function must supply.

The `RouterAllocPrinterNotifyInfo` function initializes the PRINTER_NOTIFY_INFO structure's **Version** member to the current version of the spooler's notification implementation. It initializes the structure's **Flags** and **Count** members to zero, regardless of the number specified for *cPrinterNotifyInfoData*.

Print providers should call [AppendPrinterNotifyInfoData](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-appendprinternotifyinfodata) to fill in members of the PRINTER_NOTIFY_INFO_DATA structure array.

If `RefreshPrinterChangeNotification` executes successfully and returns the allocated structures to the caller, you should assume that the caller will deallocate structure memory. However, if `RefreshPrinterChangeNotification` encounters an error it should call [RouterFreePrinterNotifyInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerfreeprinternotifyinfo) to deallocate the memory.

For additional information, see [Supporting Printer Change Notifications](https://learn.microsoft.com/windows-hardware/drivers/print/supporting-printer-change-notifications).

## See also

[AppendPrinterNotifyInfoData](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-appendprinternotifyinfodata)

[RefreshPrinterChangeNotification](https://learn.microsoft.com/previous-versions/ff561930(v=vs.85))

[RouterFreePrinterNotifyInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerfreeprinternotifyinfo)