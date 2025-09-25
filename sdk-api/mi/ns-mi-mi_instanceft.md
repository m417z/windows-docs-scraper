## Description

A support structure used in the [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance)
structure. Use the functions with the name prefix **MI_Instance_** to manipulate
these structures.

## Members

### `AddElement`

Adds a new property to a dynamic instance. See
[MI_Instance_AddElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_addelement).

### `ClearElement`

Clears the value of the named element (CIM property) and sets it to Null. See
[MI_Instance_ClearElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clearelement).

### `ClearElementAt`

Clears the value of the element (CIM property) at the specified index and sets it to Null. See
[MI_Instance_ClearElementAt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clearelementat).

### `Clone`

Creates a copy of the specified instance on the heap. See
[MI_Instance_Clone](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_clone).

### `Delete`

Deletes an instance that was created on the heap. See
[MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete).

### `Destruct`

Deletes an instance that was created on the stack. See
[MI_Instance_Destruct](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_destruct).

### `GetClass`

Gets the [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) associated with an instance. See
[MI_Instance_GetClass](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_getclass).

### `GetClassName`

Gets the class name of the specified instance. See
[MI_Instance_GetClassName](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_getclassname).

### `GetElement`

Gets the value of the named element (CIM property). See
[MI_Instance_GetElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_getelement).

### `GetElementAt`

Gets the value of the element (CIM property) at the specified index. See
[MI_Instance_GetElementAt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_getelementat).

### `GetElementCount`

Gets the number of elements in an instance. See
[MI_Instance_GetElementCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_getelementcount).

### `GetNameSpace`

Gets the namespace name of the specified instance. See
[MI_Instance_GetNameSpace](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_getnamespace).

### `GetServerName`

Gets the server name from the specified instance. See
[MI_Instance_GetServerName](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_getservername).

### `IsA`

Determines if the instance self is an instance of the class given by classDecl. See
[MI_Instance_IsA](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_isa).

### `SetElement`

Set the value of the property with the given name in the given instance. See
[MI_Instance_SetElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_setelement).

### `SetElementAt`

Set the value of the property at the given index of an instance. See
[MI_Instance_SetElementAt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_setelementat).

### `SetNameSpace`

Sets the namespace name of the specified instance. See
[MI_Instance_SetNameSpace](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_setnamespace).

### `SetServerName`

Sets the server name of the specified instance. See
[MI_Instance_SetServerName](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_setservername).