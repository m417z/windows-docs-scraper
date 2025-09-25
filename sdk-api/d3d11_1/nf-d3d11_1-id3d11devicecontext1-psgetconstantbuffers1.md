# ID3D11DeviceContext1::PSGetConstantBuffers1

## Description

Gets the constant buffers that the pixel shader pipeline stage uses.

## Parameters

### `StartSlot` [in]

Index into the device's zero-based array to begin retrieving constant buffers from (ranges from 0 to D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1).

### `NumBuffers` [in]

Number of buffers to retrieve (ranges from 0 to D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - *StartSlot*).

### `ppConstantBuffers` [out, optional]

Array of constant buffer interface pointers to be returned by the method.

### `pFirstConstant` [out, optional]

A pointer to an array that receives the offsets into the buffers that *ppConstantBuffers* specifies. Each offset specifies where, from the shader's point of view, each constant buffer starts. Each offset is measured in shader constants, which are 16 bytes (4*32-bit components). Therefore, an offset of 2 indicates that the start of the associated constant buffer is 32 bytes into the constant buffer. The runtime sets *pFirstConstant* to **NULL** if the buffers do not have offsets.

### `pNumConstants` [out, optional]

A pointer to an array that receives the numbers of constants in the buffers that *ppConstantBuffers* specifies. Each number specifies the number of constants that are contained in the constant buffer that the shader uses. Each number of constants starts from its respective offset that is specified in the *pFirstConstant* array. The runtime sets *pNumConstants* to **NULL** if it doesn't specify the numbers of constants in each buffer.

## Remarks

If no buffer is bound at a slot, *pFirstConstant* and *pNumConstants* are **NULL** for that slot.

## See also

[ID3D11DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11devicecontext1)