# ID2D1Properties::GetPropertyCount

## Description

Gets the number of top-level properties.

## Return value

Type: **UINT32**

This method returns the number of custom (non-system) properties that can be accessed by the object.

## Remarks

This method returns the number of custom properties on the [ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties) interface. System properties and sub-properties are part of a closed set, and are enumerable by iterating over this closed set.

## See also

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)