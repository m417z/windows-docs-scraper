# WdfChildListBeginScan function

## Description

[Applies to KMDF only]

The **WdfChildListBeginScan** method prepares a specified list of child devices so the driver can update the information in the list.

## Parameters

### `ChildList` [in]

A handle to a framework child list object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfChildListBeginScan** method marks all of the child devices in the list as missing.

After calling **WdfChildListBeginScan**, the driver can call [WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent) repeatedly, or call [WdfChildListUpdateAllChildDescriptionsAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistupdateallchilddescriptionsaspresent), to report all of the child devices that are currently attached to the parent device.

After the driver has finished updating the child list, it must call [WdfChildListEndScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistendscan). This call delivers the updated child list to the Plug and Play (PnP) manager. Subsequently, the framework will call the driver's [EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device) callback function for each device that the driver reported.

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

For a code example that uses **WdfChildListBeginScan**, see [WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent).

## See also

[WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent)

[WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration)

[WdfChildListEndScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistendscan)

[WdfChildListUpdateAllChildDescriptionsAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistupdateallchilddescriptionsaspresent)