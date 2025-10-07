# XMU565::XMU565(uint8_t,uint8_t,uint8_t)

## Description

Initializes a new instance of [XMU565](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu565) from three `int8_t` arguments.

This constructor initializes a new instance of \<wdcml:xref rid="dxmath.xmu565" targtype="struct">XMU565 \</wdcml:xref> from three `int8_t` arguments.

**Note** This is only available for C++ based development.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new **XMU565** instance.

The magnitude of this argument will be clamped to a range of [0, 31].

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new **XMU565** instance.

The magnitude of this argument will be clamped to a range of [0, 63].

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new **XMU565** instance.

The magnitude of this argument will be clamped to a range of [0, 31].

## Remarks

The following pseudocode demonstrates the operation of this constructor, which takes advantage of the union of the three components of the **XMU565** vector with an instance of **uint16_t** in the definition of the structure:

```cpp
XMU565 instance;
_x1=min( max( _x, 0 ), 31 );
_y1=min( max( _y, 0 ), 63 );
_z1=min( max( _z, 0 ), 31 );

instance.v= ((z & 0x1F) << 11) |
            ((y & 0x3F) << 5) |
            ((x & 0x1F));
```

## See also

[XMU565](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu565)

[XMU565 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmu565-ctor)