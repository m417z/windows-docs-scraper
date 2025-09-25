# RtlDeleteElementGenericTableAvl function

## Description

The **RtlDeleteElementGenericTableAvl** routine deletes an element from a generic table.

## Parameters

### `Table` [in]

A pointer to the generic table ([RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table)). The table must have been initialized by calling [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl).

### `Buffer` [in]

A pointer to a caller-allocated buffer containing a value that uniquely identifies the element to be deleted.

## Return value

**RtlDeleteElementGenericTableAvl** returns **TRUE** if the element was successfully deleted, **FALSE** otherwise.

## Remarks

**RtlDeleteElementGenericTableAvl** calls the *CompareRoutine* and *FreeRoutine* that were registered in the call to [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl).

By default, the operating system uses splay trees to implement generic tables, but the **RtlDeleteElementGenericTableAvl** routine only works with Adelson-Velsky/Landis (AVL) trees. To configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the **RtlDeleteElementGenericTableAvl** routine instead of [RtlDeleteElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldeleteelementgenerictable). In the call to **RtlDeleteElementGenericTableAvl**, the caller must pass a [RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of the *Rtl..GenericTableAvl* routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlDeleteElementGenericTableAvl** must be running at IRQL < DISPATCH_LEVEL if either of the following conditions holds:

* The caller-allocated memory at *Table* or at *Buffer* is pageable.
* The caller-supplied *CompareRoutine* or *FreeRoutine* contains pageable code.

## See also

[RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl)

[RtlInsertElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictableavl)