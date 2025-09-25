# IAdviseSink::OnSave

## Description

Called by the server to notify all registered advisory sinks that the object has been saved.

## Remarks

Object handlers and link objects normally implement **IAdviseSink::OnSave** to receive notifications of when an object is saved to disk, either to its original storage (through a **Save** operation) or to new storage (through a **Save As** operation). Object Handlers and link objects register to be notified when an object is saved for the purpose of updating their caches, but then only if the advise flag passed during registration specifies ADVFCACHE_ONSAVE. Object handlers and link objects forward these notifications to their containers.

## See also

[IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink)