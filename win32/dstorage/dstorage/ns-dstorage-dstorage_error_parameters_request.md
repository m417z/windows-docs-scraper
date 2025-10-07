# DSTORAGE_ERROR_PARAMETERS_REQUEST structure (dstorage.h)

The parameters passed to the [EnqueueRequest](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nf-dstorage-idstoragequeue-enqueuerequest) call, and optional filename if the request is for a file source.

## Members

`Filename`

For a file source request, the name of the file the request was targeted to.

`RequestName`

The name of the request if one was specified.

`Request`

The parameters passed to the [EnqueueRequest](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nf-dstorage-idstoragequeue-enqueuerequest) call.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |