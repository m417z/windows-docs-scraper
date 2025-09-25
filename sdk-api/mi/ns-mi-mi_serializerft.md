## Description

A support structure used in the
[MI_ClientFT_V1](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_clientft_v1) structure. Use the functions with the
name prefix "MI_Serializer_" to manipulate these structures.

## Members

### `Close`

Closes a serializer object and frees any internal memory associated with it. See
[MI_Serializer_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_serializer_close).

### `SerializeClass`

Serializes an [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) into a buffer in the format
specified when it was created. See
[MI_Serializer_SerializeClass](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_serializer_serializeclass).

### `SerializeInstance`

Serializes an [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) into a buffer in the
format specified when the serializer was created. See
[MI_Serializer_SerializeInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_serializer_serializeinstance).