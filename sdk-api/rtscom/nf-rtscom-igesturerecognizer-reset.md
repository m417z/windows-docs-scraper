# IGestureRecognizer::Reset

## Description

Deletes past stroke information from the [GestureRecognizer Class](https://learn.microsoft.com/windows/desktop/tablet/gesturerecognizer-class) object.

## Return value

For a description of return values see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

Removes any past strokes from consideration for gestures. If Reset is called while the user is in the middle of writing a stroke, the [GestureRecognizer Class](https://learn.microsoft.com/windows/desktop/tablet/gesturerecognizer-class) object ignores that stroke.

## See also

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[GestureRecognizer Class](https://learn.microsoft.com/windows/desktop/tablet/gesturerecognizer-class)

[IGestureRecognizer](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-igesturerecognizer)

[IGestureRecognizer::Enabled Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-igesturerecognizer-get_enabled)