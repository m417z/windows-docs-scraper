# XMUSHORTN2::XMUSHORTN2(uint16_t,uint16_t)

## Description

Initializes a new instance of `XMUSHORTN2` from two `uint16_t` arguments.

This constructor initializes a new instance of [XMUSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushortn2) from two
`uint16_t` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMUSHORTN2` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMUSHORTN2` instance.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of
this constructor:

```

	XMUSHORTN2 instance;

	instance.x = _x;
	instance.y = _y;

```

## See also

**Reference**

[XMUSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmushortn2)

[XMUSHORTN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmushortn2-ctor)