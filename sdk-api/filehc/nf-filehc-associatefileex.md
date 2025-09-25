# AssociateFileEx function

## Description

Associates a file with an asnychronous context.

## Parameters

### `hFile` [in]

A file handle that should be in the context. It is created with the FILE_FLAG_OVERLAPPED flag set for asynchronous I/O operations.

### `fStoreWithDots` [in]

If set to **TRUE**, this object was stored with dot stuffing.

### `fStoredWithTerminatingDot` [in]

A flag that indicates whether the terminating dot is included in an object. If this parameter is set to **TRUE**, the object is stored with a terminating dot.

The terminating dot is used by the NNTP/SMTP protocol to identify the end of message.

## Return value

Returns a pointer to the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure that was obtained. If the function fails, it returns **NULL**.

## See also

[FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10))