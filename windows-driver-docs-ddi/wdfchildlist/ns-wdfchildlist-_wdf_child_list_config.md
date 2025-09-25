# _WDF_CHILD_LIST_CONFIG structure

## Description

[Applies to KMDF only]

The **WDF_CHILD_LIST_CONFIG** structure contains configuration information for a list of child devices.

## Members

### `Size`

The size, in bytes, of this structure.

### `IdentificationDescriptionSize`

The size, in bytes, of each child's [identification description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration). For more information, see [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header).

### `AddressDescriptionSize`

The size, in bytes, of each child's [address description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration). For more information, see [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header).

### `EvtChildListCreateDevice`

A pointer to the driver's [EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device) event callback function. This callback function is required.

### `EvtChildListScanForChildren`

A pointer to the driver's [EvtChildListScanForChildren](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_scan_for_children) event callback function. This callback function is optional.

### `EvtChildListIdentificationDescriptionCopy`

A pointer to the driver's [EvtChildListIdentificationDescriptionCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_copy) event callback function. This callback function is optional.

### `EvtChildListIdentificationDescriptionDuplicate`

A pointer to the driver's [EvtChildListIdentificationDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_duplicate) event callback function. This callback function is optional.

### `EvtChildListIdentificationDescriptionCleanup`

A pointer to the driver's [EvtChildListIdentificationDescriptionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_cleanup) event callback function. This callback function is optional.

### `EvtChildListIdentificationDescriptionCompare`

A pointer to the driver's [EvtChildListIdentificationDescriptionCompare](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_compare) event callback function. This callback function is optional.

### `EvtChildListAddressDescriptionCopy`

A pointer to the driver's [EvtChildListAddressDescriptionCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_copy) event callback function. This callback function is optional.

### `EvtChildListAddressDescriptionDuplicate`

A pointer to the driver's [EvtChildListAddressDescriptionDuplicate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_duplicate) event callback function. This callback function is optional.

### `EvtChildListAddressDescriptionCleanup`

A pointer to the driver's [EvtChildListAddressDescriptionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_address_description_cleanup) event callback function. This callback function is optional.

### `EvtChildListDeviceReenumerated`

A pointer to the driver's [EvtChildListDeviceReenumerated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_device_reenumerated) event callback function. This callback function is optional.

## Remarks

The **WDF_CHILD_LIST_CONFIG** structure is used as input to the [WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig) and [WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate) methods.

To initialize a WDF_CHILD_LIST_CONFIG structure, the driver must call [WDF_CHILD_LIST_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_list_config_init).

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

## See also

[WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WDF_CHILD_LIST_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_list_config_init)

[WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate)

[WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig)