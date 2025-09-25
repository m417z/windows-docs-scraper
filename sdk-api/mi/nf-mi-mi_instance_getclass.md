# MI_Instance_GetClass function

## Description

Gets the [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) associated with an
instance.

## Parameters

### `self` [in]

A pointer to an instance whose [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) structure is
to be retrieved.

### `instanceClass`

Returned [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class). This
**MI_Class** wraps the
[MI_ClassDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_classdecl) field inside the
[MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) and does not retrieve anything from the
server. This returned class should be deleted via
[MI_Class_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_class_delete).

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies
the function return code. This can be one of the following codes.

## Remarks

Different types of classes exist. A dynamic instance has a very flat class declaration with no real
qualifiers. Certain
[flags](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/mi-flags) in to
session objects can also change the type of runtime type information (RTTI) that is returned, such that it has
none (types are all strings, flat structure, no qualifiers), basic (types of properties should be correct, but
they are flat-structured without qualifiers), standard (best effort at creating hierarchy, but overloaded
properties may not show original type in parent class), and full, which is an accurate class declaration.
Therefore, how an instance is created or retrieved will depend on the accuracy of the class declaration.

## See also

[MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class)

[MI_ClassDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_classdecl)

[MI_Class_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_class_delete)

[MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance)