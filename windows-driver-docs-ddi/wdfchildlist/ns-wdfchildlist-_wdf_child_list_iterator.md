# _WDF_CHILD_LIST_ITERATOR structure

## Description

[Applies to KMDF only]

The **WDF_CHILD_LIST_ITERATOR** structure identifies the type of child devices that the framework will retrieve when a driver calls [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice).

## Members

### `Size`

The size, in bytes, of this structure.

### `Flags`

One or more flags that are defined by the [WDF_RETRIEVE_CHILD_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ne-wdfchildlist-_wdf_retrieve_child_flags) enumeration.

### `Reserved`

Reserved for internal use only.

## Remarks

The driver must initialize the **WDF_CHILD_LIST_ITERATOR** structure by calling [WDF_CHILD_LIST_ITERATOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_list_iterator_init).

The WDF_CHILD_LIST_ITERATOR structure is used as input to the [WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration),[WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) ,and [WdfChildListEndIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistenditeration) methods. The driver must set the **Flags** member before calling **WdfChildListBeginIteration**. After calling **WdfChildListBeginIteration**, the driver must not modify the structure's contents until after calling **WdfChildListEndIteration**.

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

## See also

[WDF_CHILD_LIST_ITERATOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_list_iterator_init)

[WDF_RETRIEVE_CHILD_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ne-wdfchildlist-_wdf_retrieve_child_flags)

[WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration)

[WdfChildListEndIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistenditeration)

[WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice)