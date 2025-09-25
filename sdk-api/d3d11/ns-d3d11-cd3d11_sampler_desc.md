# CD3D11_SAMPLER_DESC structure

## Description

Represents a sampler state and provides convenience methods for creating sampler states.

## Members

## Remarks

Here is how D3D11.h defines **CD3D11_SAMPLER_DESC**:

|  |
| --- |
| ``` struct CD3D11_SAMPLER_DESC : public D3D11_SAMPLER_DESC {     CD3D11_SAMPLER_DESC()     {}     explicit CD3D11_SAMPLER_DESC( const D3D11_SAMPLER_DESC& o ) :         D3D11_SAMPLER_DESC( o )     {}     explicit CD3D11_SAMPLER_DESC( CD3D11_DEFAULT )     {         Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;         AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;         AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;         AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;         MipLODBias = 0;         MaxAnisotropy = 1;         ComparisonFunc = D3D11_COMPARISON_NEVER;         BorderColor[ 0 ] = 1.0f;         BorderColor[ 1 ] = 1.0f;         BorderColor[ 2 ] = 1.0f;         BorderColor[ 3 ] = 1.0f;         MinLOD = -3.402823466e+38F; // -FLT_MAX         MaxLOD = 3.402823466e+38F; // FLT_MAX     }     explicit CD3D11_SAMPLER_DESC(         D3D11_FILTER filter,         D3D11_TEXTURE_ADDRESS_MODE addressU,         D3D11_TEXTURE_ADDRESS_MODE addressV,         D3D11_TEXTURE_ADDRESS_MODE addressW,         FLOAT mipLODBias,         UINT maxAnisotropy,         D3D11_COMPARISON_FUNC comparisonFunc,         _In_reads_opt_( 4 ) const FLOAT* borderColor, // RGBA         FLOAT minLOD,         FLOAT maxLOD )     {         Filter = filter;         AddressU = addressU;         AddressV = addressV;         AddressW = addressW;         MipLODBias = mipLODBias;         MaxAnisotropy = maxAnisotropy;         ComparisonFunc = comparisonFunc;         const float defaultColor[ 4 ] = { 1.0f, 1.0f, 1.0f, 1.0f };         if (!borderColor) borderColor = defaultColor;         BorderColor[ 0 ] = borderColor[ 0 ];         BorderColor[ 1 ] = borderColor[ 1 ];         BorderColor[ 2 ] = borderColor[ 2 ];         BorderColor[ 3 ] = borderColor[ 3 ];         MinLOD = minLOD;         MaxLOD = maxLOD;     }     ~CD3D11_SAMPLER_DESC() {}     operator const D3D11_SAMPLER_DESC&() const { return *this; } }; ``` |

## See also

[CD3D11 Helper Structures](https://learn.microsoft.com/windows/desktop/direct3d11/cd3d11-helper-classes)