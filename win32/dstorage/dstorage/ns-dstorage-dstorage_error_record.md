# DSTORAGE_ERROR_RECORD structure (dstorage.h)

Structure to receive the detailed record of a failed DirectStorage request.

## Members

`FailureCount`

The number of failed requests in the queue since the last [RetrieveErrorRecord](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nf-dstorage-idstoragequeue-retrieveerrorrecord) call.

`FirstFailure`

Detailed record about the first failed command in the enqueue order.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |