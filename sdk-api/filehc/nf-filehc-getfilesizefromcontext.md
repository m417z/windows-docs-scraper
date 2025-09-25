# GetFileSizeFromContext function

## Description

Reports the file size cached with the handle.

## Parameters

### `pContext` [in]

A pointer to the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure that is associated with the file.

### `pcbFileSizeHigh` [out]

A pointer to the byte count of the file.

## Return value

Returns the size of the file in bytes.

## See also

[FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10))