# DStorageSetConfiguration1 function (dstorage.h)

Configures DirectStorage; with an additional option to enable file buffering. You must call **DStorageSetConfiguration1** before your first call to [DStorageGetFactory](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nf-dstorage-dstoragegetfactory). If you don't, then default values are used.

## Parameters

`configuration`

Type: **[DSTORAGE_CONFIGURATION1](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_configuration1)**

Specifies the configuration.

## Return value

Standard HRESULT error code. The configuration can be changed only when no queue is created and no files are open; otherwise, **E_DSTORAGE_STAGING_BUFFER_LOCKED** is returned.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |