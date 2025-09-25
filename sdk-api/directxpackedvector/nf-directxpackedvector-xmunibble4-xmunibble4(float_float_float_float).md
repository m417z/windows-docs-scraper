# XMUNIBBLE4::XMUNIBBLE4(float,float,float,float)

## Description

Initializes a new instance of `XMUNIBBLE4` from four `float` arguments.

This constructor initializes a new instance of [XMUNIBBLE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmunibble4)  from four
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMUNIBBLE4` instance.

The magnitude of this argument will be clamped to a range of [0, 15.0].

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMUNIBBLE4` instance.

The magnitude of this argument will be clamped to a range of [0, 15.0].

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMUNIBBLE4` instance.

The magnitude of this argument will be clamped to a range of [0, 15.0].

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMUNIBBLE4` instance.

The magnitude of this argument will be clamped to a range of [0, 15.0].

## Remarks

The following pseudocode demonstrates the operation of this constructor, which takes
advantage of the `union` of the four components of the `XMUNIBBLE4` vector with an instance of `uint16_t` in the definition of the structure:

```

	XMUNIBBLE4 instance;
	_x1=min( max( _x, 0.0 ), 15.0f );
	_y1=min( max( _y, 0.0 ), 15.0f );
	_z1=min( max( _z, 0.0 ), 15.0f );
	_w1=min( max( _w, 0.0 ), 15.0f );

	instance.v =  ( (uint16_t)_w1 << 12) |
                      (((uint16_t)_z1 & 0xF) << 8) |
                      (((uint16_t)_y1 & 0xF) << 4) |
                      (((uint16_t)_x1 & 0xF));

```

## See also

**Reference**

[XMUNIBBLE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmunibble4)

[XMUNIBBLE4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmunibble4-ctor)