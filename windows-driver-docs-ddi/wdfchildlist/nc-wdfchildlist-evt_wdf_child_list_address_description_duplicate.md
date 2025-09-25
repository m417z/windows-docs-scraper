# EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_DUPLICATE callback function

## Description

[Applies to KMDF only]

A driver's *EvtChildListAddressDescriptionDuplicate* event callback function duplicates a child address description.

## Parameters

### `ChildList` [in]

A handle to a framework child-list object.

### `SourceAddressDescription` [in]

A pointer to a [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure that identifies the source location of the child address description.

### `DestinationAddressDescription` [out]

A pointer to a WDF_CHILD_ADDRESS_DESCRIPTION_HEADER structure that identifies the destination location of the child address description.

## Return value

The *EvtChildListAddressDescriptionDuplicate* callback function must return STATUS_SUCCESS, or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**, if the operation succeeds. Otherwise, this function must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

## Remarks

If a bus driver is using [dynamic enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration), it can register an *EvtChildListAddressDescriptionDuplicate* callback function by calling [WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig) or [WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate).

The framework duplicates driver-supplied address descriptions so that it can have internal copies of the descriptions.

The *EvtChildListAddressDescriptionDuplicate* callback function must create a duplicate copy of an address description. A driver must supply this callback function if its child devices require an address description, and if the framework cannot call [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) to duplicate the address description. (The framework cannot call **RtlCopyMemory** if the description contains pointers to additional memory.)

If your driver provides address descriptions but does not provide a *EvtChildListAddressDescriptionDuplicate* callback function, the framework duplicates address descriptions by calling [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory).

The following steps describe a typical scenario:

1. The driver determines that a child device exists.
2. The driver creates an address description by filling in a driver-defined structure that contains a [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure and possibly by dynamically allocating additional memory to store address information that has a device-specific size.
3. The driver calls [WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent) to report a child device, supplying a pointer to the address description.
4. The framework calls the *EvtChildListAddressDescriptionDuplicate* callback function (if it exists) or [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) to duplicate the address description so that it can have an internal copy of the description.

The framework can use [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) to duplicate an address description, if the description consists of a single structure with a predetermined size that is specified by the **AddressDescriptionSize** member of the WDF_CHILD_ADDRESS_DESCRIPTION_HEADER structure. However, sometimes the description must also contain additional information that is stored in dynamically allocated memory. In this case, you will typically define a description structure so that a member points to the dynamically allocated memory, and your driver must provide an *EvtChildListAddressDescriptionDuplicate* callback function. The callback function must do the following:

1. Allocate additional memory, typically by calling [ExAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool).
2. Store the allocated memory's address in the driver-defined address description structure (that is, the callback function's *DestinationAddressDescription* structure).
3. Copy other structure members from the callback function's *SourceAddressDescription* structure to the callback function's *DestinationAddressDescription* structure.

The only [framework child-list object method](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/) that a driver's *EvtChildListAddressDescriptionDuplicate* callback function can call is [WdfChildListGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistgetdevice).

The framework acquires an internal child-list object lock before calling the *EvtChildListAddressDescriptionDuplicate* callback function. The callback function must only perform operations that are related to the described duplication operation, such as calling framework memory object methods and accessing object context space. It must not call methods that access other drivers.

If your driver supplies an *EvtChildListAddressDescriptionDuplicate* callback function, it might also need [EvtChildListAddressDescriptionCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_copy) and [EvtChildListAddressDescriptionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_cleanup) callback functions.

For more information about dynamic enumeration, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

## See also

[EvtChildListAddressDescriptionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_cleanup)

[ExAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool)

[RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory)

[WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header)

[WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent)

[WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate)

[WdfChildListGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistgetdevice)

[WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig)