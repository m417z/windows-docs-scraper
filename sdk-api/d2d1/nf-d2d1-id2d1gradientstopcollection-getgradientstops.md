# ID2D1GradientStopCollection::GetGradientStops

## Description

Copies the gradient stops from the collection into an array of [D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_gradient_stop) structures.

## Parameters

### `gradientStops` [out]

Type: **[D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_gradient_stop)***

A pointer to a one-dimensional array of [D2D1_GRADIENT_STOP](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_gradient_stop) structures. When this method returns, the array contains copies of the collection's gradient stops. You must allocate the memory for this array.

### `gradientStopsCount`

Type: **UINT**

A value indicating the number of gradient stops to copy. If the value is less than the number of gradient stops in the collection, the remaining gradient stops are omitted. If the value is larger than the number of gradient stops in the collection, the extra gradient stops are set to **NULL**. To obtain the number of gradient stops in the collection, use the [GetGradientStopCount](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1gradientstopcollection-getgradientstopcount) method.

## Remarks

Gradient stops are copied in order of position, starting with the gradient stop with the smallest position value and progressing to the gradient stop with the largest position value.

## See also

[ID2D1GradientStopCollection](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1gradientstopcollection)