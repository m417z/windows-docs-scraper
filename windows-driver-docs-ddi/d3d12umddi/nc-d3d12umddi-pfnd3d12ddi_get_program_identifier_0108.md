## Description

UMD's **PFND3D12DDI_GET_PROGRAM_IDENTIFIER_0108** function retrieves an identifier for a program within a state object.

## Parameters

### `unnamedParam1`

[in] A [**D3D12DDI_HSTATEOBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_state_object_0054) handle to the state object for which the program identifier is being queried.

### `pProgramName`

[in] Pointer to a string that specifies the name of the program, such as a work graph, for which to retrieve the program identifier.

## Return value

**PFND3D12DDI_GET_PROGRAM_IDENTIFIER_0108** returns a [**D3D12DDI_PROGRAM_IDENTIFIER_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_program_identifier_0108) structure that contains the program identifier for the program within the state object.

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_PROGRAM_IDENTIFIER_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_program_identifier_0108)

[**PFND3D12DDI_SET_PROGRAM_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_set_program_0108)