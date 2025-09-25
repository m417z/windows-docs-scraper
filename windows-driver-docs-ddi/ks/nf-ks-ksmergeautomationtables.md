# KsMergeAutomationTables function

## Description

The **KsMergeAutomationTables** function merges two automation tables.

## Parameters

### `AutomationTableAB` [out]

A pointer to the location at which a pointer to a [KSAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksautomation_table_) is deposited. This structure is the resulting merged automation table.

### `AutomationTableA` [in, optional]

A pointer to a [KSAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksautomation_table_) structure representing the first of the two automation tables to merge. This table is the dominant table with respect to duplicate entries. If **NULL**, *AutomationTableB* is copied into *AutomationTableAB* and optionally placed in *Bag*.

### `AutomationTableB` [in, optional]

A pointer to a [KSAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksautomation_table_) structure representing the second of the two automation tables to merge. If **NULL**, *AutomationTableA* is copied into *AutomationTableAB* and optionally placed in *Bag*.

### `Bag` [in, optional]

The newly created automation table is placed in this KSOBJECT_BAG (equivalent to type PVOID) for later clean up. This parameter is optional.

## Return value

**KsMergeAutomationTables** returns STATUS_SUCCESS if the merge successfully completes. If unsuccessful, it returns an error code. The most frequent error code is STATUS_INSUFFICIENT_RESOURCES, which indicates that there are insufficient system resources to complete the merge.

## Remarks

If both *AutomationTableA* and *AutomationTableB* are **NULL**, this routine performs no action and returns STATUS_SUCCESS.

The entries in *AutomationTableA* have priority in the merge*.* If there is an entry that appears in both *AutomationTableA* and *AutomationTableB*, the entry in *AutomationTableA* is the one that is placed into the merged table. The newly created automation table is placed in the requested object bag if one is provided.

If an input table is in an object bag at call-time, *AVStream removes the table from the object bag* before **KsMergeAutomationTables** returns.

If the *Bag* parameter is not **NULL**, the minidriver should take the mutex associated with the object bag prior to calling this routine. If the bag is associated with a pin or a filter, then the control mutex must be held. If the bag is associated with a filter factory or a device, then the device mutex should be held. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

Also see [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags) and [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables).

## See also

[KsAddItemToObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadditemtoobjectbag)

[KsCopyObjectBagItems](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscopyobjectbagitems)

[KsRemoveItemFromObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksremoveitemfromobjectbag)