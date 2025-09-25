# ClfsAllocReservedLog function

## Description

The **ClfsAllocReservedLog** routine reserves space in a marshalling area for a set of records.

## Parameters

### `pvMarshalContext` [in]

A pointer to an opaque context that represents a marshalling area. The caller previously obtained this pointer by calling [ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea).

### `cRecords` [in]

The number of records in the set. This value must match the value of *cRecords* previously passed to [ClfsAlignReservedLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsalignreservedlog).

### `pcbAdjustment` [in]

A pointer to a LONGLONG-typed variable that supplies the size, in bytes, of the reservation that will hold all the records in the set. The caller previously obtained this size by calling [ClfsAlignReservedLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsalignreservedlog).

## Return value

**ClfsAllocReservedLog** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsAlignReservedLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsalignreservedlog)