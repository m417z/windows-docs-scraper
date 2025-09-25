# XMUBYTEN2::XMUBYTEN2(uint8_t,uint8_t)

## Description

Initializes a new instance of `XMUBYTEN2` from two `uint8_t` arguments.

This constructor initializes a new instance of [XMUBYTEN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten2)  from two `uint8_t` arguments.

**Note** This constructor is only available with C++.

## Parameters

### `_x`

Value of the x-coordinate of the vector, the **x** member of the new `XMUBYTEN2` instance.

### `_y`

Value of the y-coordinate of the vector, the **y** member of the new `XMUBYTEN2` instance.

## Remarks

Input values are not normalized. The following pseudocode demonstrates the operation of this constructor:

```

	    XMUBYTEN2 instance;

	    instance.x = _x;
	    instance.y = _y;
	
```

## See also

**Reference**

[XMUBYTEN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmubyten2)

[XMUBYTEN2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmubyten2-ctor)