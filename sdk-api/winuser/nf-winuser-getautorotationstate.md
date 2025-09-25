# GetAutoRotationState function

## Description

Retrieves an [AR_STATE](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-ar_state) value containing the state of screen auto-rotation for the system, for example whether auto-rotation is supported, and whether it is enabled by the user. **GetAutoRotationState** provides a robust and diverse way of querying for auto-rotation state, and more. For example, if you want your app to behave differently when multiple monitors are attached then you can determine that from the **AR_STATE** returned.

## Parameters

### `pState` [out]

Pointer to a location in memory that will receive the current state of auto-rotation for the system.

## Return value

TRUE if the method succeeds, otherwise FALSE.

See [GetDisplayAutoRotationPreferences](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdisplayautorotationpreferences) for an example of using this function.