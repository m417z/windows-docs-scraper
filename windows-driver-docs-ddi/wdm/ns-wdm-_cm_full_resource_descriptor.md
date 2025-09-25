# _CM_FULL_RESOURCE_DESCRIPTOR structure

## Description

The **CM_FULL_RESOURCE_DESCRIPTOR** structure specifies a set of system hardware resources of various types, assigned to a device that is connected to a specific bus. This structure is contained within a [CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list) structure.

## Members

### `InterfaceType`

Specifies the type of bus to which the device is connected. This must be one of the types defined by [INTERFACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_interface_type), in Wdm.h or Ntddk.h. (Not used by WDM drivers.)

### `BusNumber`

The system-assigned, driver-supplied, zero-based number of the bus to which the device is connected. (Not used by WDM drivers.)

### `PartialResourceList`

A [CM_PARTIAL_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_list) structure.

## See also

[CM_PARTIAL_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_list)

[CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list)