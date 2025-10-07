# DStorageGetFactory function (dstorage.h)

Returns the static DirectStorage factory object used to create DirectStorage queues, open files for DirectStorage access, and other global operations.

## Parameters

`riid`

Specifies the DirectStorage factory interface, such as `__uuidof(IDStorageFactory)`.

`ppv`

Receives the DirectStorage factory object.

## Return value

Standard HRESULT error code.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |