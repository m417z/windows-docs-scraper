## Description

The **RtlEnumerateGenericTable** routine is used to enumerate the elements in a generic table.

## Parameters

### `Table` [in]

A pointer to the generic table ([**RTL_GENERIC_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table)). The table must have been initialized by calling [RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable).

### `Restart` [in]

Set to **TRUE** if the enumeration is to start at the first element in the table. Set to **FALSE** if resuming the enumeration from a previous call.

To enumerate all elements in the table, use **RtlEnumerateGenericTable** as follows:

```cpp
for (p = RtlEnumerateGenericTable ( Table, TRUE );
     p != NULL;
     p = RtlEnumerateGenericTable ( Table, FALSE )) {
        // Process the element pointed to by p
}
```

## Return value

**RtlEnumerateGenericTable** returns a pointer to the next element, if one exists. If there are no more elements in the table, **RtlEnumerateGenericTable** returns **NULL**.

## Remarks

**RtlEnumerateGenericTable** flattens the generic table by converting it from a splay tree into a sorted linked list. To enumerate the table without flattening it, use [RtlEnumerateGenericTableWithoutSplaying](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplaying).

Callers of the *Rtl..GenericTable* routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

By default, the operating system uses splay trees to implement generic tables. Under some circumstances, operations on a splay tree will make the tree deep and narrow and might even turn it into a straight line. Very deep trees degrade the performance of searches. You can ensure a more balanced, shallower tree implementation of generic tables by using Adelson-Velsky/Landis (AVL) trees. If you want to configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *Ntddk.h*:

`#define RTL_USE_AVL_TABLES 0`

If RTL_USE_AVL_TABLES is not defined, you must use the AVL form of the generic table routines. For example, use the [RtlEnumerateGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictableavl) routine instead of **RtlEnumerateGenericTable**. In the call to **RtlEnumerateGenericTableAvl**, the caller must pass a [RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [**RTL_GENERIC_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of **RtlEnumerateGenericTable** must be running at IRQL < DISPATCH_LEVEL if the caller-allocated memory for the generic table is pageable.

## See also

[ExInitializeFastMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[RtlEnumerateGenericTableWithoutSplaying](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplaying)

[RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable)

[RtlIsGenericTableEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableempty)

[RtlNumberGenericTableElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelements)