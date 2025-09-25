# XMUSHORT2::XMUSHORT2(float,float)

## Description

Initializes a new instance of `XMUSHORT2` from two `float` arguments.

This constructor initializes a new instance of [XMUSHORT2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushort2) from two
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMUSHORT2` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMUSHORT2` instance.

## Remarks

The magnitude of each argument to the constructor will be clamped to the range supported
by a 16-bit unsigned integer [0.0, 65535.0].

The following pseudocode demonstrates the operation of this constructor:

```

	XMUSHORT2 instance;

	instance.x = (uint16_t)min( max( _x, 0.0 ), 65535.0 );
	instance.y = (uint16_t)min( max( _y, 0.0 ), 65535.0 );

```

## See also

**Reference**

[XMUSHORT2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushort2)

[XMUSHORT2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmushort2-ctor)