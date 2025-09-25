# ClfsReserveAndAppendLog function

## Description

The **ClfsReserveAndAppendLog** routine reserves space in a marshalling area or appends a record to a marshalling area or does both atomically.

## Parameters

### `pvMarshalContext` [in]

A pointer to an opaque context that represents a marshalling area associated with a CLFS stream. The caller previously obtained this pointer by calling [ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea).

### `rgWriteEntries` [in, optional]

A pointer to an array of [CLFS_WRITE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_write_entry) structures, each of which holds a pointer to a buffer of data that will become part of the record that is appended to the log. This parameter can be **NULL** if *cWriteEntries* is zero.

### `cWriteEntries` [in]

The number of elements in the array pointed to by *rgWriteEntries*. This parameter must be zero if *rgWriteEntries* is **NULL**.

### `plsnUndoNext` [in, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that supplies the undo-next LSN of the record to be appended.

### `plsnPrevious` [in, optional]

A pointer to a CLFS_LSN structure that supplies the previous LSN of the record to be appended.

### `cReserveRecords` [in]

The number of elements in the array pointed to by *rgcbReservation*. This parameter must be zero if *rgcbReservation* is **NULL** or the CLFS_FLAG_USE_RESERVATION flag of *fFlags* is set.

### `rgcbReservation` [in, out]

A pointer to an array of LONGLONG-typed variables. The caller sets each element of the array to the size, in bytes, of a record that must have space reserved for it. On return, each array element receives that actual size of the space reserved for the record. This includes the space required for headers and alignment. If the reservation value is negative, a reserved record that most nearly matches the absolute value of the provided negative value will be freed. This parameter can be **NULL** if *cReserveRecords* is zero and must be **NULL** if the CLFS_FLAG_USE_RESERVATION flag of *fFlags* is set.

### `fFlags` [in]

This parameter can be zero or any combination of the following flags.

| Flag | Meaning |
| --- | --- |
| CLFS_FLAG_FORCE_APPEND | After the current record is appended to a log I/O block, the block is queued, in LSN sequence, to stable storage. This flag provides no guarantee that the record is forced to stable storage (see CLFS_FLAG_FORCE_FLUSH). |
| CLFS_FLAG_FORCE_FLUSH | After the current record is appended to a log I/O block, the block is forced to stable storage. |
| CLFS_FLAG_USE_RESERVATION | The current record is placed in reserved space in a log I/O block within the marshalling area. The number of reserved records in the marshalling area is reduced by one. If this flag is set, *cReserveRecords* must be zero and *rgcbReservation* must be **NULL**. |

### `plsn` [out, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that receives the LSN of the appended record. This parameter can be **NULL** if *cWriteEntries* is zero.

## Return value

**ClfsReserveAndAppendLog** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

The **ClfsReserveAndAppendLog** routine changes its fundamental behavior based on the presence of optional parameters and the state of the CLFS_USE_RESERVATION flag. The following table summarizes common scenarios.

| Parameter and flag values | Actions performed |
| --- | --- |
| *cWriteEntries* = 0.<br><br>*rgWriteEntries* = **NULL**.<br><br>*plsn* = **NULL**. | Reserves space for a set of records, but does not append the records to the marshalling area. The *rgcbReservation* parameter gives the size of the data portion of each record that needs space reserved. |
| *cWriteEntries* > 0.<br><br>*rgWriteEntries* is not **NULL**.<br><br>*plsn* is not **NULL**.<br><br>*cReserveRecords* = 0.<br><br>*rgcbReservation* is **NULL**.<br><br>CLFS_USE_RESERVATION is set. | Appends a record to the marshalling area by using space that has already been reserved. Reduces the number of reserved record spaces by one. |
| *cWriteEntries* > 0.<br><br>*rgWriteEntries* is not **NULL**.<br><br>*plsn* is not **NULL**.<br><br>*cReserveRecords* = 0.<br><br>*rgcbReservation* is **NULL**.<br><br>CLFS_USE_RESERVATION is cleared. | Appends a record to the marshalling area by reserving new space. Leaves the number of reserved record spaces unchanged. |
| *cWriteEntries* > 0.<br><br>*rgWriteEntries* is not **NULL**.<br><br>*plsn* is not **NULL**.<br><br>*cReserveRecords* > 0.<br><br>rgcbReservation is not **NULL**.<br><br>CLFS_USE_RESERVATION flag is cleared. | Appends a record to the marshalling area by reserving new space. Also reserves space for a set of records that are not appended at this time. The *rgcbReservation* parameter gives the size of each record that needs space reserved. Increases the number of reserved record spaces by the value of *cReserveRecords*. |

Calling **ClfsReserveAndAppendLog** is equivalent to calling [ClfsReserveAndAppendLogAligned](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreserveandappendlogaligned) with the *cbEntryAlignment* parameter set to one.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn)

[CLFS_WRITE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_write_entry)

[ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea)

[ClfsReserveAndAppendLogAligned](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreserveandappendlogaligned)