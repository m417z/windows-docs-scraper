# EVT_WDF_CHILD_LIST_ADDRESS_DESCRIPTION_CLEANUP callback function

## Description

[Applies to KMDF only]

A driver's *EvtChildListAddressDescriptionCleanup* event callback function frees any memory allocations for an [address description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration) that the driver's [EvtChildListAddressDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_duplicate) callback function allocated.

## Parameters

### `ChildList` [in]

A handle to a framework child-list object.

### `AddressDescription` [in, out]

A pointer to a [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure that identifies an address description.

## Remarks

If a bus driver is using [dynamic enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration), it can register an *EvtChildListAddressDescriptionCleanup* callback function by calling [WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig) or [WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate).

If an address description points to additional information that is stored in dynamically allocated memory, and if that memory is allocated by an [EvtChildListAddressDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_duplicate) callback function, the driver must provide an *EvtChildListAddressDescriptionCleanup* callback function.

Typically, the [EvtChildListAddressDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_duplicate) callback function allocates memory by calling [ExAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool). The *EvtChildListAddressDescriptionCleanup* callback function must deallocate that memory by calling [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool). This callback function must not attempt to deallocate the rest of the address description. In other words, the callback function must not deallocate the address description structure that the *AddressDescription* parameter points to; it must deallocate only additional memory allocations that the description structure points to.

For more information about dynamic enumeration, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

## See also

[EvtChildListAddressDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_duplicate)

[ExAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool)

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header)

[WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate)

[WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig)