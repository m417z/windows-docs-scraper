# XMBYTE4::XMBYTE4(float,float,float,float)

## Description

Initializes a new instance of `XMBYTE4` from four `float` arguments.

This constructor initializes a new instance of [XMBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyte4) from four
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMBYTE4` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMBYTE4` instance.

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMBYTE4` instance.

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMBYTE4` instance.

## Remarks

The magnitude of each argument to the constructor will be clamped to the range supported by an
8-bit signed integer [-127.0, 127.0].

The following pseudocode demonstrates the operation of this constructor:

```

	XMBYTE4 instance;

	instance.x = (int8_t)min( max( _x, -127.0 ), 127.0 );
	instance.y = (int8_t)min( max( _y, -127.0 ), 127.0 );
	instance.z = (int8_t)min( max( _z, -127.0 ), 127.0 );
	instance.w = (int8_t)min( max( _w, -127.0 ), 127.0 );

```

## See also

**Reference**

[XMBYTE4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyte4)

[XMBYTE4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyte4-ctor)