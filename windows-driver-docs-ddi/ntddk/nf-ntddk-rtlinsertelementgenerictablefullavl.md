# RtlInsertElementGenericTableFullAvl function

## Description

The **RtlInsertElementGenericTableFullAvl** routine adds a new entry to a generic table.

## Parameters

### `Table` [in]

Pointer to a generic Adelson-Velsky/Landis (AVL) table ([RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table)) that was initialized by a call to [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl).

### `Buffer` [in]

A caller-allocated buffer that contains the user data to copy into the new element. For more information, see [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl).

### `BufferSize` [in]

Size in bytes of data in *Buffer.*

### `NewElement` [out, optional]

On output, a value of **TRUE** means the insertion of the new element in the generic table was successful. A value of **FALSE** means the insertion failed.

### `NodeOrParent` [in]

The search result of a previous call to [RtlLookupElementGenericTableFullAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictablefullavl). This value indicates to the **RtlInsertElementGenericTableFullAvl** routine whether the tree is currently empty, or if not empty, whether to insert the new entry to the left or the right of the parent entry. The *SearchResult* parameter can have any of the following values:

#### TableEmptyTree

The tree was empty. The contents of *NodeOrParent* has *not* been altered.

#### TableFoundNode

The **RtlInsertElementGenericTableFullAvl** routine found a table entry whose key matches the data in *Buffer*. *NodeOrParent* contains a pointer to the matched entry.

#### TableInsertAsLeft

The **RtlInsertElementGenericTableFullAvl** routine did *not* find a table entry whose key matches the data in *Buffer*. If the entry that **RtlInsertElementGenericTableFullAvl** searched for were in the table, it would be the left child of the entry that *NodeOrParent* points to.

#### TableInsertAsRight

The **RtlInsertElementGenericTableFullAvl** routine did *not* find a table entry whose key matches the data in *Buffer*. If the entry that **RtlInsertElementGenericTableFullAvl** searched for were in the table, it would be the right child of the entry that *NodeOrParent* points to.

### `SearchResult` [in]

A pointer to a table entry. If the **RtlInsertElementGenericTableFullAvl** routine matches an entry, *NodeOrParent* points to the matched entry. If the **RtlInsertElementGenericTableFullAvl** routine fails to find a match, *NodeOrParent* points to the entry that would be the parent of the entry that **RtlInsertElementGenericTableFullAvl** routine was searching for.

## Return value

**RtlInsertElementGenericTableFullAvl** returns a pointer to the user data for the newly inserted entry, or the user data for a matching entry that is already in the generic table. If no matching entry is found, but **RtlInsertElementGenericTableFullAvl** cannot insert the new entry (for example, because the *AllocateRoutine* fails), **RtlInsertElementGenericTableFullAvl** returns **NULL**.

## Remarks

To insert an entry, **RtlInsertElementGenericTableFullAvl** calls the *CompareRoutine* and *AllocateRoutine* that were registered when the generic table was initialized by [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl). After inserting the new entry, **RtlInsertElementGenericTableFullAvl** rebalances the AVL link tree.

When a new entry is inserted into the table, its data is copied from *Buffer* into the new entry. Thus the pointer returned by **RtlInsertElementGenericTableFullAvl** is never equal to *Buffer*.

If the caller's *CompareRoutine* returns **GenericEqual**, the data at *Buffer* is assumed to duplicate the data for an existing entry in the generic table. In this case, **RtlInsertElementGenericTableFullAvl** does not add the new entry (and thus does not call the *AllocateRoutine*), because a generic table cannot have duplicate entries.

If a matching entry already exists in the generic table, **RtlInsertElementGenericTableFullAvl** returns a pointer to the existing entry's data and sets *NewElement* to **FALSE**.

If there is no matching entry in the table already,**RtlInsertElementGenericTableFullAvl** routine allocates sufficient space for the user data of new entry (*BufferSize*) plus the links associated with the new entry. Thus the total number of bytes will be at least *BufferSize* + **sizeof**(BALANCED_LINKS). Caller should not use the first **sizeof**(BALANCED_LINKS) bytes of the memory that the *AllocateRoutine*allocates.

Callers of the*Rtl..GenericTableAvl* routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

By default, the operating system uses splay trees to implement generic tables, but the **RtlInsertElementGenericTableFullAvl** routine only works with Adelson-Velsky/Landis (AVL) trees. To configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the **RtlInsertElementGenericTableFullAvl** routine instead of **RtlInsertElementGenericTableFull**. In the call to **RtlInsertElementGenericTableFullAvl**, the caller must pass a [RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of **RtlInsertElementGenericTableFullAvl** must be running at IRQL < DISPATCH_LEVEL if either of the following conditions holds:

* The caller-allocated memory at *Table* or at *Buffer* is pageable.
* The caller-supplied *CompareRoutine* or *AllocateRoutine* contains pageable code.

## See also

[RtlDeleteElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldeleteelementgenerictable)

[RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable)