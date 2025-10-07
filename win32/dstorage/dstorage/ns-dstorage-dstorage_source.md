# DSTORAGE_SOURCE union (dstorage.h)

Describes the source specified for a DirectStorage request. For a request, the value of `request.Options.SourceType` determines which of these union fields is active. See [IDStorageQueue::EnqueueRequest](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nf-dstorage-idstoragequeue-enqueuerequest).

## Members

`Memory`

See [DSTORAGE_SOURCE_MEMORY](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_source_memory).

`File`

See [DSTORAGE_SOURCE_FILE](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_source_file).

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |