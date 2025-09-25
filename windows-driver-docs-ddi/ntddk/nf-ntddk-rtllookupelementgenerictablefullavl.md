# RtlLookupElementGenericTableFullAvl function

## Description

The **RtlLookupElementGenericTableFullAvl** routine searches a generic table for an element that matches the specified data.

## Parameters

### `Table` [in]

Pointer to the generic Adelson-Velsky/Landis (AVL) table ([RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table)). The table must have been initialized by calling [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl).

### `Buffer` [in]

A buffer of search data to pass to the *CompareRoutine* that was registered when [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl) initialized the generic table. For more information, see the description of **RtlInitializeGenericTableAvl**.

### `NodeOrParent` [out]

On output, a value that describes the relationship of the *NodeOrParent* with the table entry (node) that **RtlLookupElementGenericTableFullAvl** is searching for. The *SearchResult* parameter can have any of the following values:

#### TableEmptyTree

The tree was empty. The contents of *NodeOrParent* has *not* been altered.

#### TableFoundNode

The **RtlLookupElementGenericTableFullAvl** routine found a table entry whose key matches the data in *Buffer*. *NodeOrParent* contains a pointer to the matched entry.

#### TableInsertAsLeft

The **RtlLookupElementGenericTableFullAvl** routine did *not*find a table entry whose key matches the data in *Buffer*. I*not*f the entry that **RtlLookupElementGenericTableFullAvl** searched for were in the table, it would be the left child of the entry that *NodeOrParent* points to.

#### TableInsertAsRight

The **RtlLookupElementGenericTableFullAvl** routine did *not*find a table entry whose key matches the data in *Buffer*. If the entry that **RtlLookupElementGenericTableFullAvl** searched for were in the table, it would be the right child of the entry that *NodeOrParent* points to.

### `SearchResult` [out]

A pointer to a table entry. If the **RtlLookupElementGenericTableFullAvl** routine matches an entry, *NodeOrParent*points to the matched entry. If the **RtlLookupElementGenericTableFullAvl** routine fails to find a match, *NodeOrParent* points to the entry that would be the parent of the entry that **RtlLookupElementGenericTableFullAvl** routine was searching for.

## Return value

**RtlLookupElementGenericTableFullAvl** returns a pointer to the user data that is associated with the matching element in the generic table, or **NULL** if the generic table currently has no elements or if no matching element is found.

## Remarks

By default, the operating system uses splay trees to implement generic tables, but the **RtlLookupElementGenericTableFullAvl** routine only works with Adelson-Velsky/Landis (AVL) trees. To configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the **RtlLookupElementGenericTableFullAvl** routine instead of [RtlLookupElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictable). In the call to **RtlLookupElementGenericTableFullAvl**, the caller must pass a [RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of the *Rtl..GenericTableAvl* routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlLookupElementGenericTableFullAvl** must be running at IRQL < DISPATCH_LEVEL if either of the following conditions holds:

* The caller-allocated memory at *Table* or at *Buffer* is pageable.
* The caller-supplied *CompareRoutine* contains pageable code.

## See also

[RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl)

[RtlIsGenericTableEmptyAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableemptyavl)

[RtlNumberGenericTableElementsAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelementsavl)