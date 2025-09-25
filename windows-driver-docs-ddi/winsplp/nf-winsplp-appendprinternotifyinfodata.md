## Description

The print spooler's **AppendPrinterNotifyInfoData** function adds the contents of a specified PRINTER_NOTIFY_INFO_DATA structure to a specified PRINTER_NOTIFY_INFO structure.

## Parameters

### `pInfoDest` [in]

Caller-supplied pointer to a **PRINTER_NOTIFY_INFO** structure.

### `pDataSrc`

Caller-supplied pointer to a **PRINTER_NOTIFY_INFO_DATA** structure.

### `fdwFlags`

Caller-supplied flags. The following flag is defined.

**PRINTER_NOTIFY_INFO_DATA_COMPACT**
If set, the function examines the **Type**, **Field**, and **Id** members of the supplied **PRINTER_NOTIFY_INFO_DATA** structure. If they all match an existing element of the **PRINTER_NOTIFY_INFO_DATA** structure array, the existing element is overwritten with the supplied element. If a match is not found, the function adds the specified structure to the end of the array.

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise, the function returns **FALSE**. The caller can obtain an error code by calling *GetLastError*.

## Remarks

A print provider's [RefreshPrinterChangeNotification](https://learn.microsoft.com/previous-versions/ff561930(v=vs.85)) function should call **AppendPrinterNotifyInfoData** as often as necessary to populate a **PRINTER_NOTIFY_INFO_DATA** structure array, after first calling [RouterAllocPrinterNotifyInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerallocprinternotifyinfo) to allocate storage for the array and its associated PRINTER_NOTIFY_INFO structure.

Based on whether the PRINTER_NOTIFY_INFO_DATA_COMPACT flag is set, the function either appends the specified **PRINTER_NOTIFY_INFO_DATA** structure to the end of the structure array or overwrites an existing array element. If the structure is appended, the function increments the **PRINTER_NOTIFY_INFO** structure's **Count** member.

If **AppendPrinterNotifyInfoData** detects that the PRINTER_NOTIFY_INFO_DISCARDED flag is set in the specified **PRINTER_NOTIFY_INFO** structure, the function clears all PRINTER_NOTIFY_INFO_DATA structures and sets the error code to ERROR_OUT_OF_STRUCTURES.

If **NULL** is specified for *pInfoDataSrc*, **AppendPrinterNotifyInfoData** sets the PRINTER_NOTIFY_INFO_DISCARDED flag in the specified **PRINTER_NOTIFY_INFO** structure, clears all **PRINTER_NOTIFY_INFO_DATA** structures, and sets the error code to ERROR_OUT_OF_STRUCTURES.

(For more information about the PRINTER_NOTIFY_INFO_DISCARDED flag, see the description of FindNextPrinterChangeNotification in the Windows SDK documentation.)

For additional information, see [Supporting Printer Change Notifications](https://learn.microsoft.com/windows-hardware/drivers/print/supporting-printer-change-notifications).

## See also

[RefreshPrinterChangeNotification](https://learn.microsoft.com/previous-versions/ff561930(v=vs.85))

[RouterAllocPrinterNotifyInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerallocprinternotifyinfo)