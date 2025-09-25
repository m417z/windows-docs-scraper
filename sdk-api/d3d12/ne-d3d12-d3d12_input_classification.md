# D3D12_INPUT_CLASSIFICATION enumeration

## Description

Identifies the type of data contained in an input slot.

## Constants

### `D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA:0`

Input data is per-vertex data.

### `D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA:1`

Input data is per-instance data.

## Remarks

Specify one of these values in the member of a [D3D12_INPUT_ELEMENT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_input_element_desc) structure to specify the type of data for the input element of a pipeline state object.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)