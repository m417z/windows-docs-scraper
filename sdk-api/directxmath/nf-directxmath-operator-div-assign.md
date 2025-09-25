# XMVECTOR::operator /= (XMVECTOR&,XMVECTOR)

## Description

Divides one **XMVECTOR** instance by a second instance, returning a reference to the updated initial instance.

The `operator /=` divides each component of the current instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by the corresponding component in a second specified instance of **XMVECTOR**, returning a reference to the updated initial instance.

**Note** This operator is only available under C++.

## Parameters

### `V1`

Reference to current instance of **XMVECTOR**.

### `V2`

**XMVECTOR** instance whose components are to be divisors.

## Return value

Reference to the updated current instance of **XMVECTOR** containing the result of the division operation.

## Remarks

The following pseudocode demonstrates the operation of this operator:

```cpp
   XMVECTOR V1;
   XMVECTOR V2;
   V1.x = V1.x / V2.x;
   V1.y = V1.y / V2.y;
   V1.z = V1.z / V2.z;
   V1.w = V1.w / V2.w;
```

## See also

[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type)