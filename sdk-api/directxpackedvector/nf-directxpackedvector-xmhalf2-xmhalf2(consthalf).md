# XMHALF2::XMHALF2(const HALF)

## Description

Initializes a new instance of [XMHALF2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf2) from a two element `HALF` array argument.

This constructor initializes a new instance of **XMHALF2** from a two element `HALF` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Two element `HALF` array containing the values used to initialize the two components of a new instance of **XMHALF2**.

## Remarks

The following pseudocode demonstrates the operation of this constructor:
```cpp
XMHALF2 instance;
instance.x = pArray[0];
instance.y = pArray[1];
```

## See also

[XMHALF2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf2)

[XMHALF2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmhalf2-ctor)