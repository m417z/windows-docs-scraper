# InjectSyntheticPointerInput function

## Description

Simulates pointer input (pen or touch).

## Parameters

### `device`

A handle to the pointer injection device created by [CreateSyntheticPointerDevice](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createsyntheticpointerdevice).

### `pointerInfo` [in]

An array of [POINTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-pointer_type_info) structures represneting the injected pointers.

The type must match the *pointerType* parameter of the [CreateSyntheticPointerDevice](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createsyntheticpointerdevice) call that created the injection device.

The ptPixelLocation for each POINTER_TYPE_INFO is specified relative to top left of the virtual screen:

### `count` [in]

The number of contacts.

For [PT_TOUCH](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type) this value must be greater than 0 and less than or equal to [MAX_TOUCH_COUNT](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchinjection/constants).

For [PT_PEN](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type) this value must be 1.

## Return value

If this function succeeds, it returns TRUE.
Otherwise, it returns FALSE. To retrieve extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.