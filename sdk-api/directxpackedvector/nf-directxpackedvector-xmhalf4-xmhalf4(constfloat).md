# XMHALF4::XMHALF4(const float)

## Description

Initializes a new instance of [XMHALF4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf4) from a four element `float` array argument.

This constructor initializes a new instance of **XMHALF4** from a four element `float` array argument.

**Note** This constructor is only available under C++.

## Parameters

### `pArray`

Four element `float` array containing the values used to initialize the four components of a new instance of **XMHALF4**.

## Remarks

If the magnitude of one of the members of *pArray* cannot be represented by the **HALF** type, the corresponding member of the new instance of **XMHALF4** will be infinity for a 16-bit integer (+0x7FFF).

The following pseudocode demonstrates the operation of this constructor using the XNA Math *XMConvertFloatToHalf* function:

```cpp
XMHALF4 instance;

instance.x = XMConvertFloatToHalf(pArray[0]);
instance.y = XMConvertFloatToHalf(pArray[1]);
instance.z = XMConvertFloatToHalf(pArray[2]);
instance.w = XMConvertFloatToHalf(pArray[3]);
```

## See also

[XMHALF4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmhalf4)

[XMHALF4 Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmhalf4-ctor)