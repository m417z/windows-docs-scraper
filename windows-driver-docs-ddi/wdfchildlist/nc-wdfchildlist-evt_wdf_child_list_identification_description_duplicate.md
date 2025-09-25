# EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_DUPLICATE callback function

## Description

[Applies to KMDF only]

A driver's *EvtChildListIdentificationDescriptionDuplicate* event callback function duplicates a child identification description.

## Parameters

### `ChildList` [in]

A handle to a framework child-list object.

### `SourceIdentificationDescription` [in]

A pointer to a [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure that identifies the source location of the child identification description.

### `DestinationIdentificationDescription` [out]

A pointer to a WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER structure that identifies the destination location of the duplicate child identification description.

## Return value

The *EvtChildListIdentificationDescriptionDuplicate* callback function must return STATUS_SUCCESS, or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**, if the operation succeeds. Otherwise, this callback function must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

## Remarks

If a bus driver is using [dynamic enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration), it can register an *EvtChildListIdentificationDescriptionDuplicate* callback function by calling [WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig) or [WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate).

The framework duplicates driver-supplied identification descriptions so that it can have internal copies of the descriptions.

The *EvtChildListIdentificationDescriptionDuplicate* callback function must create a duplicate copy of an identification description. A driver must supply this callback function if the framework cannot call [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) to duplicate the identification description. (The framework cannot call **RtlCopyMemory** if the description contains pointers to additional memory.)

If your driver does not provide an *EvtChildListIdentificationDescriptionDuplicate* callback function, the framework duplicates identification descriptions by calling [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory).

The following steps describe a typical scenario:

1. The driver determines that a child device exists.
2. The driver creates an identification description by filling in a driver-defined structure that contains a [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure and possibly by dynamically allocating addition memory to store identification information that has a device-specific size.
3. The driver calls [WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent) to report a child device, supplying a pointer to the identification description.
4. The framework calls the *EvtChildListIdentificationDescriptionDuplicate* callback function (if it exists) or [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) to duplicate the identification description so that it can have an internal copy of the description.

The framework can use [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) to duplicate an identification description, if the description consists of a single structure with a predetermined size that is specified by the **IdentificationDescriptionSize** member of the WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER structure. However, sometimes the description must also contain additional information that is stored in dynamically allocated memory. In this case, you will typically define a description structure so that a member points to the dynamically allocated memory, and your driver must provide an *EvtChildListIdentificationDescriptionDuplicate* callback function. The callback function must do the following:

1. Allocate additional memory, typically by calling [ExAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool).
2. Store the allocated memory's address in the driver-defined address description structure (that is, the callback function's *DestinationIdentificationDescription* structure).
3. Copy other structure members from the callback function's *SourceIdentificationDescription* structure to the callback function's *DestinationIdentificationDescription* structure.

The only [framework child-list object method](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/) that a driver's *EvtChildListIdentificationDescriptionDuplicate* callback function can call is [WdfChildListGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistgetdevice).

The framework acquires an internal child-list object lock before calling the *EvtChildListIdentificationDescriptionDuplicate* callback function. This callback function must only perform operations that are related to the duplication operation, such as calling framework memory object methods and accessing object context space. It must not call methods that access other drivers.

If your driver supplies an *EvtChildListIdentificationDescriptionDuplicate* callback function, it might also need [EvtChildListIdentificationDescriptionCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_copy), [EvtChildListIdentificationDescriptionCompare](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_compare), and [EvtChildListIdentificationDescriptionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_cleanup) callback functions.

For more information about dynamic enumeration, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

## See also

[EvtChildListIdentificationDescriptionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_cleanup)

[EvtChildListIdentificationDescriptionCompare](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_compare)

[EvtChildListIdentificationDescriptionCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_copy)

[ExAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool)

[RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent)

[WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate)

[WdfChildListGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistgetdevice)

[WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig)