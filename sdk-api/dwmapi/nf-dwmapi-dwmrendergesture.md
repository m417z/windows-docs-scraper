# DwmRenderGesture function

## Description

Notifies Desktop Window Manager (DWM) that a touch contact has been recognized as a gesture, and that DWM should draw feedback for that gesture.

## Parameters

### `gt` [in]

The type of gesture, specified as one of the [GESTURE_TYPE](https://learn.microsoft.com/windows/desktop/api/dwmapi/ne-dwmapi-gesture_type) values.

### `cContacts` [in]

The number of contact points.

### `pdwPointerID` [in]

The pointer ID.

### `pPoints` [in]

The points.