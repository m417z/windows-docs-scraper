# XMXDEC4::XMXDEC4(float,float,float,float)

## Description

Initializes a new instance of `XMXDEC4` from four `float` arguments.

This constructor initializes a new instance of [XMXDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdec4)  from four
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMXDEC4` instance.

The magnitude of this argument will be clamped to a range of [-511.0,
511.0].

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMXDEC4` instance.

The magnitude of this argument will be clamped to a range of [-511.0,
511.0].

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMXDEC4` instance.

The magnitude of this argument will be clamped to a range of [-511.0,
511.0].

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMXDEC4` instance.

The magnitude of this argument will be clamped to a range of [0.0, 3.0].

## Remarks

The following pseudocode demonstrates the operation of this constructor, which takes
advantage of the `union` of the four components of the `XMXDEC4` vector with an instance of `uint32_t` in the definition of the structure:

```

	XMXDEC4 instance;
	_x1=min( max( _x, -511.0 ), 511.0 );
	_y1=min( max( _y, -511.0 ), 511.0 );
	_z1=min( max( _z, -511.0 ), 511.0 );
	_w1=min( max( _w, 0.0 ), 3.0 );

	instance.v =  ( (int32_t)_w1 << 30) |
                      (((int32_t)_z1 & 0x3FF) << 20) |
                      (((int32_t)_y1 & 0x3FF) << 10) |
                      (((uint32_t)_x1 & 0x3FF));;

```

## See also

**Reference**

[XMXDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdec4)

[XMXDEC4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmxdec4-ctor)