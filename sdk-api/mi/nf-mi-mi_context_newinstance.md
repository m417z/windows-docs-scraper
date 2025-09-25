# MI_Context_NewInstance function

## Description

Creates a new instance of a class given a class declaration.

## Parameters

### `context` [in]

A pointer to the request context.

### `classDecl` [in]

A pointer to the class declaration used to initialize the instance. The runtime type information (RTTI) is generated for the class and should be named for the class, followed by an "_rtti" suffix.

### `instance`

A pointer to the returned instance. There is also a generated function named for the class, followed by a "_Delete" suffix.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

When you are finished using the instance, it must be deleted via the [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete) function.