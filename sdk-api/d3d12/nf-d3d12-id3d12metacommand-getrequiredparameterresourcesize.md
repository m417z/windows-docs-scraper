# ID3D12MetaCommand::GetRequiredParameterResourceSize

## Description

Retrieves the amount of memory required for the specified runtime parameter resource for a meta command, for the specified stage.

## Parameters

### `Stage` [in]

Type: **D3D12_META_COMMAND_PARAMETER_STAGE**

A **D3D12_META_COMMAND_PARAMETER_STAGE** specifying the stage to which the parameter belongs.

### `ParameterIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index of the parameter within the stage.

## Return value

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of bytes required for the specified runtime parameter resource.

## See also

[ID3D12MetaCommand](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12metacommand)