# RtlIsGenericTableEmpty function

## Description

The **RtlIsGenericTableEmpty** routine determines if a generic table is empty.

## Parameters

### `Table` [in]

Pointer to the generic table ([RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table)). The table must have been initialized by calling [RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable).

## Return value

**RtlIsGenericTableEmpty** returns **FALSE** if the table contains one or more elements, **TRUE** otherwise.

## Remarks

By default, the operating system uses splay trees to implement generic tables. Under some circumstances, operations on a splay tree will make the tree deep and narrow and might even turn it into a straight line. Very deep trees degrade the performance of searches. You can ensure a more balanced, shallower tree implementation of generic tables by using Adelson-Velsky/Landis (AVL) trees. If you want to configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the [RtlIsGenericTableEmptyAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableemptyavl) Structure routine instead of **RtlIsGenericTableEmpty**. In the call to [RtlIsGenericTableEmptyAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableemptyavl), the caller must pass a **RTL_AVL_TABLE** table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of **RtlIsGenericTableEmpty** must be running at ≤ APC_LEVEL if the caller-allocated memory at *Table* is pageable.

## See also

[RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable)