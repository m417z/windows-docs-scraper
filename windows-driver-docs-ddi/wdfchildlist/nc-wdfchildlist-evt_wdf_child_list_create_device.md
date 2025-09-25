# EVT_WDF_CHILD_LIST_CREATE_DEVICE callback function

## Description

[Applies to KMDF only]

A bus driver's *EvtChildListCreateDevice* event callback function creates a framework device object for a new device that has been dynamically enumerated.

## Parameters

### `ChildList` [in]

A handle to the framework child-list object that the driver specified when it called [WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent).

### `IdentificationDescription` [in]

A pointer to a copy of the [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure that the driver specified when it called [WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent).

### `ChildInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

## Return value

The *EvtChildListCreateDevice* callback function must return STATUS_SUCCESS, or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**, if the operation succeeds. Otherwise, this function must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

If the operation failed but you think your driver should try again later, and if the driver's *EvtChildListCreateDevice* callback function has not called [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), the driver can return STATUS_RETRY. As a result, the framework calls the *EvtChildListCreateDevice* callback function again later. If your driver returns STATUS_RETRY more than a few times, the framework will stop calling the callback function for the failing device.

## Remarks

If a bus driver is using [dynamic enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration), it can register an *EvtChildListCreateDevice* callback function by calling [WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig) or [WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate).

After a driver calls [WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent) or [WdfChildListUpdateAllChildDescriptionsAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistupdateallchilddescriptionsaspresent), the framework calls the driver's *EvtChildListCreateDevice* callback function. The callback function must call [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) to create a framework device object (a PDO).

Before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), the driver must call framework-supplied functions that initialize the WDFDEVICE_INIT structure. For more information about these functions, see [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init).

For more information about calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

For more information about dynamic enumeration, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

## See also

[WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent)

[WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate)

[WdfChildListUpdateAllChildDescriptionsAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistupdateallchilddescriptionsaspresent)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig)