# IGestureRecognizer::EnableGestures

## Description

Sets a value that indicates to which application gestures the [GestureRecognizer Class](https://learn.microsoft.com/windows/desktop/tablet/gesturerecognizer-class) object responds.

## Parameters

### `cGestures` [in]

 The size of the array to which the *pGestures* parameter points. Valid values are between 0 and 64, inclusive.

### `pGestures` [in]

An array of the [InkApplicationGesture Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture) values that indicates to which application gestures the [GestureRecognizer Class](https://learn.microsoft.com/windows/desktop/tablet/gesturerecognizer-class) object responds.

## Return value

For a description of return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

You cannot enable **AllGestures** in conjunction with any other gestures.

## See also

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[GestureRecognizer Class](https://learn.microsoft.com/windows/desktop/tablet/gesturerecognizer-class)

[IGestureRecognizer](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-igesturerecognizer)

[IGestureRecognizer::Enabled Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-igesturerecognizer-get_enabled)