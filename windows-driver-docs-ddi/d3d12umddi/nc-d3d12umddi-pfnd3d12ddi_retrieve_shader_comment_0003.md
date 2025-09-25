# PFND3D12DDI_RETRIEVE_SHADER_COMMENT_0003 callback function

## Description

Implemented by the client driver to retrieve shader comment.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A handle to a pipeline state.

### `pBuffer`

Pointer to a buffer.

### `CharacterCountIncludingNullTerminator`

The character count, including the null terminator.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_RETRIEVE_SHADER_COMMENT_0003 Pfnd3d12ddiRetrieveShaderComment0003;

// Definition

HRESULT Pfnd3d12ddiRetrieveShaderComment0003
(
	 D3D12DDI_HDEVICE
	 D3D12DDI_HPIPELINESTATE
	WCHAR *pBuffer
	SIZE_T *CharacterCountIncludingNullTerminator
)
{...}

PFND3D12DDI_RETRIEVE_SHADER_COMMENT_0003

```

## Remarks

## See also