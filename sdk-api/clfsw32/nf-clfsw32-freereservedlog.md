# FreeReservedLog function

## Description

Reduces the number of reserved log records in a marshaling area made by calling [ReserveAndAppendLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-reserveandappendlog), [ReserveAndAppendLogAligned](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-reserveandappendlogaligned), or [AllocReservedLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-allocreservedlog). By using this function, clients can free an aggregate set of records and bytes that are reserved in the marshaling area.

## Parameters

### `pvMarshal` [in, out]

A pointer to the opaque marshaling context that is allocated by using the [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) function.

### `cReservedRecords` [in]

The number of reserved records to be freed.

If the byte count of the adjustment in *pcbAdjustment* is positive, *cReservedRecords* is the total number of reserved records that are remaining after the adjustment. Otherwise, this parameter specifies the number of records to be subtracted from the current number of reserved records, but can never exceed the reserved count.

### `pcbAdjustment` [in, out]

The number of bytes of reservation space affected by the adjustment.

On input, if this number is positive, it specifies the total remaining size of the reserved space after the adjustment. If this parameter is negative, its absolute value is the number of bytes to be freed.

This value is usually an aggregate of the actual reserved space that is returned in a previous call to the following:

* [ReserveAndAppendLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-reserveandappendlog)
* [ReserveAndAppendLogAligned](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-reserveandappendlogaligned)
* [AllocReservedLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-allocreservedlog)

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## Remarks

When you reserve records, you reserve a specific size. When you free those records, you must free the same size.

## See also

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)