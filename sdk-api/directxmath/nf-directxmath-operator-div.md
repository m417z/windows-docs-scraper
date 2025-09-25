# XMVECTOR::operator / (XMVECTOR,XMVECTOR)

## Description

Divides one instance of **XMVECTOR** by a second instance, returning the result in a third instance.

The `operator /` divides each component of an instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by the corresponding component in a second instance of **XMVECTOR**, returning a new **XMVECTOR** instance containing the result.

**Note** This operator is only available under C++.

## Parameters

### `V1`

**XMVECTOR** instance whose components are the dividends of the division operation.

### `V2`

**XMVECTOR** instance whose components are the divisors of the division operation.

## Return value

**XMVECTOR** instance whose components are the quotient of the division of each component of V1 by each corresponding component of *V2*.

## Remarks

The following pseudocode demonstrates the operation of this operator:

```cpp
   XMVECTOR V1;
   XMVECTOR V2;
   XMVECTOR Vout;
   Vout.x = V1.x / V2.x;
   Vout.y = V1.y / V2.y;
   Vout.z = V1.z / V2.z;
   Vout.w = V1.w / V2.w;
```

## See also

[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type)