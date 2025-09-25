# operator -(XMVECTOR, XMVECTOR)

## Description

Subtracts one instance of **XMVECTOR** from a second instance, returning the result in a new instance of **XMVECTOR**.

The `operator -` subtracts each component of an instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) from each component of another instance of **XMVECTOR**, returning a new **XMVECTOR** instance containing the result.

**Note** This operator is only available under C++.

## Parameters

### `V1`

**XMVECTOR** instance whose components are the minuends of the subtraction operation.

### `V2`

**XMVECTOR** instance whose components are the subtrahends of the subtraction operation.

## Return value

**XMVECTOR** instance whose components are the result of subtracting of each component of *V2* from each corresponding component of *V1*.

## Remarks

The following pseudocode demonstrates the operation of this operator:

```cpp
   XMVECTOR V1;
   XMVECTOR V2;
   XMVECTOR Vout;
   Vout.x = V1.x - V2.x;
   Vout.y = V1.y - V2.y;
   Vout.z = V1.z - V2.z;
   Vout.w = V1.w - V2.w;
```

## See also

[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type)