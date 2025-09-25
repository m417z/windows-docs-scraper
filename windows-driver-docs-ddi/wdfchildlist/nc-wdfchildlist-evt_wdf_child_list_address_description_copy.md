# EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_COPY callback function

## Description

[Applies to KMDF only]

A driver's *EvtChildListAddressDescriptionCopy* event callback function copies a child address description from one specified location to another.

## Parameters

### `ChildList` [in]

A handle to a framework child-list object.

### `SourceAddressDescription` [in]

A pointer to a [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure that identifies the source location of the child address description.

### `DestinationAddressDescription` [out]

A pointer to a WDF_CHILD_ADDRESS_DESCRIPTION_HEADER structure that identifies the destination location of the child address description.

## Remarks

If a bus driver is using [dynamic enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration), it can register an *EvtChildListAddressDescriptionCopy* callback function by calling [WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig) or [WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate).

The framework copies information from one driver-supplied address description to another when it needs to update an existing description with new information, or when it needs to pass the contents of an address description to the driver.

The *EvtChildListAddressDescriptionCopy* callback function must copy the contents of a source description to a destination description. A driver must supply this callback function if its child devices require an address description, and if the framework cannot call [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) to copy the address description. (The framework cannot call **RtlCopyMemory** if the description contains pointers to additional memory.)

If your driver provides address descriptions but does not provide a *EvtChildListAddressDescriptionCopy* callback function, the framework copies address descriptions by calling [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory).

The following steps describe a typical scenario:

1. The driver determines that a child device exists.
2. The driver creates an address description by filling in a driver-defined structure that contains a [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure and possibly by dynamically allocating additional memory to store address information that has a device-specific size.
3. The driver calls [WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent) to report a child device, supplying a pointer to the address description.
4. The framework determines that the driver had previously reported the device, so the framework can update the device's old address description with new information.
5. The framework calls the *EvtChildListAddressDescriptionCopy* callback function (if it exists) or [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) to copy the new address description information into the existing address description.

The framework can use [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) to copy an address description, if the description consists of a single structure with a predetermined size that is specified by the **AddressDescriptionSize** member of the [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure. However, sometimes the description must also contain additional information that is stored in dynamically allocated memory. In this case, you will typically define a description structure so that a member points to the dynamically allocated memory, and your driver must provide an *EvtChildListAddressDescriptionCopy* callback function. The callback function must do the following:

1. In the callback function's *SourceAddressDescription* and *DestinationAddressDescription* structures, find the pointers to dynamically allocated memory.
2. Copy the dynamically allocated memory from the source to the destination, using the pointers.
3. Copy other structure members from the callback function's *SourceAddressDescription* structure to the callback function's *DestinationAddressDescription* structure.

The only [framework child-list object method](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/) that a driver's *EvtChildListAddressDescriptionCopy* callback function can call is [WdfChildListGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistgetdevice).

The framework acquires an internal child-list object lock before calling the *EvtChildListAddressDescriptionCopy* callback function. The callback function must only perform operations that are related to the described copy operation, such as calling framework memory object methods and accessing object context space. It must not call methods that access other drivers.

If your driver supplies an *EvtChildListAddressDescriptionCopy* callback function, it might also need [EvtChildListAddressDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_duplicate) and [EvtChildListAddressDescriptionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_cleanup) callback functions.

For more information about dynamic enumeration, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

## See also

[EvtChildListAddressDescriptionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_cleanup)

[EvtChildListAddressDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_duplicate)

[RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory)

[WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header)

[WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent)

[WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate)

[WdfChildListGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistgetdevice)

[WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig)