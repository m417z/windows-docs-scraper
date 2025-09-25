# XMVECTOR::operator + (XMVECTOR,XMVECTOR)

## Description

Adds two instances of **XMVECTOR**, returning the result in a new instance.

The `operator +` adds each component of two instances of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type), and then returns the result in a new **XMVECTOR** instance.

**Note** This operator is only available under C++.

## Parameters

### `V1`

Instance of **XMVECTOR** whose components added to those of *V2*.

### `V2`

Instance of **XMVECTOR** whose components added to those of *V1*.

## Return value

**XMVECTOR** instance whose components are the sum of the corresponding components of *V1* and *V2*.

## Remarks

The following pseudocode demonstrates the operation of this operator:

```cpp
   XMVECTOR V1;
   XMVECTOR V2;
   XMVECTOR Vout;
   Vout.x = V1.x + V2.x;
   Vout.y = V1.y + V2.y;
   Vout.z = V1.z + V2.z;
   Vout.w = V1.w + V2.w;
```

## See also

[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type)