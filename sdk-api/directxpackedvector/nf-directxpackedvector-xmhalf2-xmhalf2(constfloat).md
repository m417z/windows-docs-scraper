# XMHALF2::XMHALF2(const float)

## Description

Initializes a new instance of [XMHALF2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf2) from a two element `float` array argument.

This constructor initializes a new instance of** XMHALF2** from a two element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Two element `float` array containing the values used to initialize the two components of a new instance of **XMHALF2**.

## Remarks

If the magnitude of one of the members of *pArray* cannot be represented by the **HALF** type, the corresponding member of the new instance of **XMHALF2** will be infinity for a 16-bit integer (+0x7FFF).

The following pseudocode demonstrates the operation of this constructor using the XNA Math *XMConvertFloatToHalf* function:

```cpp
XMHALF2 instance;

instance.x = XMConvertFloatToHalf(pArray[0]);
instance.y = XMConvertFloatToHalf(pArray[1]);
```

## See also

[XMHALF2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf2)

[XMHALF2 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmhalf2-ctor)