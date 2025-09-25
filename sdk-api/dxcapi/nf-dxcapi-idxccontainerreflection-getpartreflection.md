## Description

Retrieves the reflection interface for the specified part.

## Parameters

### `idx`

The index of the part to search for.

### `iid`

The IID of the interface to retrieve. Use an interface such as [ID3D12ShaderReflection](https://learn.microsoft.com/windows/win32/api/d3d12shader/nn-d3d12shader-id3d12shaderreflection).

### `ppvObject`

A pointer to the variable in which to receive the index of the matching part.

## Return value

**S_OK** on success, or **E_NOT_VALID_STATE** if a container has not been loaded by using [Load](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxccontainerreflection-load), or **E_BOUND** if *idx* is out of bounds, or another standard **HRESULT** error code.

## Remarks

## See also