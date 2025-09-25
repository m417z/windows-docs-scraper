# ClfsAlignReservedLog function

## Description

The **ClfsAlignReservedLog** routine calculates the size of the space that must be reserved for a specified set of records. The size calculation includes the space required for headers and the space required for sector alignment.

## Parameters

### `pvMarshalContext` [in]

A pointer to an opaque context that represents a marshalling area associated with a CLFS stream. The caller previously obtained this pointer by calling [ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea).

### `cRecords` [in]

The number of elements in the array pointed to by *rgcbReservation*.

### `rgcbReservation` [in]

A pointer to an array of LONGLONG-typed variables that supplies a list of record sizes (in bytes).

### `pcbAlignReservation` [out]

A pointer to a LONGLONG-typed variable that receives the size, in bytes, of the required reservation.

## Return value

**ClfsAlignReservedLog** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsAllocReservedLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsallocreservedlog)