# MI_Application_NewClass function

## Description

Creates an [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) from an
[MI_ClassDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_classdecl) structure. The resulting
[MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) structure must be closed by using the
[MI_Class_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_class_delete) function.

## Parameters

### `application` [in]

Handle returned from
[MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1).

### `classDecl` [in]

The [MI_ClassDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_classdecl) for the class to create.

### `namespaceName` [in, optional]

The optional namespace name.

### `serverName` [in, optional]

The optional server name.

### `classObject` [out]

The resultant [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) structure.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the
function return code. This can be one of the following codes.