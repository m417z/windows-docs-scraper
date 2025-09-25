# IUPnPEventSink::OnStateChangedSafe

## Description

The
**OnStateChangedSafe** method sends an event to the device host with the list of DISPIDs that have changed. The device host must query the service object to obtain the new value for each state variable that has changed.

The
**OnStateChangedSafe** method can only be used by Visual Basic developers and those using languages that do not support native arrays.

## Parameters

### `varsadispidChanges` [in]

Contains a safearray of the DISPIDs of the state variables that have changed.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPEventSink](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpeventsink)