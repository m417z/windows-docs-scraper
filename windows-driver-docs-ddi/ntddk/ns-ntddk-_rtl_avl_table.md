# _RTL_AVL_TABLE structure

## Description

The RTL_AVL_TABLE structure contains file system-specific data for an Adelson-Velsky/Landis (AVL) tree. An AVL tree ensures a more balanced, shallower tree implementation than a splay tree implementation of a generic table ([RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table)).

RTL_AVL_TABLE is opaque, so cannot be directly manipulated. Drivers must use the support routines that are described in the Remarks section to manipulate RTL_AVL_TABLE values.

## Members

### `BalancedRoot`

Reserved for system use.

### `OrderedPointer`

Reserved for system use.

### `WhichOrderedElement`

Reserved for system use.

### `NumberGenericTableElements`

Reserved for system use.

### `DepthOfTree`

Reserved for system use.

### `RestartKey`

Reserved for system use.

### `DeleteCount`

Reserved for system use.

### `CompareRoutine`

Reserved for system use.

### `AllocateRoutine`

Reserved for system use.

### `FreeRoutine`

Reserved for system use.

### `TableContext`

Reserved for system use.

## Remarks

To initialize an AVL table package, you allocate a buffer that is at least **sizeof(**RTL_AVL_TABLE**)** bytes in size. You can then use this buffer to receive the initialized AVL table structure from a call to the [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl) routine. Use the following routines to manipulate the table:

* [RtlDeleteElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldeleteelementgenerictableavl)
* [RtlEnumerateGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictableavl)
* [RtlEnumerateGenericTableLikeADirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablelikeadirectory)
* [RtlEnumerateGenericTableWithoutSplayingAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplayingavl)
* [RtlGetElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetelementgenerictableavl)
* [RtlInsertElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictableavl)
* [RtlInsertElementGenericTableFullAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictablefullavl)
* [RtlIsGenericTableEmptyAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableemptyavl)
* [RtlLookupElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictableavl)
* [RtlLookupElementGenericTableFullAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictablefullavl)
* [RtlLookupFirstMatchingElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupfirstmatchingelementgenerictableavl)
* [RtlNumberGenericTableElementsAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelementsavl)

## See also

[RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table)

[RtlDeleteElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldeleteelementgenerictableavl)

[RtlEnumerateGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictableavl)

[RtlEnumerateGenericTableLikeADirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablelikeadirectory)

[RtlEnumerateGenericTableWithoutSplayingAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplayingavl)

[RtlGetElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetelementgenerictableavl)

[RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl)

[RtlInsertElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictableavl)

[RtlInsertElementGenericTableFullAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictablefullavl)

[RtlIsGenericTableEmptyAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableemptyavl)

[RtlLookupElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictableavl)

[RtlLookupElementGenericTableFullAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictablefullavl)

[RtlLookupFirstMatchingElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupfirstmatchingelementgenerictableavl)

[RtlNumberGenericTableElementsAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelementsavl)