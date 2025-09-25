# XMFLOAT4A::XMFLOAT4A(const float)

## Description

Initializes a new instance of `XMFLOAT4` from a four element `float` array
argument.

This constructor initializes a new instance of [XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4) from a from
a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element `float` array containing the values used to initialize the
four components of a new instance of `XMFLOAT4`.

## Remarks

The following pseudocode demonstrates the operation of this constructor:

```

	XMFLOAT4 instance;
	instance.x = pArray[0];
	instance.y = pArray[1];
	instance.z = pArray[2];
	instance.w = pArray[3];

```

## See also

**Reference**

[XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4)

[XMFLOAT4 Constructors](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmfloat4-xmfloat4(constfloat))