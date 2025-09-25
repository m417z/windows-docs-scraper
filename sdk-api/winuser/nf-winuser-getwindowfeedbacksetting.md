# GetWindowFeedbackSetting function

## Description

Retrieves the feedback configuration for a window.

## Parameters

### `hwnd` [in]

The window to check for feedback configuration.

### `feedback` [in]

One of the values from the [FEEDBACK_TYPE](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-feedback_type) enumeration.

### `dwFlags` [in]

Specify [GWFS_INCLUDE_ANCESTORS](https://learn.microsoft.com/previous-versions/windows/desktop/input_feedback/constants) to check the parent window chain until a value is found. The default is 0 and indicates that only the specified window will be checked.

### `pSize` [in, out]

The size of memory region that the *config* parameter points to.

The *pSize* parameter specifies the size of the configuration data for the feedback type in *feedback* and must be sizeof(BOOL).

### `config` [out, optional]

The configuration data.

The *config* parameter must point to a value of type BOOL.

## Return value

Returns TRUE if the specified feedback setting is configured on the specified window. Otherwise, it returns FALSE (and *config* won't be modified).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_feedback/functions)

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)