# _PHYSICAL_ELEMENT_STATUS structure

## Description

The **PHYSICAL_ELEMENT_STATUS** structure defines the output buffer for [**IOCTL_STORAGE_GET_PHYSICAL_ELEMENT_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_physical_element_status).

## Members

### `Version`

Specifies the version of this structure.

### `Size`

Specifies the size of this structure, in bytes.

### `DescriptorCount`

Specifies the number of descriptors in the element descriptors list given as input in [**PHYSICAL_ELEMENT_STATUS_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_physical_element_status_request).

### `ReturnedDescriptorCount`

Specifies the number of valid descriptors returned.

### `ElementIdentifierBeingDepoped`

Specifies the element identifier of a de-popped descriptor.

### `Reserved`

Reserved for future use.

### `Descriptors`

The valid descriptors sorted in ascending order based on the element identifier.

## Remarks

## See also

[**IOCTL_STORAGE_GET_PHYSICAL_ELEMENT_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_physical_element_status)

[**PHYSICAL_ELEMENT_STATUS_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_physical_element_status_request)

[**PHYSICAL_ELEMENT_STATUS_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_physical_element_status_descriptor)