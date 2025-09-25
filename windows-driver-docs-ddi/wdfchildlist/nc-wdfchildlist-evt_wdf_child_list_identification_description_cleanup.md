# EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_CLEANUP callback function

## Description

[Applies to KMDF only]

A driver's *EvtChildListIdentificationDescriptionCleanup* event callback function frees any memory allocations for an identification description that the driver's [EvtChildListIdentificationDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_duplicate) callback function allocated.

## Parameters

### `ChildList` [in]

A handle to a framework child-list object.

### `IdentificationDescription` [in, out]

A pointer to a [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure that identifies an identification description.

## Remarks

If a bus driver is using [dynamic enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration), it can register an *EvtChildListIdentificationDescriptionCleanup* callback function by calling [WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig) or [WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate).

If an identification description points to additional information that is stored in dynamically allocated memory, and if that memory is allocated by an [EvtChildListIdentificationDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_duplicate) callback function, the driver must provide an *EvtChildListIdentificationDescriptionCleanup* callback function.

Typically, the [EvtChildListIdentificationDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_duplicate) callback function allocates memory by calling [ExAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool). The *EvtChildListIdentificationDescriptionCleanup* callback function must deallocate that memory by calling [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool). This callback function must not attempt to deallocate the rest of the identification description. In other words, the callback function must not deallocate the address description structure that the *IdentificationDescription* parameter points to; it must deallocate only additional memory allocations that the description structure points to.

For more information about dynamic enumeration, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

## See also

[EvtChildListIdentificationDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_duplicate)

[ExAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool)

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate)

[WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig)