# InitializeTouchInjection function

## Description

Configures the touch injection context for the calling application and initializes the maximum number of simultaneous contacts that the app can inject.

**Note** **InitializeTouchInjection** must precede any call to [InjectTouchInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-injecttouchinput).

## Parameters

### `maxCount` [in]

The maximum number of touch contacts.

The *maxCount* parameter must be greater than 0 and less than or equal to MAX_TOUCH_COUNT (256) as defined in winuser.h.

### `dwMode` [in]

The contact visualization mode.

The *dwMode* parameter must be [TOUCH_FEEDBACK_DEFAULT](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchinjection/constants), **TOUCH_FEEDBACK_INDIRECT**, or **TOUCH_FEEDBACK_NONE**.

## Return value

If the function succeeds, the return value is TRUE.

If the function fails, the return value is FALSE. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If [TOUCH_FEEDBACK_DEFAULT](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchinjection/constants) is set, the injected touch feedback may get suppressed by the end-user settings in the **Pen and Touch** control panel.

If [TOUCH_FEEDBACK_INDIRECT](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchinjection/constants) is set, the injected touch feedback overrides the end-user settings in the **Pen and Touch** control panel.

If [TOUCH_FEEDBACK_INDIRECT](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchinjection/constants) or **TOUCH_FEEDBACK_NONE** are set, touch feedback provided by applications and controls may not be affected.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchinjection/functions)