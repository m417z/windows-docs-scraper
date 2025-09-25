## Description

Performs an asynchronous refresh operation with the specified query, and invokes the [IPrinterQueueEvent::OnBidiResponseReceived](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterqueueevent-onbidiresponsereceived) method.

## Parameters

### `bstrBidiQuery` [in]

The specified query.

## Return value

This method returns an **HRESULT** value.

## Remarks

When the **SendBidiQuery** method is called, it immediately raises the [IPrinterQueueEvent::OnBidiResponseReceived](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterqueueevent-onbidiresponsereceived) event, if there is a cached response available. The print system then starts an asynchronous operation to use the [Bidi Communication Interfaces](https://learn.microsoft.com/previous-versions/dd183365(v=vs.85)). At this point **SendBidiQuery** returns, thus unblocking the caller. When the asynchronous operation completes, the print system raises the **IPrinterQueueEvent::OnBidiResponseReceived** event again. **SendBidiQuery** is decoupled from its associated response on purpose. The decoupling is done because, in the case where there is no cached data, the resulting latency can be due to many factors and an immediate response cannot be expected. Additionally the caller may receive multiple responses based on whether there is cached data, and whether there is a response from the device.

Using the [Bidi Communication Interfaces](https://learn.microsoft.com/previous-versions/dd183365(v=vs.85)) causes the port monitor to refresh the underlying requested values. In the case of USB, if a JavaScript component is available, then the JavaScript code is invoked to refresh the requested values.

The cache is also updated in the following situations:

- At predetermined intervals

  - For WSD devices the data is updated when the device reports changes via events.

  - For TCP & USB devices the refresh interval is based on where the Bidi value is defined.

  - All standard Bidi values (as defined by the port monitor's embedded Bidi files) are refreshed at an interval that is preset by the port monitors. If the specific Bidi Query is part of the IHV Bidi Extension, then the refresh interval is specified in the XML extension file for each individual value.

- When printer configuration changes

  - For example, when a WSD-based device raises an event to let the spooler (WSDMon) know that something about the device has changed. In other words, the printer configuration has changed.

## See also

[Bidi Communication Interfaces](https://learn.microsoft.com/previous-versions/dd183365(v=vs.85))

[IPrinterQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueue)

[IPrinterQueueEvent::OnBidiResponseReceived](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterqueueevent-onbidiresponsereceived)