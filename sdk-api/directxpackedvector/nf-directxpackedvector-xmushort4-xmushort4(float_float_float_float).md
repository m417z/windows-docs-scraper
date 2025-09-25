# XMUSHORT4::XMUSHORT4(float,float,float,float)

## Description

Initializes a new instance of `XMUSHORT4` from four `float` arguments.

This constructor initializes a new instance of [XMUSHORT4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushort4) from four
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMUSHORT4` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMUSHORT4` instance.

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMUSHORT4` instance.

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMUSHORT4` instance.

## Remarks

The magnitude of each argument to the constructor will be clamped to the range supported
by a 16-bit unsigned integer [0.0, 65535.0].

The following pseudocode demonstrates the operation of this constructor:

```

	XMUSHORT4 instance;

	instance.x = (uint16_t)min( max( _x, 0.0 ), 65535.0 );
	instance.y = (uint16_t)min( max( _y, 0.0 ), 65535.0 );
	instance.z = (uint16_t)min( max( _z, 0.0 ), 65535.0 );
	instance.w = (uint16_t)min( max( _w, 0.0 ), 65535.0 );

```

## See also

**Reference**

[XMUSHORT4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushort4)

[XMUSHORT4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmushort4-ctor)