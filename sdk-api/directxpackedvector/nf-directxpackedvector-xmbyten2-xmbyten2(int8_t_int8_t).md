# XMBYTEN2::XMBYTEN2(int8_t,int8_t)

## Description

Initializes a new instance of `XMBYTEN2` from two `int8_t` arguments.

This constructor initializes a new instance of [XMBYTEN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten2)  from two `int8_t` arguments.

**Note** This constructor is only available with C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new `XMBYTEN2` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new `XMBYTEN2` instance.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of this constructor:

```

	    XMBYTEN2 instance;

	    instance.x = _x;
	    instance.y = _y;
	
```

## See also

**Reference**

[XMBYTEN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmbyten2)

[XMBYTEN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmbyten2-ctor)