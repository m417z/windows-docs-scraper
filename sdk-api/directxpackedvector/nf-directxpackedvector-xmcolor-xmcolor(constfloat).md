# XMCOLOR::XMCOLOR(const float)

## Description

Initializes a new instance of [XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor) from a four element `float` array argument.

This constructor initializes a new instance of **XMCOLOR** from a from a four element `float` array argument.

**Note** This is only available for C++ based development.

## Parameters

### `pArray`

Four element floating point array containing the color values used to initialize the four components of a new instance of **XMCOLOR**.

## Remarks

Array elements are mapped to the vector components of a new instance of **XMCOLOR** as follows:

| Vector Component | Array Element | Range | Description |
|------------------|---------------|-------|--|
| a | pArray[0] | 0.0, 1.0 | During instantiation, pArray[0] is clamped between 0 and 1, multiplied by 255.0f and assigned to a (alpha channel). |
| r | pArray[1] | 0.0, 1.0 | During instantiation, pArray[1] is clamped between 0 and 1, multiplied by 255.0f, and then assigned to r (red channel). |
| z | pArray[2] | 0.0, 1.0 | During instantiation, pArray[2] is clamped between 0 and 1, multiplied by 255.0f, and then assigned to g (green channel). |
| w | pArray[3] | 0.0, 1.0 | During instantiation, pArray[3] is clamped between 0 and 1, multiplied by 255.0f, and then assigned to b (blue channel). |

The following pseudocode demonstrates the operation of this constructor, which takes advantage of the *union* of the four color channels of the **XMCOLOR** structure with an instance of `uint32_t` in the definition of the structure:

```cpp
XMCOLOR instance;
_a1 = min( max( pArray[0], 0.0 ), 1.0 );
_r1 = min( max( pArray[1], 0.0 ), 1.0 );
_g1 = min( max( pArray[2], 0.0 ), 1.0 );
_b1 = min( max( pArray[3], 0.0 ), 1.0 );

_a1 = round ( _a1 * 255.0f );
_r1 = round ( _r1 * 255.0f );
_g1 = round ( _g1 * 255.0f );
_b1 = round ( _b1 * 255.0f );

instance.v =  ( (uint32_t)_a1 << 24) |
              ( (uint32_t)_r1 << 16) |
              ( (uint32_t)_b1 <<  8) |
              ( (uint32_t)_b1 );
```

## See also

[XMCOLOR](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmcolor)

[XMCOLOR Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmcolor-ctor)