# _PEP_DEVICE_REGISTER_V2 structure (pepfx.h)

## Description

The **PEP_DEVICE_REGISTER** structure describes all the components in a particular device.

## Members

### `Flags`

### `ComponentCount`

The number of components in this device, which is also the number of elements in the **Components** array. The **ComponentCount** value must be greater than or equal to one.

### `Components`

The first element in an array of pointers to [PEP_COMPONENT_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_v2) structures. Each element in the array points to a structure that describes a component in the device. If this array contains more than one element, the additional elements immediately follow the end of the **PEP_DEVICE_REGISTER** structure.

## Remarks

The [PEP_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_device_v2) structure contains a **Register** member that points to a **PEP_DEVICE_REGISTER** structure.

## See also

[PEP_COMPONENT_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_component_v2)

[PEP_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_device_v2)