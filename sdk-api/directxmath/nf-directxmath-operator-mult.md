# XMVECTOR::operator * (XMVECTOR,XMVECTOR)

## Description

Multiplies one instance of **XMVECTOR** by a second instance, returning the result in a third instance.

The `operator *` multiplies each component of an instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by the corresponding component in a second instance of **XMVECTOR**, returning a new **XMVECTOR** instance containing the result.

**Note** This operator is only available under C++.

## Parameters

### `V1`

**XMVECTOR** instance whose components provide one set of multiplicands for this multiplication operation.

### `V2`

**XMVECTOR** instance whose components provide one set of multiplicands for this multiplication operation.

## Return value

**XMVECTOR** instance whose components are the product of the multiplication of the corresponding components of *V1* by *V2*.

## Remarks

The following pseudocode demonstrates the operation of this operator:

```cpp
   XMVECTOR V;
   Float S;
   XMVECTOR Vout;
   Vout.x = V1.x * V2.x;
   Vout.y = V1.y * V2.y;
   Vout.z = V1.z * V2.z;
   Vout.w = V1.w * V2.w;
```

## See also

[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type)