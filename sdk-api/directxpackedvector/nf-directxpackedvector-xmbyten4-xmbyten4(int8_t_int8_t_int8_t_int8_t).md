# XMBYTEN4::XMBYTEN4(int8_t,int8_t,int8_t,int8_t)

## Description

Initializes a new instance of `XMBYTEN4` from four `int8_t` arguments.

This constructor initializes a new instance of [XMBYTEN4](https://msdn.microsoft.com/62d61a35-8674-4855-b09c-f351363cd50b) from a
four `int8_t` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMBYTEN4` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMBYTEN4` instance.

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMBYTEN4` instance.

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMBYTEN4` instance.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of
this constructor:

```

	    XMBYTEN4 instance;

	    instance.x = _x;
	    instance.y = _y;
	    instance.z = _z;
	    instance.w = _w;

	
```

## See also

**Reference**

[XMBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten4)

[XMBYTEN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyten4-ctor)