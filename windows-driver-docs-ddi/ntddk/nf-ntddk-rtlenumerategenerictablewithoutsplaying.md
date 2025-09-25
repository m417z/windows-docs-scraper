## Description

The **RtlEnumerateGenericTableWithoutSplaying** routine is used to enumerate the elements in a generic table.

## Parameters

### `Table` [in]

A pointer to the generic table ([RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table)). The table must have been initialized by calling [RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable).

### `RestartKey` [in, out]

An address of the element returned by the previous call to **RtlEnumerateGenericTableWithoutSplaying**. Should be set to **NULL** if the enumeration is to start at the first element in the table.

To enumerate all elements in the table, use **RtlEnumerateGenericTableWithoutSplaying** as follows:

```cpp
RestartKey = NULL;
for (ptr = RtlEnumerateGenericTableWithoutSplaying(Table, &RestartKey);
     ptr != NULL;
     ptr = RtlEnumerateGenericTableWithoutSplaying(Table, &RestartKey)) {
        // Process the element pointed to by ptr
}
```

## Return value

**RtlEnumerateGenericTableWithoutSplaying** returns a pointer to the caller-defined structure associated with the element. It returns **NULL** if *RestartKey* is **NULL** and the table has no elements or if *RestartKey* is a returned pointer and there is no next element.

## Remarks

Unlike [RtlEnumerateGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictable), **RtlEnumerateGenericTableWithoutSplaying** does not flatten the generic table by converting it from a splay tree into a sorted linked list. **RtlEnumerateGenericTableWithoutSplaying** is more efficient and multiprocessor-safe than **RtlEnumerateGenericTable**.

**RtlEnumerateGenericTableWithoutSplaying** can be called repeatedly to process the caller's data in each element of a generic table.

Callers of the *Rtl..GenericTable* routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

By default, the operating system uses splay trees to implement generic tables. Under some circumstances, operations on a splay tree will make the tree deep and narrow and might even turn it into a straight line. Very deep trees degrade the performance of searches. You can ensure a more balanced, shallower tree implementation of generic tables by using Adelson-Velsky/Landis (AVL) trees. If you want to configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the **RtlEnumerateGenericTableWithoutSplaying** routine instead of [RtlEnumerateGenericTableWithoutSplayingAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplayingavl). In the call to **RtlEnumerateGenericTableWithoutSplayingAvl**, the caller must pass a [RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of **RtlEnumerateGenericTableWithoutSplaying** must be running at IRQL < DISPATCH_LEVEL if the caller-allocated memory for the generic table is pageable.

## See also

[RtlEnumerateGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictable)

[RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable)

[RtlIsGenericTableEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableempty)

[RtlNumberGenericTableElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelements)