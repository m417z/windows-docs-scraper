# CD3D11_COUNTER_DESC structure

## Description

Represents a counter and provides convenience methods for creating counters.

## Members

## Remarks

Here is how D3D11.h defines **CD3D11_COUNTER_DESC**:

|  |
| --- |
| ``` struct CD3D11_COUNTER_DESC : public D3D11_COUNTER_DESC {     CD3D11_COUNTER_DESC()     {}     explicit CD3D11_COUNTER_DESC( const D3D11_COUNTER_DESC& o ) :         D3D11_COUNTER_DESC( o )     {}     explicit CD3D11_COUNTER_DESC(         D3D11_COUNTER counter,         UINT miscFlags = 0 )     {         Counter = counter;         MiscFlags = miscFlags;     }     ~CD3D11_COUNTER_DESC() {}     operator const D3D11_COUNTER_DESC&() const { return *this; } }; ``` |

## See also

[CD3D11 Helper Structures](https://learn.microsoft.com/windows/desktop/direct3d11/cd3d11-helper-classes)