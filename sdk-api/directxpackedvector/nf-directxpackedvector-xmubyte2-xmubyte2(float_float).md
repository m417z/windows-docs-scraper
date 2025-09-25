# XMUBYTE2::XMUBYTE2(float,float)

## Description

Initializes a new instance of `XMUBYTE2` from two `float` arguments.

This constructor initializes a new instance of [XMUBYTE2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte2) from two `float` arguments.

**Note** This constructor is only available with C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new `XMUBYTE2` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new `XMUBYTE2` instance.

## Remarks

The magnitude of each argument to the constructor will be clamped to the range supported by an 8-bit signed integer [0,
255.0].

The following pseudocode demonstrates the operation of this constructor:

```

	XMUBYTE2 instance;

	instance.x = (uint8_t)min( max( _x, 0.0 ), 255.0 );
	instance.y = (uint8_t)min( max( _y, 0.0 ), 255.0 );

```

## See also

**Reference**

[XMUBYTE2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyte2)

[XMUBYTE2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyte2-ctor)