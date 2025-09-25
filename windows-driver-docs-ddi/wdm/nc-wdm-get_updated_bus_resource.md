## Description

Reports the latest resource lists.

## Parameters

### `Context` [In]

A pointer to interface-specific context information. For this parameter, the caller supplies the value from the **Context** member of the [**BUS_RESOURCE_UPDATE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_resource_update_interface) structure for the interface.

### `UpdatedResourceList` [Out]

A pointer to the resource list in [**CM_RESOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list) structures that the driver used to detect the device. Resources in this list are in raw, untranslated form.

### `UpdatedTranslatedResourceList` [Out]

A pointer to the resource list in [**CM_RESOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list) structures. Resources in this list are translated.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The Pnp Manager invokes this callback function to query the bus driver for the latest resources.

Register the bus driver's implementation of this callback function by setting the **PGET_UPDATED_BUS_RESOURCE** member of [**BUS_RESOURCE_UPDATE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_resource_update_interface).

## See also