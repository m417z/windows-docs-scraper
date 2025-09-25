# D3D12_INPUT_LAYOUT_DESC structure

## Description

Describes the input-buffer data for the input-assembler stage.

## Members

### `pInputElementDescs`

An array of [D3D12_INPUT_ELEMENT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_input_element_desc) structures that describe the data types of the input-assembler stage.

### `NumElements`

The number of input-data types in the array of input elements that the **pInputElementDescs** member points to.

## Remarks

This structure is a member of the [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) structure.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)