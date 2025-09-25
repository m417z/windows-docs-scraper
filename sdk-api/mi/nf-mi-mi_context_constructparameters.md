# MI_Context_ConstructParameters function

## Description

A provider calls this function to initialize a parameter's instance.

## Parameters

### `context` [in]

A pointer to the request context.

### `methodDecl` [in]

A pointer to the method declaration used to initialize the instance.

### `instance` [out]

A pointer to the returned instance.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.

## Remarks

You are responsible for reserving the memory for the instance (either on the stack or the heap). When you have finished using the instance, delete it by calling the [MI_Instance_Destruct](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_destruct) function.