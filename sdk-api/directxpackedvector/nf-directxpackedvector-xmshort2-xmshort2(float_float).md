# XMSHORT2::XMSHORT2(float,float)

## Description

Initializes a new instance of `XMSHORT2` from two `float` arguments.

This constructor initializes a new instance of [XMSHORT2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort2) from two
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMSHORT2` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMSHORT2` instance.

## Remarks

The magnitude of each argument to the constructor will be clamped to the range supported
by a 16-bit signed integer [-32767.0, 32767.0].

The following pseudocode demonstrates the operation of this constructor:

```

	XMSHORT2 instance;

	instance.x = (int16_t)min( max( _x, -32767.0 ), 32767.0 );
	instance.y = (int16_t)min( max( _y, -32767.0 ), 32767.0 );

```

## See also

**Reference**

[XMSHORT2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshort2)

[XMSHORT2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshort2-ctor)