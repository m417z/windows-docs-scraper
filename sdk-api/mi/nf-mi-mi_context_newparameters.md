# MI_Context_NewParameters function

## Description

Creates a new instance of a method given a method declaration.

## Parameters

### `context` [in]

A pointer to the request context.

### `methodDecl` [in]

A pointer to the Method declaration used to initialize the instance.

### `instance`

A pointer to the returned instance.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

When you are finished using the instance, it must be deleted with the [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete) function.