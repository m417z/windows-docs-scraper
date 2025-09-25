# IMiniport::GetDescription

## Description

The GetDescription method outputs a pointer to the miniport object's filter descriptor.

## Parameters

### `Description`

Output pointer for the filter-descriptor pointer. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the filter descriptor. The filter descriptor is a structure of type PCFILTER_DESCRIPTOR.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The miniport driver's filter descriptor is a PCFILTER_DESCRIPTOR structure that describes the KS filter that the miniport driver implements. The structure contains descriptions of the filter's pins, nodes, connections, and properties.

## See also

[IMiniPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiport)