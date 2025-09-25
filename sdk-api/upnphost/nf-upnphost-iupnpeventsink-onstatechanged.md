# IUPnPEventSink::OnStateChanged

## Description

The
**OnStateChanged** method sends an event to the device host with the list of DISPIDs of the state variables that have changed. The device host must query the service object to obtain the new value for each state variable that has changed.

This method is unavailable to Visual Basic developers, and those using other languages that do not support native arrays. These developers must use
[OnStateChangedSafe](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpeventsink-onstatechangedsafe) instead.

## Parameters

### `cChanges` [in]

Specifies the number of variables in *rgdispidChanges*. The value indicates the number of variables whose values have changed.

### `rgdispidChanges` [in]

Contains a list of the DISPIDs of the state variables that have changed. The number of elements in this buffer is specified by *cChanges*.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

If *cChanges* is zero or *rgdispidChanges* is **NULL**, E_INVALIDARG is returned.

## See also

[IUPnPEventSink](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpeventsink)