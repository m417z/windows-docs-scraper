# IGestureRecognizer::get_MaxStrokeCount

## Description

Gets or sets the maximum number of strokes allowed per gesture recognition.

This property is read/write.

## Parameters

## Remarks

Valid values are 1 and 2. When the **MaxStrokeCount** property is 2, gesture recognizer looks back to the most recent two strokes and attempts to recognize them as gestures. This may result in multiple recognition calls and multiple gesture events flowing through the system.

## See also

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[GestureRecognizer Class](https://learn.microsoft.com/windows/desktop/tablet/gesturerecognizer-class)

[IGestureRecognizer](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-igesturerecognizer)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)