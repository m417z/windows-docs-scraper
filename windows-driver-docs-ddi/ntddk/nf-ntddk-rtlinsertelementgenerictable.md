# RtlInsertElementGenericTable function

## Description

The **RtlInsertElementGenericTable** routine adds a new element to a generic table.

## Parameters

### `Table` [in]

Pointer to the generic table ([RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table)). The table must have been initialized by calling [RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable).

### `Buffer` [in]

Pointer to a caller-allocated buffer containing data to be copied into the new element. For more information, see the description of [RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable).

### `BufferSize` [in]

Number of bytes to be allocated for caller-supplied data when the new element is inserted.

### `NewElement` [out, optional]

Pointer to a variable that receives **TRUE** if a new element with the data at *Buffer* was inserted in the generic table; or **FALSE** if the new element was not inserted.

## Return value

**RtlInsertElementGenericTable** returns a pointer to the newly inserted element's associated data, or it returns a pointer to the existing element's data if a matching element already exists in the generic table. If no matching element is found, but the new element cannot be inserted (for example, because the *AllocateRoutine* fails), **RtlInsertElementGenericTable** returns **NULL**.

## Remarks

To insert an element, **RtlInsertElementGenericTable** calls the *CompareRoutine* and *AllocateRoutine* that were registered when the generic table was initialized by [RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable). After inserting the new element, **RtlInsertElementGenericTable** rebalances the splay link tree.

When a new element is inserted into the table, its data is copied from *Buffer* into the new element. Thus the pointer returned by **RtlInsertElementGenericTable** is never equal to *Buffer*.

If the caller's *CompareRoutine* returns **GenericEqual**, the data at *Buffer* is assumed to duplicate the data for an existing element in the generic table. In this case, **RtlInsertElementGenericTable** does not add the new element (and thus does not call the *AllocateRoutine*), because a generic table cannot have duplicate elements.

If a matching element already exists in the generic table, **RtlInsertElementGenericTable** returns a pointer to the existing element's data and sets *NewElement* to **FALSE**.

Callers of the Rtl..GenericTable routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

By default, the operating system uses splay trees to implement generic tables. Under some circumstances, operations on a splay tree will make the tree deep and narrow and might even turn it into a straight line. Very deep trees degrade the performance of searches. You can ensure a more balanced, shallower tree implementation of generic tables by using Adelson-Velsky/Landis (AVL) trees. If you want to configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the [RtlInsertElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictableavl) routine instead of **RtlInsertElementGenericTable**. In the call to **RtlInsertElementGenericTableAvl**, the caller must pass a [RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of **RtlInsertElementGenericTable** must be running at IRQL < DISPATCH_LEVEL if either of the following conditions holds:

* The caller-allocated memory at *Table* or at *Buffer* is pageable.
* The caller-supplied *CompareRoutine* or *AllocateRoutine* contains pageable code.

## See also

[RtlDeleteElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldeleteelementgenerictable)

[RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable)