# RtlInsertElementGenericTableAvl function

## Description

The **RtlInsertElementGenericTableAvl** routine adds a new entry to a generic table.

## Parameters

### `Table` [in]

Pointer to a generic Adelson-Velsky/Landis (AVL) table ([RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table)) that was initialized by a call to [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl).

### `Buffer` [in]

A caller-allocated buffer that contains the user data to copy into the new element. For more information, see [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl).

### `BufferSize` [in]

Size in bytes of data in *Buffer.*

### `NewElement` [out, optional]

On output, a value of **TRUE** means the insertion of the new element in the generic table was successful. A value of **FALSE** means the insertion failed.

## Return value

**RtlInsertElementGenericTableAvl** returns a pointer to the user data for the newly inserted entry, or the user data for a matching entry that is already in the generic table. If no matching entry is found, but **RtlInsertElementGenericTableAvl** cannot insert the new entry (for example, because the *AllocateRoutine* fails), **RtlInsertElementGenericTableAvl** returns **NULL**.

## Remarks

To insert an entry, **RtlInsertElementGenericTableAvl** calls the *CompareRoutine* and *AllocateRoutine* that were registered when the generic table was initialized by [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl). After inserting the new entry, **RtlInsertElementGenericTableAvl** rebalances the AVL link tree.

When a new entry is inserted into the table, its data is copied from *Buffer* into the new entry. Thus the pointer returned by **RtlInsertElementGenericTableAvl** is never equal to *Buffer*.

If the caller's *CompareRoutine* returns **GenericEqual**, the data at *Buffer* is assumed to duplicate the data for an existing entry in the generic table. In this case, **RtlInsertElementGenericTableAvl** does not add the new entry (and thus does not call the *AllocateRoutine*), because a generic table cannot have duplicate entries.

If a matching entry already exists in the generic table, **RtlInsertElementGenericTableAvl** returns a pointer to the existing entry's data and sets *NewElement* to **FALSE**.

If there is no matching entry in the table already,**RtlInsertElementGenericTableAvl** routine allocates sufficient space for the user data of new entry (*BufferSize*) plus the links associated with the new entry. Thus the total number of bytes will be at least *BufferSize* + **sizeof**(RTL_BALANCED_LINKS). Caller should not use the first **sizeof**(RTL_BALANCED_LINKS) bytes of the memory that the *AllocateRoutine*allocates.

Callers of the *Rtl..GenericTableAvl* routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

By default, the operating system uses splay trees to implement generic tables, but the **RtlInsertElementGenericTableAvl** routine only works with Adelson-Velsky/Landis (AVL) trees. To configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the **RtlInsertElementGenericTableAvl** routine instead of [RtlInsertElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictable). In the call to **RtlInsertElementGenericTableAvl**, the caller must pass a [RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of **RtlInsertElementGenericTableAvl** must be running at IRQL < DISPATCH_LEVEL if either of the following conditions holds:

* The caller-allocated memory at *Table* or at *Buffer* is pageable.
* The caller-supplied *CompareRoutine* or *AllocateRoutine* contains pageable code.

## See also

[RtlDeleteElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldeleteelementgenerictableavl)

[RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl)