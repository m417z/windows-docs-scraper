## Description

Instantiates an a Media Foundation D3D12 synchronization primitive used to synchronize access to a D3D12 resource stored in an Media Foundation object.

## Parameters

### `pDevice`

The [ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device) associated with the resource and primitive being created.

### `riid`

The GUID identifying the interface of the synchronization object that will be created.

### `ppvSyncObject`

Receives a **void\*\*** pointing to the created synchronization object.

## Return value

An HRESULT including but not limited to the following values:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| MF_E_OPERATION_UNSUPPORTED_AT_D3D_FEATURE_LEVEL | The attempted call or command is not supported with the DirectX version used by the component. |
| o MF_E_UNSUPPORTED_MEDIATYPE_AT_D3D_FEATURE_LEVEL | The specified media type is not supported with the DirectX version used by the component. |

## Remarks

## See also