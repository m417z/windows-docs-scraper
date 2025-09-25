## Description

The **RtlEnumerateGenericTableWithoutSplayingAvl** routine is used to enumerate the elements in a generic table.

## Parameters

### `Table` [in]

A pointer to the generic table ([RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table)). The table must have been initialized by calling [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl).

### `RestartKey` [in, out]

An address of the element returned by the previous call to **RtlEnumerateGenericTableWithoutSplayingAvl**. Should be set to **NULL** if the enumeration is to start at the first element in the table.

To enumerate all elements in the table, use **RtlEnumerateGenericTableWithoutSplayingAvl** as follows:

```cpp
RestartKey = NULL;
for (ptr = RtlEnumerateGenericTableWithoutSplayingAvl(Table, &RestartKey);
     ptr != NULL;
     ptr = RtlEnumerateGenericTableWithoutSplayingAvl(Table, &RestartKey)) {
        // Process the element pointed to by ptr
}
```

## Return value

**RtlEnumerateGenericTableWithoutSplayingAvl** returns a pointer to the caller-defined structure associated with the element. It returns **NULL** if *RestartKey* is **NULL** and the table has no elements or if *RestartKey* is a returned pointer and there is no next element.

## Remarks

**RtlEnumerateGenericTableWithoutSplayingAvl** can be called repeatedly to process the caller's data in each element of a generic table.

Elements are return in the order returned is as defined by the *PRTL_AVL_COMPARE_ROUTINE* parameter supplied to [RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl).

By default, the operating system uses splay trees to implement generic tables, but the [RtlLookupElementGenericTableFullAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictablefullavl) routine only works with Adelson-Velsky/Landis (AVL) trees. To configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the **RtlEnumerateGenericTableWithoutSplayingAvl** routine instead of [RtlEnumerateGenericTableWithoutSplaying](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplaying). In the call to **RtlEnumerateGenericTableWithoutSplayingAvl**, the caller must pass a [RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of the* Rtl..GenericTableAvl* routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlEnumerateGenericTableWithoutSplayingAvl** must be running at IRQL < DISPATCH_LEVEL if the caller-allocated memory for the generic table is pageable.

## See also

[RtlEnumerateGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictableavl)

[RtlInitializeGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictableavl)

[RtlIsGenericTableEmptyAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableemptyavl)

[RtlNumberGenericTableElementsAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelementsavl)