# EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COPY callback function

## Description

[Applies to KMDF only]

A driver's *EvtChildListIdentificationDescriptionCopy* event callback function copies a child identification description from one specified location to another.

## Parameters

### `ChildList` [in]

A handle to a framework child-list object.

### `SourceIdentificationDescription` [in]

A pointer to a [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure that identifies the source location of the child identification description.

### `DestinationIdentificationDescription` [out]

A pointer to a [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure that identifies the destination location of the child identification description.

## Remarks

If a bus driver is using [dynamic enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration), it can register an *EvtChildListIdentificationDescriptionCopy* callback function by calling [WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig) or [WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate).

The framework copies information from one driver-supplied identification description to another when it needs to update an existing description with new information, or when it needs to pass the contents of an identification description to the driver.

The *EvtChildListIdentificationDescriptionCopy* callback function must copy the contents of a source description to a destination description. A driver must supply this callback function if the framework cannot call [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) to copy the identification description. (The framework cannot call **RtlCopyMemory** if the description contains pointers to additional memory.)

If your driver does not provide an *EvtChildListIdentificationDescriptionCopy* callback function, the framework copies identification descriptions by calling [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory).

The following steps describe a possible scenario:

1. The driver that is traversing a child list calls [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice). The driver supplies a [WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info) structure so that it can receive the child device's identification description.
2. The framework calls the *EvtChildListIdentificationDescriptionCopy* callback function (if it exists) or [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) to copy the device's identification description. The source of the copy operation is the framework's internal copy of the description. The destination is memory that the driver allocated and identified in its WDF_CHILD_RETRIEVE_INFO structure.

The framework can use [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) to copy an identification description, if the description consists of a single structure with a predetermined size that is specified by the **IdentificationDescriptionSize** member of the [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure. However, sometimes the description must also contain additional information that is stored in dynamically allocated memory. In this case, you will typically define a description structure so that a member points to the dynamically allocated memory, and your driver must provide an *EvtChildListIdentificationDescriptionCopy* callback function. The callback function must do the following:

1. In the callback function's *SourceIdentificationDescription* and *DestinationIdentificationDescription* structures, find the pointers to dynamically allocated memory.
2. Copy the dynamically allocated memory from the source to the destination, using the pointers.
3. Copy other structure members from the callback function's *SourceIdentificationDescription* structure to the callback function's *DestinationIdentificationDescription* structure.

The only [framework child-list object method](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/) that a driver's *EvtChildListIdentificationDescriptionCopy* callback function can call is [WdfChildListGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistgetdevice).

The framework acquires an internal child-list object lock before calling the *EvtChildListIdentificationDescriptionCopy* callback function. The callback function must only perform operations that are related to the copy operation, such as calling framework memory object methods and accessing object context space. It must not call methods that access other drivers.

If your driver supplies an *EvtChildListIdentificationDescriptionCopy* callback function, it might also need [EvtChildListIdentificationDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_duplicate), [EvtChildListIdentificationDescriptionCompare](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_compare), and [EvtChildListIdentificationDescriptionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_cleanup) callback functions.

For more information about dynamic enumeration, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

## See also

[EvtChildListIdentificationDescriptionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_cleanup)

[EvtChildListIdentificationDescriptionCompare](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_compare)

[EvtChildListIdentificationDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_duplicate)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate)

[WdfChildListGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistgetdevice)

[WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig)