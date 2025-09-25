# XMUBYTEN4::XMUBYTEN4(uint8_t,uint8_t,uint8_t,uint8_t)

## Description

Initializes a new instance of `XMUBYTEN4` from four `uint8_t` arguments.

This constructor initializes a new instance of [XMUBYTEN4](https://msdn.microsoft.com/552002c1-0000-44a6-9f43-9c958a8d1aa3) from a
four `uint8_t` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMUBYTEN4` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMUBYTEN4` instance.

### `_z`

Value of the z-coordinate of the vector, the **z** member of the new
`XMUBYTEN4` instance.

### `_w`

Value of the w-coordinate of the vector, the **w** member of the new
`XMUBYTEN4` instance.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of
this constructor:

```

	    XMUBYTEN4 instance;

	    instance.x = _x;
	    instance.y = _y;
	    instance.z = _z;
	    instance.w = _w;

	
```

## See also

**Reference**

[XMUBYTEN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten4)

[XMUBYTEN4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyten4-ctor)