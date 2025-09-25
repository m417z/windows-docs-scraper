# XMHALF2::XMHALF2(float,float)

## Description

Initializes a new instance of `XMHALF2` from two `float` arguments.

This constructor initializes a new instance of [XMHALF2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf2) from two
`float` arguments.

**Note** This constructor is only available under C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new
`XMHALF2` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new
`XMHALF2` instance.

## Remarks

If the magnitude of one of this constructor's floating point arguments cannot be
represented by the `HALF` type, the corresponding member of the new instance of
`XMHALF2` will be infinity for a 16-bit integer (+0x7FFF).

The following pseudocode demonstrates the operation of this constructor using the XNA
Math [XMConvertFloatToHalf](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmconvertfloattohalf) function:

```

	XMHALF2 instance;

	instance.x = XMConvertFloatToHalf(_x);
	instance.y = XMConvertFloatToHalf(_y);

```

## See also

**Reference**

[XMHALF2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf2)

[XMHALF2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmhalf2-ctor)