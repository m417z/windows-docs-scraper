# CD3D11_RECT structure

## Description

Represents a rectangle and provides convenience methods for creating rectangles.

## Members

## Remarks

Here is how D3D11.h defines **CD3D11_RECT**:

|  |
| --- |
| ``` struct CD3D11_RECT : public D3D11_RECT {     CD3D11_RECT()     {}     explicit CD3D11_RECT( const D3D11_RECT& o ) :         D3D11_RECT( o )     {}     explicit CD3D11_RECT(         LONG Left,         LONG Top,         LONG Right,         LONG Bottom )     {         left = Left;         top = Top;         right = Right;         bottom = Bottom;     }     ~CD3D11_RECT() {}     operator const D3D11_RECT&() const { return *this; } }; ``` |

## See also

[CD3D11 Helper Structures](https://learn.microsoft.com/windows/desktop/direct3d11/cd3d11-helper-classes)