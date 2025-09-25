## Description

> [!WARNING]
> Starting with Windows 10, the APIs which support third-party print providers are deprecated. Microsoft does not recommend any investment into third-party print providers. Additionally, on Windows 8 and newer products where the v4 print driver model is available, third-party print providers may not create or manage queues which use v4 print drivers.

A print provider's **FindFirstPrinterChangeNotification** function informs the provider that an application has requested notification when a specified set of events occur on a specified print queue.

## Parameters

### `hPrinter`

Caller-supplied printer handle, identifying the printer for which event notification is being requested. This handle must have been previously obtained from [OpenPrinter](https://learn.microsoft.com/windows/win32/printdocs/openprinter).

### `fdwFilter`

Defines the **DWORD** parameter *fdwFilter*.

### `fdwOptions`

Not used.

### `pPrinterNotifyOptions`

Caller-supplied pointer to a PRINTER_NOTIFY_OPTIONS structure (described in the Windows SDK documentation).

## Return value

Returns the print driver handle.

## Remarks

When the spooler calls a print provider's **FindFirstPrinterChangeNotification** function, *pPrinterNotifyOptions* identifies the types of information that the print provider should send to the spooler when one of the specified events occurs.

For a list of the types of notifications an application can request, and for a list of the types of information that can be used to describe an event, see the Windows SDK documentation's description of **FindFirstPrinterChangeNotification**. Types of events for which an application might request notification include adding or deleting a print job or form. Types of information an application might request include job or form parameters.

If the print provider does not request polling, the print provider must supply the types of information identified by *pPrinterNotifyOptions*, by calling [PartialReplyPrinterChangeNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-partialreplyprinterchangenotification) or [ReplyPrinterChangeNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-replyprinterchangenotification).

If the provider does request polling (that is, it sets PRINTER_NOTIFY_STATUS_POLL), it should not call **ReplyPrinterChangeNotification**. Instead, the spooler signals the application at regular intervals.

Both polled and nonpolled print provider must return the current state of all requested information types whenever its [RefreshPrinterChangeNotification](https://learn.microsoft.com/previous-versions/ff561930(v=vs.85)) function is called.

For additional information, see [Supporting Printer Change Notifications](https://learn.microsoft.com/windows-hardware/drivers/print/supporting-printer-change-notifications).

## See also

[ReplyPrinterChangeNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-replyprinterchangenotification)

[PartialReplyPrinterChangeNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-partialreplyprinterchangenotification)

[RefreshPrinterChangeNotification](https://learn.microsoft.com/previous-versions/ff561930(v=vs.85))