# XMU565::XMU565(float,float,float)

## Description

Initializes a new instance of `XMU565` from three `float` arguments.

This constructor initializes a new instance of [XMU565](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu565)  from three
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMU565` instance.

The magnitude of this argument will be clamped to a range of [0.0, 31.0].

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMU565` instance.

The magnitude of this argument will be clamped to a range of [0.0, 63.0].

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMU565` instance.

The magnitude of this argument will be clamped to a range of [0.0, 31.0].

## Remarks

The following pseudocode demonstrates the operation of this constructor, which takes
advantage of the `union` of the three components of the `XMU565` vector
with an instance of `uint16_t` in the definition of the structure:

```

	XMU565 instance;
	_x1=min( max( _x, 0.0 ), 31.0 );
	_y1=min( max( _y, 0.0 ), 63.0 );
	_z1=min( max( _z, 0.0 ), 31.0 );

	instance.v= ((z & 0x1F) << 11) |
                    ((y & 0x3F) << 5) |
                    ((x & 0x1F));

```

## See also

**Reference**

[XMU565](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu565)

[XMU565 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmu565-ctor)