# IManipulationProcessor::get_PivotRadius

## Description

The **PivotRadius** property is used to determine how much rotation is used in single finger manipulation.

This property is read/write.

## Parameters

## Remarks

**Note** The pivot radius must either be negative, 0, or a value greater than 1. Setting the pivot radius to a value between 0.0 and 1.0 will return **E_INVALIDARG**.

## See also

[IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor)

[PivotPointX](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-get_pivotpointx)

[PivotPointY](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-get_pivotpointy)

[Properties](https://learn.microsoft.com/windows/desktop/wintouch/mtproperties)

[Single Finger Rotation](https://learn.microsoft.com/windows/desktop/wintouch/single-finger-rotation)