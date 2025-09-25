# XMUBYTE4::XMUBYTE4(float,float,float,float)

## Description

Initializes a new instance of `XMUBYTE4` from four `float` arguments.

This constructor initializes a new instance of [XMUBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte4) from four
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMUBYTE4` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMUBYTE4` instance.

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMUBYTE4` instance.

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMUBYTE4` instance.

## Remarks

The magnitude of each argument to the constructor will be clamped to the range supported by an
8-bit signed integer [0, 255.0].

The following pseudocode demonstrates the operation of this constructor:

```

	XMUBYTE4 instance;

	instance.x = (uint8_t)min( max( _x, 0.0 ), 255.0 );
	instance.y = (uint8_t)min( max( _y, 0.0 ), 255.0 );
	instance.z = (uint8_t)min( max( _z, 0.0 ), 255.0 );
	instance.w = (uint8_t)min( max( _w, 0.0 ), 255.0 );

```

## See also

**Reference**

[XMUBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte4)

[XMUBYTE4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyte4-ctor)