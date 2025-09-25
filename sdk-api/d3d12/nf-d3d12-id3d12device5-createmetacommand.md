## Description

Creates an instance of the specified meta command.

## Parameters

### `CommandId` [in]

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the meta command that you wish to instantiate.

### `NodeMask` [in]

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

For single-adapter operation, set this to zero. If there are multiple adapter nodes, set a bit to identify the node (one of the device's physical adapters) to which the meta command applies. Each bit in the mask corresponds to a single node. Only one bit must be set. See [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

### `pCreationParametersData` [in, optional]

Type: **const [void](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)***

An optional pointer to a constant structure containing the values of the parameters for creating the meta command.

### `CreationParametersDataSizeInBytes` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

A [SIZE_T](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types) containing the size of the structure pointed to by *pCreationParametersData*, if set, otherwise 0.

### `riid`

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the interface that you wish to be returned in *ppMetaCommand*. This is expected to be the GUID of [ID3D12MetaCommand](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12metacommand).

### `ppMetaCommand` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the meta command. This is the address of a pointer to an [ID3D12MetaCommand](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12metacommand), representing the meta command created.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return value | Description |
| --- | --- |
| DXGI_ERROR_UNSUPPORTED | The current hardware does not support the algorithm being requested |

## See also

[ID3D12Device5](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device5)