## Description

The **RtlLookupElementGenericTable** routine searches a generic table for an element that matches the specified data.

## Parameters

### `Table`

Pointer to the generic table ([**RTL_GENERIC_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table)). The table must have been initialized by calling **RtlInitializeGenericTable**.

### `Buffer`

A buffer of search data to pass to the *CompareRoutine* that was registered when [RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable) initialized the generic table. For more information, see the description of **RtlInitializeGenericTable**.

## Return value

**RtlLookupElementGenericTable** returns a pointer to the caller-supplied data for the desired element in the generic table. It returns **NULL** if the generic table currently has no elements or if no matching element is found.

## Remarks

If a matching element is found, **RtlLookupElementGenericTable** re-balances the generic table's splay tree.

Callers of the Rtl..GenericTable routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

By default, the operating system uses splay trees to implement generic tables. Under some circumstances, operations on a splay tree will make the tree deep and narrow and might even turn it into a straight line. Very deep trees degrade the performance of searches. You can ensure a more balanced, shallower tree implementation of generic tables by using Adelson-Velsky/Landis (AVL) trees. If you want to configure the generic table routines to use AVL trees instead of splay trees in your driver, insert the following define statement in a common header file before including *ntddk.h*:

```cpp
`#define RTL_USE_AVL_TABLES 0`
```

If you do not define RTL_USE_AVL_TABLES as specified above, you must use the AVL form of the generic table routines. For example, use the [RtlLookupElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictableavl) routine instead of **RtlLookupElementGenericTable**. In the call to **RtlLookupElementGenericTableAvl**, the caller must pass a [**RTL_AVL_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table) table structure rather than [RTL_GENERIC_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table).

Callers of **RtlLookupElementGenericTable** must be running at IRQL < DISPATCH_LEVEL if either of the following conditions holds:

- The caller-allocated memory at *Table* or at *Buffer* is pageable.

- The caller-supplied *CompareRoutine* contains pageable code.

Otherwise, callers of **RtlLookupElementGenericTable** can run at IRQL <= DISPATCH_LEVEL when using non-paged memory or code.

## See also

[**RTL_AVL_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table)

[**RTL_GENERIC_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_generic_table)

[RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable)

[RtlIsGenericTableEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableempty)

[RtlNumberGenericTableElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelements)