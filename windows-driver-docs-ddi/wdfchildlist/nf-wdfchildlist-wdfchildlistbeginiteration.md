# WdfChildListBeginIteration function

## Description

[Applies to KMDF only]

The **WdfChildListBeginIteration** method prepares the framework for retrieving items from a specified child list.

## Parameters

### `ChildList` [in]

A handle to a framework child list object.

### `Iterator` [in]

A pointer to a caller-allocated [WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator) structure that indicates the type of child devices to be retrieved.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

After calling **WdfChildListBeginIteration**, the driver can repeatedly call [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) to obtain information about each child device in the child list.

After the driver has finished calling [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice), it must call [WdfChildListEndIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistenditeration).

If the driver makes changes to the child list after calling **WdfChildListBeginIteration**, the framework stores all of the changes and notifies the Plug and Play (PnP) manager of the changes when the driver calls [WdfChildListEndIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistenditeration).

The driver can nest calls to **WdfChildListBeginIteration** and [WdfChildListEndIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistenditeration). If the driver nests calls to these methods, the framework stores all of the changes until the last call to **WdfChildListEndIteration**.

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

For a code example that uses **WdfChildListBeginIteration**, see [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice).

## See also

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_identification_description_header_init)

[WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator)

[WDF_CHILD_LIST_ITERATOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_list_iterator_init)

[WdfChildListBeginScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginscan)

[WdfChildListEndIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistenditeration)

[WdfChildListRequestChildEject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistrequestchildeject)

[WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice)