# IInkGesture::GetHotPoint

## Description

Gets the hot point of the gesture, in ink space coordinates.

## Parameters

### `X` [in, out]

The X-value of the hot point, in ink space coordinates.

### `Y` [in, out]

The Y-value of the hot point, in ink space coordinates.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Error information is provided. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred while processing. |

## Remarks

The hot point is the one distinguishing point of a gesture. It is usually the point of the angle in a gesture or the point at which the gesture is intended to occur in relation to the content around it. If there is no discernable hot point for a known gesture, the starting point of the gesture is the hot point.

For example, the hot point of the [Check](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture) gesture is the point of the angle, and the hot point of the **Curlicue** gesture is the start of the stroke that is the gesture.

For more information about how a hot point is used, see [Using Gestures](https://learn.microsoft.com/windows/desktop/tablet/using-gestures).

## See also

[IInkGesture Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkgesture)

[Using Gestures](https://learn.microsoft.com/windows/desktop/tablet/using-gestures)