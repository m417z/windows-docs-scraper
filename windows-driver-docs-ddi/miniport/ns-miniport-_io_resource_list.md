# _IO_RESOURCE_LIST structure (miniport.h)

## Description

The **IO_RESOURCE_LIST** structure describes a range of raw hardware resources, of various types, that can be used by a device. The resources specified represent a single, acceptable resource configuration for a device. An array of **IO_RESOURCE_LIST** structures is contained within each [IO_RESOURCE_REQUIREMENTS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_requirements_list) structure.

## Members

### `Version`

The version number of this structure. This value should be 1.

### `Revision`

The revision of this structure. This value should be 1.

### `Count`

The number of elements in the **Descriptors** array.

### `Descriptors`

The first element in an array of one or more [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structures.

## Remarks

This structure is the header for an array of **IO_RESOURCE_DESCRIPTOR** structures. The **Descriptors** member contains the first element in this array, and the **Count** member specifies the total number of array elements. If the array contains more than one element, the remaining elements in the array immediately follow the **IO_RESOURCE_LIST** structure in memory. The total number of bytes occupied by the **IO_RESOURCE_LIST** structure and any array elements that follow this structure is **sizeof**(**IO_RESOURCE_LIST**) + (**Count** - 1) * **sizeof**(**IO_RESOURCE_DESCRIPTOR**).

## See also

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)

[IO_RESOURCE_REQUIREMENTS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_requirements_list)