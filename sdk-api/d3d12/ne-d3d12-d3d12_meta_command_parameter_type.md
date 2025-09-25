# D3D12_META_COMMAND_PARAMETER_TYPE enumeration

## Description

Defines constants that specify the data type of a parameter to a meta command.

## Constants

### `D3D12_META_COMMAND_PARAMETER_TYPE_FLOAT:0`

Specifies that the parameter is of type [FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types).

### `D3D12_META_COMMAND_PARAMETER_TYPE_UINT64:1`

Specifies that the parameter is of type [UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types).

### `D3D12_META_COMMAND_PARAMETER_TYPE_GPU_VIRTUAL_ADDRESS:2`

Specifies that the parameter is a GPU virtual address.

### `D3D12_META_COMMAND_PARAMETER_TYPE_CPU_DESCRIPTOR_HANDLE_HEAP_TYPE_CBV_SRV_UAV:3`

Specifies that the parameter is a CPU descriptor handle to a heap containing either constant buffer views, shader resource views, or unordered access views.

### `D3D12_META_COMMAND_PARAMETER_TYPE_GPU_DESCRIPTOR_HANDLE_HEAP_TYPE_CBV_SRV_UAV:4`

Specifies that the parameter is a GPU descriptor handle to a heap containing either constant buffer views, shader resource views, or unordered access views.