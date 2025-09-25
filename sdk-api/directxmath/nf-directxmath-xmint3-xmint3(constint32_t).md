# XMINT3::XMINT3(const int32_t)

## Description

Initializes a new instance of `XMINT3` from a three element `int32_t` array argument.

This constructor initializes a new instance of [XMINT3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmint3) from a from a three element
`int32_t` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Three element `int32_t` array containing the values used to initialize the three components of a new instance of
`XMINT3`.

## Remarks

The following pseudocode demonstrates the operation of this constructor:

```

	XMINT3 instance;
	instance.x =  pArray[0];
	instance.y =  pArray[1];
	instance.z =  pArray[2];

```

## See also

**Reference**

[XMINT3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmint3)

[XMINT3 Constructors](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmint3-xmint3(constint32_t))