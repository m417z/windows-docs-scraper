# EVT_WDF_CHILD_LIST_DEVICE_REENUMERATED callback function

## Description

[Applies to KMDF only]

A driver's *EvtChildListDeviceReenumerated* event callback function enables the driver to approve or cancel a reenumeration of a specified device.

## Parameters

### `ChildList` [in]

A handle to a framework child list object.

### `OldDevice` [in]

A handle to a framework device object.

### `OldAddressDescription` [in]

Optional pointer to a [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure that identifies a child address description, or NULL. If provided, this structure contains address information that was relevant before the device was reenumerated.

### `NewAddressDescription` [out]

Optional pointer to a [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure that identifies a child address description, or NULL. If provided, the callback function fills in this structure with new address information about the device.

## Return value

The *EvtChildListDeviceReenumerated* callback function returns **TRUE** to approve the reenumeration or **FALSE** to cancel it.

## Remarks

If a bus driver is using [dynamic enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration), it can register an *EvtChildListDeviceReenumerated* callback function by calling [WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig) or [WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate).

Framework-based bus drivers can receive a request from a function driver to reenumerate a particular child device. For more information about these requests, see [Handling Enumeration Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-enumeration-requests).

The bus driver's *EvtChildListDeviceReenumerated* callback function enables the driver to approve or cancel the reenumeration. The *OldDevice* parameter identifies the device, and the *ChildList* parameter identifies the child list that the device is a member of. If the callback function returns **TRUE** to approve the reenumeration, or if the callback function does not exist, the framework does the following:

1. Removes the device's framework device object (which is identified by *OldDevice*) but retains the device's identification description.
2. Calls the driver's [EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device) callback function, passing the saved identification description, so that the callback function can call [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) to create a new framework device object.

If the bus driver uses address descriptions, the *EvtChildListDeviceReenumerated* callback function receives pointers to two address descriptions. One points to the address description that is associated with the old device object. The other points to an address description that the callback function must fill in with information that describes the device's current location.

For more information about dynamic enumeration, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

## See also

[EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device)

[WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header)

[WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig)