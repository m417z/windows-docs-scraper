# IDirectManipulationViewport::SetManualGesture

## Description

Sets which gestures are ignored by [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal).

## Parameters

### `configuration` [in]

One of the values from [DIRECTMANIPULATION_GESTURE_CONFIGURATION](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_gesture_configuration).

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use this method to specify which gestures the application processes on the UI thread. If a gesture is recognized, it will be passed to the application for processing and ignored by [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal).

#### Examples

The following example shows how zoom gestures can be ignored by [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) and handled by the application, which may have custom zoom behavior implementation.

```
HRESULT hr = pViewport->SetManualGesture(DIRECTMANIPULATION_GESTURE_PINCH_ZOOM);
```

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)