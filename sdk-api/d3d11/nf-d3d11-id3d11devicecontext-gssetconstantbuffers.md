# ID3D11DeviceContext::GSSetConstantBuffers

## Description

Sets the constant buffers used by the geometry shader pipeline stage.

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into the device's zero-based array to begin setting constant buffers to (ranges from 0 to **D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT** - 1).

### `NumBuffers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of buffers to set (ranges from 0 to **D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT** - *StartSlot*).

### `ppConstantBuffers` [in, optional]

Type: **[ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)***

Array of constant buffers (see [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)) being given to the device.

## Remarks

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

You can't use the [ID3D11ShaderReflectionConstantBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionconstantbuffer) interface to get information about what is currently bound to the pipeline in the device context. But you can use **ID3D11ShaderReflectionConstantBuffer** to get information from a compiled shader. For example, you can use **ID3D11ShaderReflectionConstantBuffer** and [ID3D11ShaderReflectionVariable](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflectionvariable) to determine the slot in which a geometry shader expects a constant buffer. You can then pass this slot number to **GSSetConstantBuffers** to set the constant buffer. You can call the [D3D11Reflect](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3d11reflect) function to retrieve the address of a pointer to the [ID3D11ShaderReflection](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11shaderreflection) interface and then call [ID3D11ShaderReflection::GetConstantBufferByName](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11shaderreflection-getconstantbufferbyname) to get a pointer to **ID3D11ShaderReflectionConstantBuffer**.

The Direct3D 11.1 runtime, which is available starting with Windows 8, can bind a larger number of [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer) resources to the shader than the maximum constant buffer size that is supported by shaders (4096 constants – 4*32-bit components each). When you bind such a large buffer, the shader can access only the first 4096 4*32-bit component constants in the buffer, as if 4096 constants is the full size of the buffer.

If the application wants the shader to access other parts of the buffer, it must call the [GSSetConstantBuffers1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-gssetconstantbuffers1) method instead.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)