# DSTORAGE_ERROR_PARAMETERS_STATUS structure (dstorage.h)

The parameters passed to the [EnqueueStatus](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nf-dstorage-idstoragequeue-enqueuestatus) call.

## Members

`StatusArray`

A pointer to an [IDStorageStatusArray](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nn-dstorage-idstoragestatusarray) object.

`Index`

The index of the status entry in the [IDStorageStatusArray](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nn-dstorage-idstoragestatusarray) object to receive the status.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |