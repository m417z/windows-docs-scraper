# RtlNumberGenericTableElementsAvl function

## Description

The **RtlNumberGenericTableElementsAvl** routine returns the number of elements in a generic table.

## Parameters

### `Table` [in]

Pointer to the generic table ([RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table)). The table must have been initialized by calling [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl).

## Return value

**RtlNumberGenericTableElementsAvl** returns the number of elements that are currently stored in the table.

## Remarks

By default, the operating system uses splay trees to implement generic tables, but the **RtlNumberGenericTableElementsAvl** routine only works with Adelson-Velsky/Landis (AVL) trees. To configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the **RtlNumberGenericTableElementsAvl** routine instead of [RtlNumberGenericTableElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelements). In the call to **RtlNumberGenericTableElementsAvl**, the caller must pass a [RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of the *Rtl..GenericTableAvl* routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlNumberGenericTableElementsAvl** must be running at IRQL < DISPATCH_LEVEL if the caller-allocated memory for the generic table is pageable.

## See also

[RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl)

[RtlIsGenericTableEmptyAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableemptyavl)