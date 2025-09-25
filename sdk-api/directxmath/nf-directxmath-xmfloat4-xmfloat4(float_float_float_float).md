# XMFLOAT4::XMFLOAT4(float,float,float,float)

## Description

Initializes a new instance of `XMFLOAT4` from four `float` arguments.

This constructor initializes a new instance of [XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4) from four
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMFLOAT4` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMFLOAT4` instance.

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMFLOAT4` instance.

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMFLOAT4` instance.

## Remarks

The following pseudocode demonstrates the operation of this constructor:

```

	XMFLOAT4 instance;

	instance.x = _x;
	instance.y = _y;
	instance.z = _z;
	instance.w = _w;

```

## See also

**Reference**

[XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4)

[XMFLOAT4 Constructors](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmfloat4-xmfloat4(constfloat))