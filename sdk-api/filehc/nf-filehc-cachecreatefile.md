# CacheCreateFile function

## Description

Creates a file in the cache or finds an existing file.

## Parameters

### `lpstrName` [in]

A pointer to the name of the file to be created in the cache.

### `pfnCallBack` [in]

A pointer to the [FCACHE_CREATE_CALLBACK](https://learn.microsoft.com/previous-versions/bb432261(v=vs.85)) function that was used to create the file.

### `lpv` [in]

 If the file is not in the cache, the call calls *pfnCallBack* with *lpv* to do the actual work of calling [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

### `fAsyncContext` [in]

Specifies whether the context can be used for asynchronous I/O. If **TRUE**, the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) returned is asynchronous.

## Return value

Returns a pointer to the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure that is associated with the file that was created or found.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[FCACHE_CREATE_CALLBACK](https://learn.microsoft.com/previous-versions/bb432261(v=vs.85))

[FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10))