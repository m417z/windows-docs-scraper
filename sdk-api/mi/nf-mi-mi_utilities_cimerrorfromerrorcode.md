# MI_Utilities_CimErrorFromErrorCode function

## Description

Maps an operating-system specific error code to a CIM error instance.

## Parameters

### `error`

Error code to translate.

### `errorType` [in]

One of the following error types.

#### MI_RESULT_TYPE_MI

**MI** result type

#### MI_RESULT_TYPE_HRESULT

**HRESULT** (COM return type) result type

#### MI_RESULT_TYPE_WIN32

**Win32** result type

### `errorMessage` [in]

Error message to encode in the CIM error instance.

### `cimError`

Returned CIM error instance. This must be deleted by using the [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete) function.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.