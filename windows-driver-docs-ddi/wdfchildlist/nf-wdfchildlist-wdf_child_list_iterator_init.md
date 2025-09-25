# WDF_CHILD_LIST_ITERATOR_INIT function

## Description

[Applies to KMDF only]

The **WDF_CHILD_LIST_ITERATOR_INIT** function initializes a [WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator) structure.

## Parameters

### `Iterator` [out]

A pointer to a driver-supplied [WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator) structure.

### `Flags` [in]

A [WDF_RETRIEVE_CHILD_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ne-wdfchildlist-_wdf_retrieve_child_flags)-typed flag value.

## See also

[WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator)

[WDF_RETRIEVE_CHILD_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ne-wdfchildlist-_wdf_retrieve_child_flags)