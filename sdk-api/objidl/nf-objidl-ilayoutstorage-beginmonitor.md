# ILayoutStorage::BeginMonitor

## Description

The **BeginMonitor** method is used to begin monitoring when a loading operation is started. When the operation is complete, the application must call
[ILayoutStorage::EndMonitor](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-endmonitor).

## Return value

This method supports the standard return values E_OUTOFMEMORY, E_UNEXPECTED, E_INVALIDARG, and E_FAIL, as well as the following:

| Return code | Description |
|----------------|---------------|
| STG_E_INUSE | BeginMonitor\</xref> was called while **ILayoutStorage** was already monitoring. |

## Remarks

Normally an application calls
**BeginMonitor** before the actual loading begins. Once this method has been called, the compound file implementation regards any operation performed on the files storages and streams as part of the desired access pattern. The result is a layout script like that created explicitly by calling
[ILayoutStorage::LayoutScript](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-layoutscript).

Applications will usually use monitoring to obtain the access pattern of embedded objects. Monitoring also makes possible generic layout tools, that launch existing applications and monitor their access patterns.

A call to
[ILayoutStorage::EndMonitor](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-endmonitor) ends monitoring. Multiple calls to
**BeginMonitor** and
**EndMonitor** are permitted. Monitoring can also be mixed with calls to
[ILayoutStorage::LayoutScript](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-layoutscript).

## See also

[ILayoutStorage::EndMonitor](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-endmonitor)

[ILayoutStorage::LayoutScript](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-layoutscript)