## Description

The **D3D12DDI_PROGRAM_IDENTIFIER_0108** structure describes a program identifier for a state object.

## Members

### `OpaqueData[4]`

Device-specific program identifier. This value is global in process.

## Remarks

A program identifier allows for a given state object to contain multiple programs (including work graphs) that are distingushed by their program name. It also means that programs such as work graphs can be identified on the GPU.

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**PFNDDI_GET_PROGRAM_IDENTIFIER_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_get_program_identifier_0108)