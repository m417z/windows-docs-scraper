# XMHALF4::XMHALF4(const HALF)

## Description

Initializes a new instance of [XMHALF4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf4) from a four element `HALF` array argument.

This constructor initializes a new instance of **XMHALF4** from a from a four element `XMHALF4` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element **HALF** array containing the values used to initialize the four components of a new instance of **XMHALF4**.

## Remarks

The following pseudocode demonstrates the operation of this constructor:

```cpp
XMHALF4 instance;
instance.x = pArray[0];
instance.y = pArray[1];
instance.z = pArray[2];
instance.w = pArray[3];
```

## See also

[XMHALF4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf4)

[XMHALF4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmhalf4-ctor)