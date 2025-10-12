# _RTL_GENERIC_TABLE structure

## Description

The RTL_GENERIC_TABLE structure contains file system-specific data for a splay tree.

RTL_GENERIC_TABLE is opaque and not directly manipulated. Drivers must use the support routines that are described in the Remarks section to manipulate RTL_GENERIC_TABLE values.

## Members

### `TableRoot`

Reserved for system use.

### `InsertOrderList`

Reserved for system use.

### `OrderedPointer`

Reserved for system use.

### `WhichOrderedElement`

Reserved for system use.

### `NumberGenericTableElements`

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

To initialize a generic table package, you allocate a buffer that is at least **sizeof(**RTL_GENERIC_TABLE**)** bytes in size to receive the initialized generic table structure from a call to the [RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable) routine. You can use the following routines to manipulate the table:

* [RtlDeleteElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldeleteelementgenerictable)
* [RtlEnumerateGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictable)
* [RtlEnumerateGenericTableWithoutSplaying](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplaying)
* [RtlGetElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetelementgenerictable)
* [RtlInsertElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictable)
* [RtlInsertElementGenericTableFullAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictablefullavl)
* [RtlIsGenericTableEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableempty)
* [RtlLookupElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictable)
* [RtlLookupElementGenericTableFullAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictablefullavl)
* [RtlNumberGenericTableElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelements)

## See also

[RtlDeleteElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldeleteelementgenerictable)

[RtlEnumerateGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictable)

[RtlEnumerateGenericTableWithoutSplaying](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictablewithoutsplaying)

[RtlGetElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetelementgenerictable)

[RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable)

[RtlInsertElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictable)

[RtlInsertElementGenericTableFullAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictablefullavl)

[RtlIsGenericTableEmpty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisgenerictableempty)

[RtlLookupElementGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictable)

[RtlLookupElementGenericTableFullAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictablefullavl)

[RtlNumberGenericTableElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelements)