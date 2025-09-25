# _WDF_RETRIEVE_CHILD_FLAGS enumeration

## Description

[Applies to KMDF only]

The **WDF_RETRIEVE_CHILD_FLAGS** enumeration defines flags that a driver can set before calling [WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration).

## Constants

### `WdfRetrieveUnspecified:0x0000`

Reserved for internal use only.

### `WdfRetrievePresentChildren:0x0001`

Calls to [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) will retrieve child devices for which a framework device object exists.

### `WdfRetrieveMissingChildren:0x0002`

Calls to [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) will retrieve child devices that are marked as missing.

### `WdfRetrievePendingChildren:0x0004`

Calls to [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) will retrieve child devices that the driver has reported as present, but for which a framework device object has not been created (because the framework has not called the driver's [EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device) callback function).

### `WdfRetrieveAddedChildren:(WdfRetrievePresentChildren` | WdfRetrievePendingChildren)

Calls to [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) will retrieve child devices that are present or pending.

### `WdfRetrieveAllChildren:(WdfRetrievePresentChildren` | WdfRetrievePendingChildren | WdfRetrieveMissingChildren)

Calls to [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) will retrieve child devices that are present, pending, or missing.

## Remarks

Before calling [WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration), your driver must set **WDF_RETRIEVE_CHILD_FLAGS**-typed flags in a [WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator) structure.

## See also

[EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device)

[WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator)

[WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration)

[WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice)