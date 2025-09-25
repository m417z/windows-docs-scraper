# SetWindowFeedbackSetting function

## Description

Sets the feedback configuration for a window.

## Parameters

### `hwnd` [in]

The window to configure feedback on.

### `feedback` [in]

One of the values from the [FEEDBACK_TYPE](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-feedback_type) enumeration.

### `dwFlags` [in]

Reserved. Must be 0.

### `size` [in]

The size, in bytes, of the configuration data. Must be sizeof(BOOL) or 0 if the feedback setting is being reset.

### `configuration` [in, optional]

The configuration data. Must be BOOL or NULL if the feedback setting is being reset.

## Return value

Returns TRUE if successful; otherwise, returns FALSE.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_feedback/functions)

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)