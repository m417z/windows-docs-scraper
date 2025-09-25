# operator -=

## Description

Subtracts a floating point value from the current instance of **XMVECTOR**, returning the result in the updated current instance.

The `operator -=` subtracts a specified floating point value from each component of the current instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) and returns a reference to the updated current instance.

**Note** This operator is only available under C++.

## Parameters

### `V1`

Reference to current instance of **XMVECTOR**.

### `V2`

**XMVECTOR** instance whose components are to be subtracted from the components of *V1*.

## Return value

Reference to the updated current instance of **XMVECTOR**.

## Remarks

The following pseudocode demonstrates the operation of this operator:

```cpp
   XMVECTOR V1;
   XMVECTOR V2;
   V1.x = V1.x - V2.x;
   V1.y = V1.y - V2.y;
   V1.z = V1.z - V2.z;
   V1.w = V1.w - V2.w;
```

## See also

[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type)