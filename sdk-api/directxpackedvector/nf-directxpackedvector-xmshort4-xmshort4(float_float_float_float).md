# XMSHORT4::XMSHORT4(float,float,float,float)

## Description

Initializes a new instance of `XMSHORT4` from four `float` arguments.

This constructor initializes a new instance of [XMSHORT4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort4) from four
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMSHORT4` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMSHORT4` instance.

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMSHORT4` instance.

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMSHORT4` instance.

## Remarks

The magnitude of each argument to the constructor will be clamped to the range supported
by a 16-bit signed integer [-32767.0, 32767.0].

The following pseudocode demonstrates the operation of this constructor:

```

	XMSHORT4 instance;

	instance.x = (int16_t)min( max( _x, -32767.0 ), 32767.0 );
	instance.y = (int16_t)min( max( _y, -32767.0 ), 32767.0 );
	instance.z = (int16_t)min( max( _z, -32767.0 ), 32767.0 );
	instance.w = (int16_t)min( max( _w, -32767.0 ), 32767.0 );

```

## See also

**Reference**

[XMSHORT4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort4)

[XMSHORT4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshort4-ctor)