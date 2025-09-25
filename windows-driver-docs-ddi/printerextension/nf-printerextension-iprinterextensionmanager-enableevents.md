## Description

The EnableEvents method allows events to be generated for the specified printer driver until [DisableEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterextensionmanager-disableevents) is called.

## Parameters

### `printerDriverId` [in]

The GUID representing the specified driver for which to enable events. This GUID is specified in the INF file, and is also specified by the manifest file directive 'PrinterDriverID'.

## Return value

This method returns an **HRESULT** value.

The printer extension should call this method when it is launched so that driver events are generated for it to consume.

## Remarks

In the case of a driver event like, for example, Print Preferences or Printer Notifications, the app is expected to call **EnableEvents**. But if the app doesn't call **EnableEvents** within 5 seconds, the print system assumes that a UI was called but it's not being responsive so a standard UI is displayed instead.

## See also

[IPrinterExtensionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterextensionmanager)