# PFND3D12DDI_CHECK_DRIVER_MATCHING_IDENTIFIER_0054 callback function

## Description

Checks the serialized driver identifier to see if it matches the specified device.

## Parameters

### `unnamedParam1`

A handle to the device.

### `unnamedParam2`

Specifies the type of serialized data.

### `unnamedParam3`

Pointer to a [D3D12DDI_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_serialized_data_driver_matching_identifier_0054) structure.

## Return value

Returns [D3D12DDI_DRIVER_MATCHING_IDENTIFIER_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_driver_matching_identifier_status) that specifies whether the device is compatible with the serialized data.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CHECK_DRIVER_MATCHING_IDENTIFIER_0054 Pfnd3d12ddiCheckDriverMatchingIdentifier0054;

// Definition

D3D12DDI_DRIVER_MATCHING_IDENTIFIER_STATUS Pfnd3d12ddiCheckDriverMatchingIdentifier0054
(
	D3D12DDI_HDEVICE Arg1
	D3D12DDI_SERIALIZED_DATA_TYPE Arg2
	CONST D3D12DDI_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER_0054 *
)
{...}

```

## Remarks

## See also