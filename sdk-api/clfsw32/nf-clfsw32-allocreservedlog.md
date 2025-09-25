# AllocReservedLog function

## Description

Allocates sector-aligned space for a set of reserved records. The requested allocation must be the same size that [AlignReservedLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-alignreservedlog) returns.

## Parameters

### `pvMarshal` [in, out]

A pointer to the marshaling context that is allocated by calling the [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) function.

### `cReservedRecords` [in]

The number of reserved records that are associated with the reservation adjustment.

This value must be greater than zero (0).

### `pcbAdjustment` [in, out]

The size of the sector-aligned space reservation that is associated with the number of records specified in *cReservedRecords*, in bytes.

This parameter must be the aligned reservation size that [AlignReservedLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-alignreservedlog) returns in **pcbAlignReservation*.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## See also

[AlignReservedLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-alignreservedlog)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)