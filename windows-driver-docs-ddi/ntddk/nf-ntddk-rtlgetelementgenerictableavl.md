# RtlGetElementGenericTableAvl function

## Description

The **RtlGetElementGenericTableAvl** routine returns a pointer to the caller-supplied data for a particular generic Adelson-Velsky/Landis (AVL) table element.

## Parameters

### `Table` [in]

Pointer to the generic AVL table ([RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table)) from which the *I*th element is to be retrieved. The table must have been initialized by calling [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl).

### `I` [in]

Index of the element selected. This value is zero-based, so the index of the last-inserted element currently in *Table* is always one less than the value returned by [RtlNumberGenericTableElementsAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelementsavl).

## Return value

**RtlGetElementGenericTableAvl** returns a pointer to the caller-supplied data for the *I*th element in the generic AVL table. It returns **NULL** if the given *I* is too large or if the generic AVL table currently has no elements.

## Remarks

**RtlGetElementGenericTableAvl** returns the *I*th element inserted in the generic AVL table. To retrieve the first element, set *I* to zero. To retrieve the last element, set *I* to ([RtlNumberGenericTableElementsAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelementsavl)(*Table*)-1). Note that if an element is deleted from the generic table, the indexes of all elements inserted after the deleted element are decremented. Thus an element's index might change over time.

**RtlGetElementGenericTableAvl** is more efficient than [RtlLookupElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictableavl) if the caller can supply the index of a particular element for which the caller needs access to the associated data. However, calling **RtlGetElementGenericTableAvl** repeatedly to test for such an element is less efficient than calling **RtlLookupElementGenericTableAvl** to locate it.

Callers of the Rtl..GenericTable routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

By default, the operating system uses splay trees to implement generic tables. Under some circumstances, operations on a splay tree will make the tree deep and narrow and might even turn it into a straight line. Very deep trees degrade the performance of searches. You can ensure a more balanced, shallower tree implementation of generic tables by using Adelson-Velsky/Landis (AVL) trees. If you want to configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the **RtlGetElementGenericTableAvl** routine instead of [RtlGetElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetelementgenerictable). In the call to **RtlGetElementGenericTableAvl**, the caller must pass a [RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of **RtlGetElementGenericTableAvl** must be running at IRQL < DISPATCH_LEVEL if the caller-allocated memory for the generic table is pageable.

## See also

[RtlDeleteElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldeleteelementgenerictableavl)

[RtlEnumerateGenericTableWithoutSplayingAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplayingavl)

[RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl)

[RtlInsertElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictableavl)

[RtlLookupElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictableavl)

[RtlNumberGenericTableElementsAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelementsavl)