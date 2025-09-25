# ILayoutStorage::EndMonitor

## Description

The **EndMonitor** method ends monitoring of a compound file. Must be preceded by a call to
[ILayoutStorage::BeginMonitor](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-beginmonitor).

## Return value

This function supports the standard return values E_OUTOFMEMORY, E_UNEXPECTED, E_INVALIDARG, and E_FAIL, as well as all return values for [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

## Remarks

A call to
**EndMonitor** is generally followed by a call to
[ILayoutStorage::RelayoutDocfile](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-relayoutdocfile), which uses the access pattern detected by the monitoring to restructure the compound file.

## See also

[ILayoutStorage::BeginMonitor](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-beginmonitor)

[ILayoutStorage::ReLayoutDocfile](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-relayoutdocfile)