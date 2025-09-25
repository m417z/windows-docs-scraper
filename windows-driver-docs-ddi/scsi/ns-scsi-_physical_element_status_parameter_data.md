# _PHYSICAL_ELEMENT_STATUS_PARAMETER_DATA structure

## Description

The **PHYSICAL_ELEMENT_STATUS_PARAMETER_DATA** structure contains the parameter data for a physical element.

## Members

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

[**PHYSICAL_ELEMENT_STATUS_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_physical_element_status_request)

[**PHYSICAL_ELEMENT_STATUS_DATA_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_physical_element_status_data_descriptor)