# RtlLookupFirstMatchingElementGenericTableAvl function

## Description

The **RtlLookupFirstMatchingElementGenericTableAvl** routine finds the left-most element in the tree that matches the indicated data.

## Parameters

### `Table` [in]

A pointer to the generic Adelson-Velsky/Landis (AVL) table ([RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table)).

### `Buffer` [in]

A buffer that contains the search data.

### `RestartKey` [out]

On output, contains a search context to use with an enumeration routine, such as [RtlEnumerateGenericTableWithoutSplayingAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplayingavl).

## Return value

The **RtlLookupFirstMatchingElementGenericTableAvl**routine returns a pointer to the matched data, or **NULL** if no match was found.

## Remarks

A tree that implements a generic table might contain several file names that differ only in case. A search algorithm can use this routine to locate the first match, without reference to case, and use an enumeration routine, such as [RtlEnumerateGenericTableWithoutSplayingAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplayingavl), to return each subsequent match.

By default, the operating system uses splay trees to implement generic tables, but the **RtlLookupFirstMatchingElementGenericTableAvl**routine only works with Adelson-Velsky/Landis (AVL) trees. Under some circumstances, operations on a splay tree will make the tree deep and narrow and might even turn it into a straight line. Very deep trees degrade the performance of searches. You can ensure a more balanced, shallower tree implementation of generic tables by using Adelson-Velsky/Landis (AVL) trees. If you want to configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines.

Callers of **RtlLookupFirstMatchingElementGenericTableAvl** must be running at <= APC_LEVEL if either of the following conditions holds:

* The caller-allocated memory at *Table* or at *Buffer* is pageable.
* The caller-supplied CompareRoutine contains pageable code.

## See also

[RtlEnumerateGenericTableWithoutSplayingAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplayingavl)