# WDF_CHILD_LIST_CONFIG_INIT function

## Description

[Applies to KMDF only]

The **WDF_CHILD_LIST_CONFIG_INIT** function initializes a [WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config) structure.

## Parameters

### `Config` [out]

A pointer to a driver-allocated [WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config) structure.

### `IdentificationDescriptionSize` [in]

The size, in bytes, of each child device's [identification description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

### `EvtChildListCreateDevice` [in]

The address of a driver-supplied [EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device) event callback function.

## Remarks

The **WDF_CHILD_LIST_CONFIG_INIT** function zeros the specified [WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config) structure and sets the structure's **Size** member. Then it sets the **IdentificationDescriptionSize** and **EvtChildListCreateDevice** members to the specified values.

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

For a code example that uses **WDF_CHILD_LIST_CONFIG_INIT**, see [WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate).

## See also

[EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device)

[WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config)