# CreateSyntheticPointerDevice function

## Description

Configures the pointer injection device for the calling application, and initializes the maximum number of simultaneous pointers that the app can inject.

## Parameters

### `pointerType` [in]

The pointer injection device type. Must be either [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type) or **PT_PEN**.

### `maxCount` [in]

The maximum number of contacts.

For [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type) this value must be greater than 0 and less than or equal to [MAX_TOUCH_COUNT](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchinjection/constants).

For [PT_PEN](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type) this value must be 1.

### `mode` [in]

The contact visualization mode.

## Return value

If the function succeeds, the return value is a handle to the pointer injection device. Otherwise, it returns null. To retrieve extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.