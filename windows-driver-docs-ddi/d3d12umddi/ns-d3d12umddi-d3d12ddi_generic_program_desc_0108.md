## Description

The **D3D12DDI_GENERIC_PROGRAM_DESC_0108** structure describes a generic program state subobject that contains shader exports and associated configuration subobjects within a state object. This structure defines the state subobject of type [**D3D12DDI_STATE_SUBOBJECT_TYPE_GENERIC_PROGRAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_state_subobject_type).

## Members

### `ProgramName`

A wide-character string that specifies the name of the generic program. This name is unique within the given state object and is used to identify the program.

### `NumExports`

The number of exports from the program. This value determines the number of elements in the **pExports** array. Can be 0 if the program doesn't export any shader functions.

### `pExports`

Pointer to an array of wide-character string pointers (LPCWSTR*), where each string specifies the name of an exported shader function from this program. Each export represents a shader function or entry point that can be referenced by other parts of the state object. Can be NULL if **NumExports** is 0.

### `NumSubobjects`

The number of subobjects associated with this generic program. This value determines the number of elements in the **pSubobjects** array. Can be 0 if the program doesn't have any associated subobjects.

### `pSubobjects`

Pointer to an array of pointers to [**D3D12DDI_STATE_SUBOBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_state_subobject_0054) structures. These subobjects provide additional configuration for the generic program, such as root signatures, local root signatures, or other state that applies to the program's exports. Can be NULL if **NumSubobjects** is 0.

## Remarks

A generic program is a collection of shader code with its exports and associated configuration subobjects within a state object. The runtime validates the generic program before passing this structure to the driver.

For more information, see [Generic programs](https://learn.microsoft.com/windows-hardware/drivers/display/generic-programs).

## See also

[**D3D12DDI_EXPORT_DESC_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_export_desc_0054)

[**D3D12DDI_STATE_SUBOBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_state_subobject_0054)

[**D3D12DDI_STATE_SUBOBJECT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_state_subobject_type)

[**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072)

[**PFND3D12DDI_CREATE_STATE_OBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_state_object_0054)