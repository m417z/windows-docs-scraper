# operator -(XMVECTOR)

## Description

Computes the negation of an **XMVECTOR** instance.

The `operator -` takes an instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) and returns a new instance of **XMVECTOR**, with each component negated.

**Note** This operator is only available under C++.

## Parameters

### `V`

Vector whose components are to have their signs changed.

## Return value

Vector whose components are the negation of *V*.

## Remarks

The following pseudocode demonstrates the operation of this operator:

```cpp
   XMVECTOR V;
   XMVECTOR Vout;
   Vout.x = - V.x;
   Vout.y = - V.y;
   Vout.z = - V.z;
   Vout.w = - V.w;
```

## See also

[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type)