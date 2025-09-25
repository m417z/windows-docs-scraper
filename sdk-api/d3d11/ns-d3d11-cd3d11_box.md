# CD3D11_BOX structure

## Description

Represents a box and provides convenience methods for creating boxes.

## Members

## Remarks

Here is how D3D11.h defines **CD3D11_BOX**:

|  |
| --- |
| ``` struct CD3D11_BOX : public D3D11_BOX {     CD3D11_BOX()     {}     explicit CD3D11_BOX( const D3D11_BOX& o ) :         D3D11_BOX( o )     {}     explicit CD3D11_BOX(         LONG Left,         LONG Top,         LONG Front,         LONG Right,         LONG Bottom,         LONG Back )     {         left = Left;         top = Top;         front = Front;         right = Right;         bottom = Bottom;         back = Back;     }     ~CD3D11_BOX() {}     operator const D3D11_BOX&() const { return *this; } }; ``` |

## See also

[CD3D11 Helper Structures](https://learn.microsoft.com/windows/desktop/direct3d11/cd3d11-helper-classes)