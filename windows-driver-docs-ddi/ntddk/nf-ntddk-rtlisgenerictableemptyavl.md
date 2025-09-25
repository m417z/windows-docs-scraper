# RtlIsGenericTableEmptyAvl function

## Description

The **RtlIsGenericTableEmptyAvl** routine determines if a generic table is empty.

## Parameters

### `Table` [in]

Pointer to the generic table ([RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table)). The table must have been initialized by calling **RtlIsGenericTableEmptyAvl**.

## Return value

**RtlIsGenericTableEmptyAvl** returns **FALSE** if the table contains one or more elements, **TRUE** otherwise.

## Remarks

By default, the operating system uses splay trees to implement generic tables, but the **RtlIsGenericTableEmptyAvl** routine only works with Adelson-Velsky/Landis (AVL) trees. To configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the **RtlIsGenericTableEmptyAvl** routine instead of [RtlIsGenericTableEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableempty). In the call to **RtlIsGenericTableEmptyAvl**, the caller must pass a [RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of **RtlIsGenericTableEmptyAvl** must be running at ≤ APC_LEVEL if the caller-allocated memory at *Table* is pageable.

## See also

[RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl)