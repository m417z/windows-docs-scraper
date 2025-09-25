# D3DKMT_CLIENTHINT enumeration

## Description

D3DKMT_CLIENTHINT hints at which client is [creating a device context](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createcontext).

## Constants

### `D3DKMT_CLIENTHINT_UNKNOWN:0`

The client is unknown.

### `D3DKMT_CLIENTHINT_OPENGL:1`

The client is the OpenGL runtime.

### `D3DKMT_CLIENTHINT_CDD:2`

CDD (Canonical Display Driver). This value is reserved for internal use.

### `D3DKMT_CLIENTHINT_OPENCL:3`

The client is OpenCL (Open Computing Language).

### `D3DKMT_CLIENTHINT_VULKAN:4`

The client is Vulkan.

### `D3DKMT_CLIENTHINT_CUDA:5`

The client is CUDA (Compute Unified Device Architecture).

### `D3DKMT_CLIENTHINT_RESERVED:6`

Reserved.

### `D3DKMT_CLIENTHINT_DX7:7`

The client is the DirectX 7.0 runtime.

### `D3DKMT_CLIENTHINT_DX8:8`

The client is the DirectX 8.0 runtime.

### `D3DKMT_CLIENTHINT_DX9:9`

The client is the DirectX 9.0 runtime.

### `D3DKMT_CLIENTHINT_DX10:10`

The client is the DirectX 10.0 runtime.

### `D3DKMT_CLIENTHINT_DX11:11`

The client is the DirectX 11.0 runtime.

### `D3DKMT_CLIENTHINT_DX12:12`

The client is the DirectX 12.0 runtime.

### `D3DKMT_CLIENTHINT_9ON12:13`

The client is the D3D9On12 mapping layer (DirectX 9 on DirectX 12).

### `D3DKMT_CLIENTHINT_11ON12:14`

The client is the D3D11On12 mapping layer (DirectX 11 on DirectX 12).

### `D3DKMT_CLIENTHINT_MFT_ENCODE:15`

The client is a Media Foundation Transform (MFT).

### `D3DKMT_CLIENTHINT_GLON12:16`

The client is an OpenGL on DirectX 12 mapping layer.

### `D3DKMT_CLIENTHINT_CLON12:17`

The client is an OpenCL on DirectX 12 mapping layer.

### `D3DKMT_CLIENTHINT_DML_TENSORFLOW:18`

The client is TensorFlow.

### `D3DKMT_CLIENTHINT_ONEAPI_LEVEL0:19`

The client is oneAPI Level Zero.

### `D3DKMT_CLIENTHINT_DML_PYTORCH:20`

The client is PyTorch.

### `D3DKMT_CLIENTHINT_MAX`

Maximum enumeration value.

## See also

[**D3DKMT_CREATECONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createcontext)