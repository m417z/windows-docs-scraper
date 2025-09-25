# CD3D11_QUERY_DESC structure

## Description

Represents a query and provides convenience methods for creating queries.

## Members

## Remarks

Here is how D3D11.h defines **CD3D11_QUERY_DESC**:

|  |
| --- |
| ``` struct CD3D11_QUERY_DESC : public D3D11_QUERY_DESC {     CD3D11_QUERY_DESC()     {}     explicit CD3D11_QUERY_DESC( const D3D11_QUERY_DESC& o ) :         D3D11_QUERY_DESC( o )     {}     explicit CD3D11_QUERY_DESC(         D3D11_QUERY query,         UINT miscFlags = 0 )     {         Query = query;         MiscFlags = miscFlags;     }     ~CD3D11_QUERY_DESC() {}     operator const D3D11_QUERY_DESC&() const { return *this; } }; ``` |

## See also

[CD3D11 Helper Structures](https://learn.microsoft.com/windows/desktop/direct3d11/cd3d11-helper-classes)