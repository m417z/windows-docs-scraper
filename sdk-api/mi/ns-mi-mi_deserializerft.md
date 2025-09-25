## Description

A support structure used in the
[MI_ClientFT_V1](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_clientft_v1) structure. Use the functions with the
name prefix "MI_Deserializer_" to manipulate these structures.

## Members

### `Class_GetClassName`

Gets the class name from a serialized class buffer. See
[MI_Deserializer_Class_GetClassName](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_deserializer_class_getclassname).

### `Class_GetParentClassName`

Gets the parent class name from a serialized class buffer. See
[MI_Deserializer_Class_GetParentClassName](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_deserializer_class_getparentclassname).

### `Close`

Deletes the deserializer object and its associated memory. See
[MI_Deserializer_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_deserializer_close).

### `DeserializeClass`

Deserializes a serialized buffer into an [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class)
object. See
[MI_Deserializer_DeserializeClass](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_deserializer_deserializeclass).

### `DeserializeInstance`

Deserializes a serialized buffer into a
[MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) object. See
[MI_Deserializer_DeserializeInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_deserializer_deserializeinstance).

### `Instance_GetClassName`

Gets the class name of the specified instance. See
[MI_Instance_GetClassName](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_getclassname).

## See also

[MI_Deserializer_ClassObjectNeeded](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nc-mi-mi_deserializer_classobjectneeded)