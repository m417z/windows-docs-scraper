# operator *(XMVECTOR, float)

## Description

Multiply an instance of **XMVECTOR** by a floating point value, returning the result a new instance of **XMVECTOR**.

The `operator *` multiplies each component of an instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by a floating point value, returning a new **XMVECTOR** instance whose components contain the result.

**Note** This operator is only available under C++.

## Parameters

### `V`

**XMVECTOR** instance whose components are multiplicands of this multiplication operation.

### `S`

Floating point value used as a multiplicand for each component of *V*.

## Return value

**XMVECTOR** instance whose components are the product of the multiplication of the corresponding components of *V* by *S*.

## Remarks

The following pseudocode demonstrates the operation of this operator:

```cpp
   XMVECTOR V;
   Float S;
   XMVECTOR Vout;
   Vout.x = V1.x * S;
   Vout.y = V1.y * S;
   Vout.z = V1.z * S;
   Vout.w = V1.w * S;
```

## See also

[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type)