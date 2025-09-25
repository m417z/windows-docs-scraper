# CD3D11_TEXTURE2D_DESC structure

## Description

Represents a 2D texture and provides convenience methods for creating 2D textures.

## Members

## Remarks

Here is how D3D11.h defines **CD3D11_TEXTURE2D_DESC**:

|  |
| --- |
| ``` struct CD3D11_TEXTURE2D_DESC : public D3D11_TEXTURE2D_DESC {     CD3D11_TEXTURE2D_DESC()     {}     explicit CD3D11_TEXTURE2D_DESC( const D3D11_TEXTURE2D_DESC& o ) :         D3D11_TEXTURE2D_DESC( o )     {}     explicit CD3D11_TEXTURE2D_DESC(         DXGI_FORMAT format,         UINT width,         UINT height,         UINT arraySize = 1,         UINT mipLevels = 0,         UINT bindFlags = D3D11_BIND_SHADER_RESOURCE,         D3D11_USAGE usage = D3D11_USAGE_DEFAULT,         UINT cpuaccessFlags = 0,         UINT sampleCount = 1,         UINT sampleQuality = 0,         UINT miscFlags = 0 )     {         Width = width;         Height = height;         MipLevels = mipLevels;         ArraySize = arraySize;         Format = format;         SampleDesc.Count = sampleCount;         SampleDesc.Quality = sampleQuality;         Usage = usage;         BindFlags = bindFlags;         CPUAccessFlags = cpuaccessFlags;         MiscFlags = miscFlags;     }     ~CD3D11_TEXTURE2D_DESC() {}     operator const D3D11_TEXTURE2D_DESC&() const { return *this; } }; ``` |

## See also

[CD3D11 Helper Structures](https://learn.microsoft.com/windows/desktop/direct3d11/cd3d11-helper-classes)