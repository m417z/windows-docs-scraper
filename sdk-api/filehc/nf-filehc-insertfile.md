# InsertFile function

## Description

Inserts a file into the cache.

## Parameters

### `lpstrName` [in]

The name of the file to be inserted.

### `pContext` [in]

A pointer to the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure that is associated with the file being inserted.

### `fKeepReference` [in]

Specifies whether the reference to the file is to be kept. If **TRUE**, the user must make a call to [ReleaseContext](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms527734(v=exchg.10)) for the inserted [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)).

## Return value

Returns **TRUE** if the file is inserted; otherwise, it returns **FALSE**.

## See also

[FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10))

[ReleaseContext](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms527734(v=exchg.10))