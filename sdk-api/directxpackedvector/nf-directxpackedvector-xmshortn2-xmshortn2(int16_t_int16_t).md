# XMSHORTN2::XMSHORTN2(int16_t,int16_t)

## Description

Initializes a new instance of `XMSHORTN2` from two `int16_t` arguments.

This constructor initializes a new instance of [XMSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn2) from two
`int16_t` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMSHORTN2` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMSHORTN2` instance.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of
this constructor:

```

	XMSHORTN2 instance;

	instance.x = _x;
	instance.y = _y;

```

## See also

**Reference**

[XMSHORTN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmshortn2)

[XMSHORTN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmshortn2-ctor)