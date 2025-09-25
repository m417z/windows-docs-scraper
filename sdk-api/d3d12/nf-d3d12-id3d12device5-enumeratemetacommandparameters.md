# ID3D12Device5::EnumerateMetaCommandParameters

## Description

Queries reflection metadata about the parameters of the specified meta command.

## Parameters

### `CommandId` [in]

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the meta command whose parameters you wish to be returned in *pParameterDescs*.

### `Stage` [in]

Type: **D3D12_META_COMMAND_PARAMETER_STAGE**

A [D3D12_META_COMMAND_PARAMETER_STAGE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_meta_command_parameter_stage) specifying the stage of the parameters that you wish to be included in the query.

### `pTotalStructureSizeInBytes` [out, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

An optional pointer to a [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) containing the size of the structure containing the parameter values, which you pass when creating/initializing/executing the meta command, as appropriate.

### `pParameterCount` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) containing the number of parameters to query for. This field determines the size of the *pParameterDescs* array, unless *pParameterDescs* is **nullptr**.

### `pParameterDescs` [out, optional]

Type: **D3D12_META_COMMAND_PARAMETER_DESC***

An optional pointer to an array of [D3D12_META_COMMAND_PARAMETER_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_meta_command_parameter_desc) containing the descriptions of the parameters. Pass **nullptr** to have the parameter count returned in *pParameterCount*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D12Device5](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device5)