# XMDEC4::XMDEC4(float,float,float,float)

## Description

Initializes a new instance of `XMDEC4` from four `float` arguments.

This constructor initializes a new instance of [XMDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmdec4)  from four
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMDEC4` instance.

The magnitude of this argument will be clamped to a range of [-511.0,
511.0].

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMDEC4` instance.

The magnitude of this argument will be clamped to a range of [-511.0,
511.0].

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMDEC4` instance.

The magnitude of this argument will be clamped to a range of [-511.0,
511.0].

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMDEC4` instance.

The magnitude of this argument will be clamped to a range of [-1.0,
1.0].

## Remarks

The following pseudocode demonstrates the operation of this constructor, which takes
advantage of the `union` of the four components of the `XMDEC4` vector
with an instance of `uint32_t` in the definition of the structure:

```

	XMDEC4 instance;
	_x1=min( max( _x, -511.0 ), 511.0 );
	_y1=min( max( _y, -511.0 ), 511.0 );
	_z1=min( max( _z, -511.0 ), 511.0 );
	_w1=min( max( _w, -1.0 ), 1.0 );

	instance.v =  ( (int32_t)_w1 << 30) |
                      (((int32_t)_z1 & 0x3FF) << 20) |
                      (((int32_t)_y1 & 0x3FF) << 10) |
                      (((int32_t)_x1 & 0x3FF));

```

## See also

**Reference**

[XMDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmdec4)

[XMDEC4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmdec4-ctor)