# _WDF_CHILD_RETRIEVE_INFO structure

## Description

[Applies to KMDF only]

The WDF_CHILD_RETRIEVE_INFO structure contains information about a child device that is obtained by calling [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) or [WdfChildListRetrievePdo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievepdo).

## Members

### `Size`

The size, in bytes, of this structure.

### `IdentificationDescription`

A pointer to a driver-allocated [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure. The driver must supply a value for this structure's **IdentificationDescriptionSize** member.

If the driver is calling [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) and supplying an [EvtChildListIdentificationDescriptionCompare](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_compare) callback function, the driver must also provide an [identification description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration) that the callback function can use to compare with an entry in a child list.

If the driver is calling [WdfChildListRetrievePdo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievepdo), the driver must fill in the entire identification description.

### `AddressDescription`

A pointer to a driver-allocated [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure. The driver must supply a value for this structure's **AddressDescriptionSize** member. The framework fills in the rest of the [address description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration) when it retrieves a child from the child list. If the value of **AddressDescriptionSize** is **NULL**, address description information is not retrieved.

### `Status`

A [WDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ne-wdfchildlist-_wdf_child_list_retrieve_device_status)-typed value that the framework provides.

### `EvtChildListIdentificationDescriptionCompare`

A driver-supplied pointer to an [EvtChildListIdentificationDescriptionCompare](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_compare) callback function.

If the driver is calling [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice), this pointer is optional and can be **NULL**.

If the driver is calling [WdfChildListRetrievePdo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievepdo), this pointer is not used.

## Remarks

The WDF_CHILD_RETRIEVE_INFO structure is passed to the [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) and [WdfChildListRetrievePdo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievepdo) methods.

To initialize a WDF_CHILD_RETRIEVE_INFO structure, the driver must call [WDF_CHILD_RETRIEVE_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_retrieve_info_init).

## See also

[EvtChildListIdentificationDescriptionCompare](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_compare)

[WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WDF_CHILD_LIST_RETRIEVE_DEVICE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ne-wdfchildlist-_wdf_child_list_retrieve_device_status)

[WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice)

[WdfChildListRetrievePdo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievepdo)