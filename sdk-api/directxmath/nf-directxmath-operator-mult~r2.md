# operator *(float, XMVECTOR)

## Description

Multiply a floating point value by an instance of **XMVECTOR**, returning the result a new instance of **XMVECTOR**.

The `operator *` multiplies a floating point value against each component of an instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type), returning a new **XMVECTOR** instance whose components contain the result.

**Note** This operator is only available under C++.

## Parameters

### `S`

Floating point value used as a multiplicand for each component of *V*.

### `V`

**XMVECTOR** instance whose components are multiplicands of this multiplication operation.

## Return value

**XMVECTOR** instance whose components are the product of the multiplication of the corresponding components of *V* by *S*.

## Remarks

The following pseudocode demonstrates the operation of this operator:

```cpp
   XMVECTOR V;
   Float S;
   XMVECTOR Vout;
   Vout.x = S * V1.x;
   Vout.y = S * V1.y;
   Vout.z = S * V1.z;
   Vout.w = S * V1.w;
```

## See also

[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type)