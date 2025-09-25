# MI_Utilities_MapErrorToMiErrorCategory function

## Description

Maps an operating system specific error code to an error category.

## Parameters

### `errorType`

A null-terminated string representing an error type. Use one of these constants.

#### MI_RESULT_TYPE_MI

MI result type

#### MI_RESULT_TYPE_HRESULT

HRESULT (COM return type) result type

#### MI_RESULT_TYPE_WIN32

Win32 result type

### `error`

Error code to map.

## Return value

An [MI_ErrorCategory](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_errorcategory) structure that indicates the category of error.

## See also

[MI_ErrorCategory](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_errorcategory)