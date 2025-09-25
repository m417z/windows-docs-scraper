# AppPolicyGetWindowingModel function

## Description

Retrieves a value indicating whether a process uses a CoreWindow-based, or a HWND-based, windowing model. You can use the value to decide how to register for window state change notifications (size changed, visibility changed, etc.).

## Parameters

### `processToken` [in]

A handle that identifies the access token for a process.

### `policy` [out]

A pointer to a variable of the [AppPolicyWindowingModel](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-apppolicywindowingmodel) enumerated type. When the function returns successfully, the variable contains an enumerated constant value indicating the windowing model of the identified process.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If no known windowing model policy was found for the process token, the function raises a STATUS_ASSERTION_FAILURE exception and returns ERROR_NOT_FOUND.

If either processToken or policy are null, the function returns ERROR_INVALID_PARAMETER.