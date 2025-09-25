# ID3D12GraphicsCommandList4::InitializeMetaCommand

## Description

Initializes the specified meta command.

You must initialize a meta command at least once prior (on the GPU's timeline) to executing it. Initializing gives the implementation the chance to perform any work necessary to accelerate the invocation of the meta command. You must supply the sufficient resource parameters, including the persistent cache resource.

## Parameters

### `pMetaCommand` [in]

A pointer to an [ID3D12MetaCommand](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12metacommand) representing the meta command to initialize.

### `pInitializationParametersData` [in, optional]

An optional pointer to a constant structure containing the values of the parameters for initializing the meta command.

### `InitializationParametersDataSizeInBytes` [in]

A [SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) containing the size of the structure pointed to by *pInitializationParametersData*, if set, otherwise 0.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D12GraphicsCommandList4](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist4)