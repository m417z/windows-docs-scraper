# ID2D1EffectContext::LoadPixelShader

## Description

Loads the given shader by its unique ID. Loading the shader multiple times is ignored. When the shader is loaded it is also handed to the driver to JIT, if it hasn’t been already.

## Parameters

### `shaderId` [in]

Type: **REFGUID**

The unique id that identifies the shader.

### `shaderBuffer` [in]

Type: **const BYTE***

The buffer that contains the shader to register.

### `shaderBufferCount`

Type: **UINT32**

The size of the shader buffer in bytes.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## Remarks

The shader you specify must be compiled, not in raw HLSL code.

## See also

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)