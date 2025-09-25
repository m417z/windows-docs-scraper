# WdfChildListEndIteration function

## Description

[Applies to KMDF only]

The **WdfChildListEndIteration** method processes modifications to a specified child list.

## Parameters

### `ChildList` [in]

The same handle to a framework child-list object that the driver previously specified to [WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration).

### `Iterator` [in]

A pointer to the same caller-allocated [WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator) structure that the driver previously supplied to **WdfChildListEndIteration**.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If the driver has made multiple calls to [WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration) or [WdfChildListBeginScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginscan), the framework does not process modifications to the child list until the driver has made a corresponding number of calls to **WdfChildListEndIteration** and [WdfChildListEndScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistendscan).

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

For a code example that uses **WdfChildListEndIteration**, see [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice).

## See also

[WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator)

[WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration)

[WdfChildListBeginScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginscan)

[WdfChildListEndScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistendscan)