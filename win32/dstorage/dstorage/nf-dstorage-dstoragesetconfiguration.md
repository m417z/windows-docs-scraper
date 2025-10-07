# DStorageSetConfiguration function (dstorage.h)

Configures DirectStorage. You must call **DStorageSetConfiguration** before your first call to [DStorageGetFactory](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nf-dstorage-dstoragegetfactory). If you don't, then default values are used.

## Parameters

`configuration`

Type: **[DSTORAGE_CONFIGURATION](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_configuration)**

Specifies the configuration.

## Return value

Standard HRESULT error code. The configuration can be changed only when no queue is created and no files are open; otherwise, **E_DSTORAGE_STAGING_BUFFER_LOCKED** is returned.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |