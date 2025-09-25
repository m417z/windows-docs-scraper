# ID3D12StateObjectProperties::GetShaderIdentifier

## Description

Retrieves the unique identifier for a shader that can be used in a shader record.

## Parameters

### `pExportName`

Entrypoint in the state object for which to retrieve an identifier.

## Return value

A pointer to the shader identifier.

The data referenced by this pointer is valid as long as the state object it came from is valid. The size of the data returned is [D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES](https://learn.microsoft.com/windows/desktop/direct3d12/constants). Applications should copy and cache this data to avoid the cost of searching for it in the state object if it will need to be retrieved many times. The identifier is used in shader records within shader tables in GPU memory, which the app must populate.

The data itself globally identifies the shader, so even if the shader appears in a different state object with same associations, like any root signatures, it will have the same identifier.

If the shader isn’t fully resolved in the state object, the return value is **nullptr**.

## See also

[ID3D12StateObjectProperties](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12stateobjectproperties)