# operator *=(XMVECTOR&, float)

## Description

Multiplies an **XMVECTOR** instance by a floating point value and returns a reference to the updated instance.

The `operator *=` multiplies each component of the current instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by a specified floating point value, returning a reference to the updated current instance.

**Note** This operator is only available under C++.

## Parameters

### `V`

Reference to current instance of **XMVECTOR**.

### `S`

Floating point multiplicand.

## Return value

Reference to the updated current instance of **XMVECTOR**.

## Remarks

The following pseudocode demonstrates the operation of this operator:

```cpp
   XMVECTOR V;
   V.x = V.x * S;
   V.y = V.y * S;
   V.z = V.z * S;
   V.w = V.w * S;
```

## See also

[XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type)