# XMBYTE2::XMBYTE2(float,float)

## Description

Initializes a new instance of `XMBYTE2` from two `float` arguments.

This constructor initializes a new instance of [XMBYTE2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyte2) from two `float` arguments.

**Note** This constructor is only available with C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new `XMBYTE2` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new `XMBYTE2` instance.

## Remarks

The magnitude of each argument to the constructor will be clamped to the range supported by an 8-bit signed integer
[-127.0, 127.0].

The following pseudocode demonstrates the operation of this constructor:

```

	XMBYTE2 instance;

	instance.x = (int8_t)min( max( _x, -127.0 ), 127.0 );
	instance.y = (int8_t)min( max( _y, -127.0 ), 127.0 );

```

## See also

**Reference**

[XMBYTE2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyte2)

[XMBYTE2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyte2-ctor)