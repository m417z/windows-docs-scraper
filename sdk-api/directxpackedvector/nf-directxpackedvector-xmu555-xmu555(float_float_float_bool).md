# XMU555::XMU555(float,float,float,bool)

## Description

Initializes a new instance of `XMU555` from three `float` and one
`bool` arguments.

This constructor initializes a new instance of [XMU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu555)  from three
`float` (specifying x-, y-, and z-components) and one `bool` (specifying
the w-component) arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMU555` instance.

The magnitude of this argument will be clamped to a range of [0, 31.0].

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMU555` instance.

The magnitude of this argument will be clamped to a range of [0, 31.0].

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMU555` instance.

The magnitude of this argument will be clamped to a range of [0, 31.0].

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMU555` instance.

The magnitude of this argument will be clamped to a range of [0, 1].

## Remarks

The following pseudocode demonstrates the operation of this constructor, which takes
advantage of the `union` of the four components of the `XMU555` vector with an instance of `uint16_t` in the definition of the structure:

```

	_x1=min( max( _x, 0.0 ), 31.0 );
	_y1=min( max( _y, 0.0 ), 31.0 );
	_z1=min( max( _z, 0.0 ), 31.0 );
	_w1=min( max( _w, 0 ), 1 );

	instance.v =  (((uint16_t)_w1 ? 0x8000 : 0) |
                      (((uint16_t)_z1 & 0x1F) << 10) |
                      (((uint16_t)_y1 & 0x1F) << 5) |
		      (((uint16_t)_x1 & 0x1F)));
	
```

## See also

**Reference**

[XMU555](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmu555)

[XMU555 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmu555-ctor)