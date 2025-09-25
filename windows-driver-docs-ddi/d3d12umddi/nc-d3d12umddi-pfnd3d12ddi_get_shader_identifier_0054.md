# PFND3D12DDI_GET_SHADER_IDENTIFIER_0054 callback function

## Description

Retrieves the unique identifier for a shader that can be used in a shader record.

## Parameters

### `unnamedParam1`

A handle to a state object. The state object can be a collection or a ray tracing pipeline state object.

### `pExportName`

Entry point in the state object for which to retrieve an identifier.

## Return value

Returns a pointer to the shader identifier. If the shader isn’t fully resolved in the state object, the return value is nullptr.

## Prototype

```cpp
//Declaration

PFND3D12DDI_GET_SHADER_IDENTIFIER_0054 Pfnd3d12ddiGetShaderIdentifier0054;

// Definition

void * Pfnd3d12ddiGetShaderIdentifier0054
(
	D3D12DDI_HSTATEOBJECT_0054 Arg1
	LPCWSTR pExportName
)
{...}

```

## Remarks

The return data is valid as long as the state object it came from is valid. The size of the data returned is given by [GetShaderStackSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_get_shader_stack_size_0054) callback function. Applications should copy and cache this data to avoid the cost of searching for it in the state object if it will need to be retrieved many times. The place the identifier actually gets used is in shader records within shader tables in GPU memory, which it is up to the app to populate.

The data itself globally identifies the shader, so even if the shader appears in a different state object (with same associations like any root signatures), it will have the same identifier.

## See also