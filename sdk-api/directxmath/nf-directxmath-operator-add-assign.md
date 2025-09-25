# XMVECTOR::operator +=

## Description

Adds a floating point value to an **XMVECTOR** instance, and returns a reference to the updated instance.

The `operator +=` adds a specified floating point value to each component of the current instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type), returning a reference to the updated current instance.

**Note** This operator is only available under C++.

## Parameters

### `V1`

Reference to current instance of **XMVECTOR**.

### `V2`

**XMVECTOR** instance whose components are to be added to the component of *V1*.

## Return value

Reference to the updated current instance of **XMVECTOR**.

## Remarks

The following pseudocode demonstrates the operation of this operator:

```cpp
   XMVECTOR V;
   V1.x = V1.x + V2.x;
   V1.y = V1.y + V2.y;
   V1.z = V1.z + V2.z;
   V1.w = V1.w + V2.w;
```

## See also

[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type)