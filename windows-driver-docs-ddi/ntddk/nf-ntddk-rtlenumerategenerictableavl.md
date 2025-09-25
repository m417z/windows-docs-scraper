## Description

The **RtlEnumerateGenericTableAvl** routine is used to enumerate the elements in a generic table.

## Parameters

### `Table` [in]

A pointer to the generic table ([RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table)). The table must have been initialized by calling [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl).

### `Restart` [in]

Set to **TRUE** if the enumeration is to start at the first element in the table. Set to **FALSE** if resuming the enumeration from a previous call.

To enumerate all elements in the table, use **RtlEnumerateGenericTableAvl** as follows:

```cpp
for (p = RtlEnumerateGenericTableAvl ( Table, TRUE );
     p != NULL;
     p = RtlEnumerateGenericTableAvl ( Table, FALSE )) {
        // Process the element pointed to by p
}
```

## Return value

**RtlEnumerateGenericTableAvl** returns a pointer to the next element, if one exists. If there are no more elements in the table, **RtlEnumerateGenericTableAvl** returns **NULL**.

## Remarks

Callers of the *Rtl..GenericTableAvl* routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

By default, the operating system uses splay trees to implement generic tables, but the **RtlEnumerateGenericTableAvl** routine only works with Adelson-Velsky/Landis (AVL) trees. To configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the **RtlEnumerateGenericTableAvl** routine instead of [RtlEnumerateGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictable). In the call to **RtlEnumerateGenericTableAvl**, the caller must pass a [RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of **RtlEnumerateGenericTableAvl** must be running at IRQL < DISPATCH_LEVEL if the caller-allocated memory for the generic table is pageable.

## See also

[ExInitializeFastMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[RtlEnumerateGenericTableWithoutSplayingAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplayingavl)

[RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl)

[RtlIsGenericTableEmptyAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableemptyavl)

[RtlNumberGenericTableElementsAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelementsavl)