# IRSOPInformation::GetEventLogEntryText

## Description

The
**GetEventLogEntryText** method returns the text for a specific entry in the event log.

## Parameters

### `pszEventSource` [in]

Specifies the name of the source (application, service, driver, subsystem) that generated the log entry.

### `pszEventLogName` [in]

Specifies the name of the event log.

### `pszEventTime` [in]

Specifies the time the event was logged, in Windows Management Instrumentation (WMI) format. For more information, see
[Date and Time Format](https://learn.microsoft.com/windows/desktop/WmiSdk/date-and-time-format) in the WMI documentation.

### `dwEventID` [in]

Specifies the event ID.

### `ppszText` [out]

Receives the pointer to a buffer containing the text of the event log entry. The calling application must free the memory allocated for this buffer with a call to the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## See also

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IRSOPInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-irsopinformation)