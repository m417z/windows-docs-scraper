# AlignReservedLog function

## Description

Calculates the sector-aligned reservation size for a set of reserved records. This value is then passed to [AllocReservedLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-allocreservedlog) to reserve a block of log space for a set of records.

## Parameters

### `pvMarshal` [in, out]

A pointer to the opaque marshaling context that is allocated by calling the [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) function.

### `cReservedRecords` [in]

The number of reserved records that are associated with the reservation adjustment.

### `rgcbReservation` [in]

An array of space allocations to reserve in the log that is associated with the current marshaling context, in bytes.

The number of allocations corresponds to the number of records that *cReservedRecords* specifies. Each allocation must be greater than zero (0) or the function fails with **ERROR_INVALID_PARAMETER**.

### `pcbAlignReservation` [out]

A pointer to a variable in which the function returns the number of sector-aligned byte space to be reserved in the log—after being given the number of records that *cRecords* specifies and the size of reservations specified in the *rgcbReservation* array.

 The value returned in **pcbAlignReservation* is used as input to [AllocReservedLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-allocreservedlog). If **AllocReservedLog** succeeds, this value is always greater than zero (0). If **AllocReservedLog** fails, the value is zero (0).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## See also

[AllocReservedLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-allocreservedlog)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)