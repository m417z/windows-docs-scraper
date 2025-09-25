# ID3D12ShaderReflection::GetThreadGroupSize

## Description

Retrieves the sizes, in units of threads, of the X, Y, and Z dimensions of the shader's thread-group grid.

## Parameters

### `pSizeX` [out, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to the size, in threads, of the x-dimension of the thread-group grid. The maximum size is 1024.

### `pSizeY` [out, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to the size, in threads, of the y-dimension of the thread-group grid. The maximum size is 1024.

### `pSizeZ` [out, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to the size, in threads, of the z-dimension of the thread-group grid. The maximum size is 64.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the total size, in threads, of the thread-group grid by calculating the product of the size of each dimension.

``` syntax
*pSizeX * *pSizeY * *pSizeZ;
```

## Remarks

This method's interface is hosted in the out-of-box DLL D3DCompiler_xx.dll.

When a compute shader is written it defines the actions of a single thread group only. If multiple thread groups are required, it is the role of the [ID3D12GraphicsCommandList::Dispatch](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-dispatch) call to issue multiple thread groups.

## See also

[ID3D12ShaderReflection](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nn-d3d12shader-id3d12shaderreflection)