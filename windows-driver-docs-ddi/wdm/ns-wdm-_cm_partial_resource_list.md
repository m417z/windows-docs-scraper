## Description

The **CM_PARTIAL_RESOURCE_LIST** structure specifies a set of system hardware resources, of various types, assigned to a device. This structure is contained within a [CM_FULL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_full_resource_descriptor) structure.

## Members

### `Version`

The version number of this structure. This value should be 1.

### `Revision`

The revision of this structure. This value should be 1.

### `Count`

The number of elements contained in the **PartialDescriptors** array.

### `PartialDescriptors`

The first element in an array of one or more [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structures.

## Remarks

This structure is the header for an array of **CM_PARTIAL_RESOURCE_DESCRIPTOR** structures. The **PartialDescriptors** member contains the first element in this array, and the **Count** member specifies the total number of array elements. If the array contains more than one element, the remaining elements in the array immediately follow the **CM_PARTIAL_RESOURCE_LIST** structure in memory. The total number of bytes occupied by the **CM_PARTIAL_RESOURCE_LIST** structure and any array elements that follow this structure is **sizeof**(**CM_PARTIAL_RESOURCE_LIST**) + (**Count** - 1) * **sizeof**(**CM_PARTIAL_RESOURCE_DESCRIPTOR**).

If the last **CM_PARTIAL_RESOURCE_DESCRIPTOR** in the **CM_PARTIAL_RESOURCE_LIST** has a Type of **CmResourceTypeDeviceSpecific**, then you need to add the size of the device specific data block to the total above.

## See also

[CM_FULL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_full_resource_descriptor)

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)