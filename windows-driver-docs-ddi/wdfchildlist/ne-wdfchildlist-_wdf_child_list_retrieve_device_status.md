# _WDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS enumeration

## Description

[Applies to KMDF only]

The **WDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS** enumeration defines device status values that the framework stores in a driver's [WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info) structure.

## Constants

### `WdfChildListRetrieveDeviceUndefined:0`

### `WdfChildListRetrieveDeviceSuccess`

The [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) or [WdfChildListRetrievePdo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievepdo) method successfully retrieved a child device, and a framework device object exists for the device.

### `WdfChildListRetrieveDeviceNotYetCreated`

[WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) or [WdfChildListRetrievePdo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievepdo) successfully retrieved a child device, but a framework device object has not been created for the device (because the framework has not called the driver's [EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device) callback function).

### `WdfChildListRetrieveDeviceNoSuchDevice`

[WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) or [WdfChildListRetrievePdo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievepdo) was not able to retrieve a child device that matched the search criteria.

## Remarks

The **WDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS** enumeration is used to specify the **Status** member of a [WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info) structure.

## See also

[EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device)

[WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info)

[WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice)

[WdfChildListRetrievePdo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievepdo)